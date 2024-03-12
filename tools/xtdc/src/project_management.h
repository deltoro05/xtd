#pragma once
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <xtd/argument_exception.h>
#include <xtd/bit_converter.h>
#include <xtd/environment.h>
#include <xtd/action.h>
#include <xtd/diagnostics/process.h>
#include <xtd/io/file.h>
#include <xtd/io/path.h>

#include "project_language.h"
#include "project_sdk.h"
#include "project_type.h"

namespace xtdc_command {
  class project_management {
    class change_current_directory {
    public:
      change_current_directory(const std::filesystem::path& current_directory) {
        if (!xtd::io::file::exists(current_directory.string())) std::filesystem::create_directories(std::filesystem::path(current_directory));
        xtd::environment::current_directory(current_directory.string());
      }
      ~change_current_directory() {xtd::environment::current_directory(previous_current_directoy_);}
    private:
      xtd::ustring previous_current_directoy_ = xtd::environment::current_directory();
    };

  public:
    explicit project_management(const std::filesystem::path& output) : path_(output) {}

    static std::vector<project_sdk> get_valid_sdks(project_type type) {
      switch (type) {
        case project_type::unknown: return {project_sdk::none};
        case project_type::blank_solution: return {project_sdk::xtd};
        case project_type::console: return {project_sdk::none, project_sdk::xtd};
        case project_type::gui: return {project_sdk::cocoa, project_sdk::fltk, project_sdk::gtk2, project_sdk::gtk3, project_sdk::gtkmm, project_sdk::qt5, project_sdk::win32, project_sdk::winforms, project_sdk::wpf, project_sdk::wxwidgets, project_sdk::xtd};
        case project_type::shared_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::static_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::unit_test_application: return {project_sdk::catch2, project_sdk::gtest, project_sdk::xtd};
      }
      throw xtd::argument_exception("type is not project_type valid value", current_stack_frame_);
    }
    
    static std::vector<project_language> get_valid_languages(project_sdk sdk) {
      switch (sdk) {
        case project_sdk::none: return {project_language::cpp, project_language::c, project_language::objectivec, project_language::csharp};
        case project_sdk::catch2: return {project_language::c, project_language::cpp};
        case project_sdk::cocoa: return {project_language::objectivec};
        case project_sdk::fltk: return {project_language::cpp};
        case project_sdk::gtest: return {project_language::c, project_language::cpp};
        case project_sdk::gtk2: return {project_language::c, project_language::cpp};
        case project_sdk::gtk3: return {project_language::c, project_language::cpp};
        case project_sdk::gtkmm: return {project_language::cpp};
        case project_sdk::qt5: return {project_language::cpp};
        case project_sdk::win32: return {project_language::c, project_language::cpp};
        case project_sdk::winforms: return {project_language::csharp};
        case project_sdk::wpf: return {project_language::csharp};
        case project_sdk::wxwidgets: return {project_language::cpp};
        case project_sdk::xtd: return {project_language::cpp};
      }
      throw xtd::argument_exception("sdk is not project_sdk valid value", current_stack_frame_);
    }
    
    xtd::ustring create(const xtd::ustring& name, project_type type, project_sdk sdk, project_language language) const {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) return "The sdk param not valid with type param! Create project aborted.";
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) return "The language param not valid with sdk param! Create project aborted.";
      if (is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} already exists and not empty! Create project aborted.", path_);
      if (sdk == project_sdk::qt5 && xtd::environment::get_environment_variable("CMAKE_PREFIX_PATH").empty()) return "Set your CMAKE_PREFIX_PATH environment variable to the Qt 5 installation prefix! Create project aborted.";
      std::filesystem::create_directories(std::filesystem::path {path_}/"build");
      create_doxygen_txt(name);
      create_readme_md(name);
      std::map<project_type, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_type::blank_solution, {*this, &project_management::create_blank_solution}}, {project_type::console, {*this, &project_management::create_console}}, {project_type::gui, {*this, &project_management::create_gui}}, {project_type::shared_library, {*this, &project_management::create_shared_library}}, {project_type::static_library, {*this, &project_management::create_static_library}}, {project_type::unit_test_application, {*this, &project_management::create_unit_test_application}}}[type](name, sdk, language, true);
      generate(name);
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Create project aborted.";
      return xtd::ustring::format("Project {} created", path_);
    }

    xtd::ustring add(const xtd::ustring& name, project_type type, project_sdk sdk, project_language language) const {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) return "The sdk param not valid with type param! Add project aborted.";
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) return "The language param not valid with sdk param! Add project aborted.";
      if (is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} already exists and not empty! Add project aborted.", path_);
      if (sdk == project_sdk::qt5 && xtd::environment::get_environment_variable("CMAKE_PREFIX_PATH").empty()) return "Set your CMAKE_PREFIX_PATH environment variable to the Qt 5 installation prefix! Add project aborted.";
      if (!std::filesystem::exists(path_.parent_path()/"CMakeLists.txt")) return xtd::ustring::format("Parent directory \"{}\", is not a known project! Add project aborted.", path_.parent_path().string());
      auto lines  = xtd::io::file::read_all_lines((path_.parent_path()/"CMakeLists.txt").string());
      if (std::find_if(lines.begin(), lines.end(), [](const xtd::ustring& value) {return value.contains("find_package(xtd");}) != lines.end() && sdk != project_sdk::xtd) return "The sdk param not valid with current project sdk! Add project aborted.";
      if (std::find_if(lines.begin(), lines.end(), [](const xtd::ustring& value) {return value.contains("find_package(xtd");}) == lines.end() && sdk == project_sdk::xtd) return "The sdk param not valid with current project sdk! Add project aborted.";
     
      lines.push_back(xtd::ustring::format("{}({})", std::find_if(lines.begin(), lines.end(), [](const xtd::ustring& value) {return value.contains("find_package(xtd");}) != lines.end() ? "add_projects" : "add_subdirectory", path_.stem().string()));
      std::map<project_type, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_type::blank_solution, {*this, &project_management::create_blank_solution}}, {project_type::console, {*this, &project_management::create_console}}, {project_type::gui, {*this, &project_management::create_gui}}, {project_type::shared_library, {*this, &project_management::create_shared_library}}, {project_type::static_library, {*this, &project_management::create_static_library}}, {project_type::unit_test_application, {*this, &project_management::create_unit_test_application}}}[type](name, sdk, language, false);
      auto project_path = path_;
      path_ = path_.parent_path();
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
      generate(name);
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Add project aborted.";
      return xtd::ustring::format("Project {} added", project_path);
    }
    
    xtd::ustring build(const xtd::ustring& target, bool clean_first, bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Build project aborted.", path_);
      if (clean_first) clean(release);
      else generate();
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Build project aborted.";
      change_current_directory current_directory {xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path()};
      if (xtd::environment::os_version().is_windows_platform() || xtd::environment::os_version().is_macos_platform())
        launch_and_wait_process("cmake", xtd::ustring::format("--build {} --parallel {} --config {}{}{}", build_path(), xtd::environment::processor_count(), (release ? "Release" : "Debug"), target.empty() ? "" : xtd::ustring::format(" --target {}", target), clean_first ? " --clean-first {}" : ""));
      else
        launch_and_wait_process("cmake", xtd::ustring::format("--build {}{}", build_path()/(release ? "Release" : "Debug"), target.empty() ? "" : xtd::ustring::format(" --target {}", target), clean_first ? " --clean-first {}" : ""));
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Build project aborted.";
      return xtd::ustring::format("Project {} builded", path_);
    }

    xtd::ustring clean(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Clean project aborted.", path_);
      std::filesystem::remove_all(xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path());
      generate();
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Clean project aborted.";
      return xtd::ustring::format("Project {} cleaned", path_);
    }
    
    xtd::ustring install(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Install project aborted.", path_);
      change_current_directory current_directory {xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path()};
      build("install", false, release);
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Install project aborted.";
      return xtd::ustring::format("Project {} installed", path_);
    }
    
    xtd::ustring open(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Open project aborted.", path_);
      change_current_directory current_directory {xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path()};
      generate();
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Open project aborted.";
      if (xtd::environment::os_version().is_windows_platform()) launch_and_wait_process(xtd::ustring::format("{}.sln", (build_path()/get_name().c_str()).string()), true);
      else if (xtd::environment::os_version().is_macos_platform()) launch_and_wait_process(xtd::ustring::format("{}.xcodeproj", (build_path()/get_name().c_str()).string()), true);
      else launch_and_wait_process(xtd::ustring::format("{}.cbp", (build_path()/(release ? "Release" : "Debug")/get_name().c_str()).string()), true);
      return xtd::ustring::format("Project {} opened", get_name());
    }

    xtd::ustring update(const xtd::ustring& target) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Update project aborted.", path_);
      change_current_directory current_directory {build_path()};
      generate(target);
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Update project aborted.";
      return "";
    }

    xtd::ustring run(const xtd::ustring& target, bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Run project aborted.", path_);
      build(target, false, release);
      change_current_directory current_directory {xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path()};
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Run project aborted.";
      auto target_path = target.empty() ? get_first_target_path(release) : get_target_path(target, release);
      if (target_path.empty()) return "The target does not exist! Run project aborted.";
      
      xtd::diagnostics::process process;
      process.start_info(xtd::diagnostics::process_start_info(target_path));
      process.start_info().use_shell_execute(is_gui(std::filesystem::path(target_path.c_str())));
      process.start();
      return "";
    }

    std::vector<xtd::ustring>& targets() const {
      static std::vector<xtd::ustring> targets;
      if (targets.size() == 0)
        for (const auto& line : get_system_information())
          if (line.index_of("_BINARY_DIR:STATIC=") != xtd::ustring::npos)
            targets.push_back(line.substring(0, line.index_of("_BINARY_DIR:STATIC=")));
      return targets;
    }

    xtd::ustring test(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Test project aborted.", path_);
      change_current_directory current_directory {xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path()};
      build("", false, release);
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Test project aborted.";
      launch_and_wait_process("ctest", xtd::ustring::format("--output-on-failure --build-config {}", release ? "release" : "debug"));
      return xtd::ustring::format("Project {} tested", path_);
    }
    
    xtd::ustring uninstall(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Uninstall project aborted.", path_);
      if (!std::filesystem::exists((xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path())/"install_manifest.txt")) return xtd::ustring::format("File {} does not exists! Uninstall project aborted.", ((xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path())/"install_manifest.txt").string());
      change_current_directory current_directory {xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path()};
      
      std::filesystem::path app_path;
      for (auto file : xtd::io::file::read_all_lines(((xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path())/"install_manifest.txt").string())) {
        if (std::filesystem::exists(std::filesystem::path(file.c_str()))) {
          if (xtd::environment::os_version().is_macos_platform() && file.contains("Contents/MacOS")) app_path = file.remove(file.index_of("Contents/MacOS")).c_str();
          std::filesystem::remove(std::filesystem::path(file.c_str()));
        }
      }
      
      std::filesystem::remove((xtd::environment::os_version().is_linux_platform() ? (build_path()/(release ? "Release" : "Debug")) : build_path())/"install_manifest.txt");
      if (!app_path.empty()) std::filesystem::remove_all(app_path);
      return xtd::ustring::format("Project {} uninstalled", path_);
    }

  private:
#if defined(__XTD_RESOURCES_PATH__)
    static std::filesystem::path get_base_path() noexcept {return std::filesystem::path(__XTD_RESOURCES_PATH__);}
#else
    static xtd::ustring get_base_path() noexcept {return std::filesystem::path;}
#endif
    
    xtd::ustring& get_name() const {
      static xtd::ustring name;
      if (name.empty()) {
        for (const auto& line : get_system_information()) {
          if (line.starts_with( "CMAKE_PROJECT_NAME:STATIC=")) {
            name = line.replace("CMAKE_PROJECT_NAME:STATIC=", "");
            break;
          }
        }
      }
      if (name.empty()) name = path_.filename().string();
      return name;
    }
    
    xtd::ustring get_target_path(const xtd::ustring& target, bool release) const {
      for (const auto& line : get_system_information())
        if (line.starts_with(xtd::ustring::format("{}_BINARY_DIR:STATIC=", target)))
          return make_platform_target_path({line.replace(xtd::ustring::format("{}_BINARY_DIR:STATIC=", target), "").c_str()}, target, release);
      return (build_path()/(release ? "Release" : "Debug")/target.c_str()/target.c_str()).string();
    }
    
    xtd::ustring get_first_target_path(bool release) const {
      for (const auto& line : get_system_information())
        if (line.index_of("_BINARY_DIR:STATIC=") != xtd::ustring::npos)
          return make_platform_target_path({line.replace(xtd::ustring::format("{}_BINARY_DIR:STATIC=", line.substring(0, line.index_of("_BINARY_DIR:STATIC="))), "").c_str()}, line.substring(0, line.index_of("_BINARY_DIR:STATIC=")), release);
      if (xtd::environment::os_version().is_windows_platform()) return (build_path() / path_.filename() / (release ? "Release" : "Debug") / path_.filename()).string();
      return (build_path()/(release ? "Release" : "Debug")/path_.filename()/path_.filename()).string();
    }
    
    xtd::ustring make_platform_target_path(const std::filesystem::path& path, const xtd::ustring& target, bool release) const {
      if (xtd::environment::os_version().is_windows_platform() && std::filesystem::exists(path/(release ? "Release" : "Debug")/xtd::ustring::format("{}.exe", target).c_str()))
        return (path/(release ? "Release" : "Debug")/xtd::ustring::format("{}.exe", target).c_str()).string();
      else if (xtd::environment::os_version().is_macos_platform() && std::filesystem::exists(path/(release ? "Release" : "Debug")/xtd::ustring::format("{}.app", target).c_str()))
        return (path/(release ? "Release" : "Debug")/xtd::ustring::format("{}.app", target).c_str()).string();
      else if (xtd::environment::os_version().is_macos_platform() && std::filesystem::exists(path/(release ? "Release" : "Debug")/target.c_str()))
        return (path/(release ? "Release" : "Debug")/target.c_str()).string();
      else if (xtd::environment::os_version().is_linux_platform() && std::filesystem::exists(path/target.c_str()))
        return (path/target.c_str()).string();
      return "";
    }
    
    bool is_windows_gui_app(const std::filesystem::path& path) const {
      if (!std::filesystem::exists(path)) return false;
      auto bytes = xtd::io::file::read_all_bytes(path.string());
      // read PE Format : https://docs.microsoft.com/en-us/windows/win32/debug/pe-format
      if (bytes[0] != 'M' || bytes[1] != 'Z') return false;
      return xtd::bit_converter::to_uint16(bytes, xtd::bit_converter::to_uint16(bytes, 0x3C) + 92) == 2;
    }
    
    bool is_linux_gui_app(const std::filesystem::path& path) const {
      if (!std::filesystem::exists(path)) return false;
      auto lines = xtd::io::file::read_all_lines((std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::home).c_str())/".local"/"share"/"applications"/xtd::ustring::format("{}.desktop", path.filename()).c_str()).string());
      for (auto line : lines)
        if (line.to_lower() == "terminael=false") return true;
      return false;
    }
    
    bool is_macos_gui_app(const std::filesystem::path& path) const {
      return std::filesystem::path(path).has_extension() && std::filesystem::path(path.c_str()).extension().string() == ".app";
    }
    
    bool is_gui(const std::filesystem::path& path) const {
      if (xtd::environment::os_version().is_windows_platform()) return is_windows_gui_app(path);
      if (xtd::environment::os_version().is_macos_platform()) return is_macos_gui_app(path);
      return is_linux_gui_app(path);
    }
    
    std::vector<xtd::ustring>& get_system_information() const {
      static std::vector<xtd::ustring> system_information;
      if (system_information.size() == 0) {
        if (!std::filesystem::exists(build_path()/"xtd_si.txt")) {
          change_current_directory current_directory {build_path().string()};
          launch_and_wait_process("cmake", xtd::ustring::format("--system-information xtd_si.txt"));
        }
        system_information = xtd::io::file::read_all_lines((build_path()/"xtd_si.txt").string());
      }
      return system_information;
    }
    
    std::filesystem::path build_path() const {return path_/"build";}
    std::filesystem::path working_dir() const {return path_/"build";}
    int32_t last_exit_code() const {return last_exit_code_;}

    void create_blank_solution(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) {
      std::map<project_sdk, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_sdk::none, {*this, &project_management::create_none_blank_solution}}, {project_sdk::xtd, {*this, &project_management::create_xtd_blank_solution}}}[sdk](name, sdk, language, create_solution);
    }

    void create_none_blank_solution(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) {
      create_none_blank_solution_cmakelists_txt(name);
    }

    void create_none_blank_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "",
        "# Install",
        "install_package()",
        "",
        "# Projects"
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }

    void create_xtd_blank_solution(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) {
      create_xtd_blank_solution_cmakelists_txt(name);
    }

    void create_xtd_blank_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "",
        "# Install",
        "install_package()",
        "",
        "# Projects"
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }

    void create_console(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      if (sdk == project_sdk::xtd)
        create_xtd_console(name, sdk, language, create_solution);
      else
        std::map<project_language, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_language::c, {*this, &project_management::create_c_console}}, {project_language::cpp, {*this, &project_management::create_cpp_console}}, {project_language::csharp, {*this, &project_management::create_csharp_console}}, {project_language::objectivec, {*this, &project_management::create_objectivec_console}}}[language](name, sdk, language, create_solution);
    }

    void create_c_console(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_c_console_solution_cmakelists_txt(name);
      create_c_console_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_c_console_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_c_console_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_c_console_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/program.c",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION bin CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION bin CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION bin)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }

    void create_c_console_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <stdio.h>",
        "",
        "/* The main entry point for the application. */",
        "int main(int argc, char* argv[]) {",
        "  printf(\"Hello, World!\\n\");",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"program.c").string(), lines);
    }

    void create_cpp_console(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_cpp_console_solution_cmakelists_txt(name);
      create_cpp_console_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_cpp_console_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_cpp_console_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_cpp_console_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_cpp_console_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <iostream>",
        "",
        "using namespace std;",
        "",
        "// The main entry point for the application.",
        "int main(int argc, char* argv[]) {",
        "  cout << \"Hello, World!\" << endl;",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"program.cpp").string(), lines);
    }

    void create_csharp_console(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_csharp_console_solution_cmakelists_txt(name);
      create_csharp_console_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_csharp_console_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_csharp_console_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_csharp_console_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        "  src/Program.cs",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_csharp_console_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Program class.",
        "using System;",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        "  class Program {",
        "    /// @brief The main entry point for the application.",
        "    static void Main(string[] args) {",
        "      Console.WriteLine(\"Hello, World!\");",
        "    }",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.cs").string(), lines);
    }

    void create_objectivec_console(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_objectivec_console_solution_cmakelists_txt(name);
      create_objectivec_console_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_objectivec_console_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_objectivec_console_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_objectivec_console_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Program.m",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_objectivec_console_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#import <Foundation/Foundation.h>",
        "",
        "// The main entry point for the application.",
        "int main(int argc, const char * argv[]) {",
        "  @autoreleasepool {",
        "    NSLog(@\"Hello, World!\");",
        "  }",
        "  return 0;",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.m").string(), lines);
    }

    void create_xtd_console(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"properties" : path_/"properties");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_xtd_console_solution_cmakelists_txt(name);
      create_xtd_console_application_properties(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_console_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_console_include(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_console_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_xtd_console_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_console_application_properties(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_name(\"{}\")", name),
        xtd::ustring::format("target_startup(\"{}::program\" src/program.h)", name),
      };
      
      xtd::io::file::write_all_lines((path/"properties"/"target_properties.cmake").string(), lines);
    }

    void create_xtd_console_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/program.h",
        "  src/program.cpp",
        ")",
        "target_type(CONSOLE_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_console_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains program class.",
        "#pragma once",
        "#include <xtd/ustring.h>",
        "#include <vector>",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        "  class program {",
        "  public:",
        "    /// @brief The main entry point for the application.",
        "    static void main(const std::vector<xtd::ustring>& args);",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"program.h").string(), lines);
    }
    
    void create_xtd_console_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"program.h\"",
        "#include <xtd/console.h>",
        "",
        "using namespace std;",
        "using namespace xtd;",
        xtd::ustring::format("using namespace {};", name),
        "",
        "void program::main(const vector<ustring>& args) {",
        "  console::write_line(\"Hello, World!\");",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"program.cpp").string(), lines);
    }

    void create_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::map<project_sdk, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_sdk::cocoa, {*this, &project_management::create_cocoa_gui}}, {project_sdk::fltk, {*this, &project_management::create_fltk_gui}}, {project_sdk::gtk2, {*this, &project_management::create_gtk2_gui}}, {project_sdk::gtk3, {*this, &project_management::create_gtk3_gui}}, {project_sdk::gtkmm, {*this, &project_management::create_gtkmm_gui}}, {project_sdk::qt5, {*this, &project_management::create_qt5_gui}}, {project_sdk::win32, {*this, &project_management::create_win32_gui}}, {project_sdk::winforms, {*this, &project_management::create_winforms_gui}}, {project_sdk::wpf, {*this, &project_management::create_wpf_gui}}, {project_sdk::wxwidgets, {*this, &project_management::create_wxwidgets_gui}}, {project_sdk::xtd, {*this, &project_management::create_xtd_gui}}}[sdk](name, sdk, language, create_solution);
    }
    
    void create_cocoa_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_cocoa_gui_solution_cmakelists_txt(name);
      create_cocoa_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_cocoa_gui_include(name, create_solution ? path_/name.c_str() : path_);
      create_cocoa_gui_source(name, create_solution ? path_/name.c_str() : path_);
      create_cocoa_gui_main(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_cocoa_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_cocoa_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Window1.h",
        "  src/Window1.m",
        "  src/Program.m",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa\")",
        "set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})",
        xtd::ustring::format("set(MACOSX_BUNDLE_COPYRIGHT \"Copyright © {:L}\")", std::chrono::system_clock::now()),
        xtd::ustring::format("set(MACOSX_BUNDLE_INFO_STRING \"{} application\")", name),
        xtd::ustring::format("set(MACOSX_BUNDLE_GUI_IDENTIFIER \"org.Company.{}\")", name),
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_cocoa_gui_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#import <Cocoa/Cocoa.h>",
        "",
        "/// @brief Represents the main NSWindow",
        "@interface Window1 : NSWindow {",
        "}",
        " /// @brief Initializes a new instance of the Window1 class.",
        "- (instancetype)init;",
        "- (BOOL)windowShouldClose:(id)sender;",
        "@end",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.h").string(), lines);
    }
    
    void create_cocoa_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"Window1.h\"",
        "",
        "@implementation Window1",
        "- (instancetype)init {",
        "  [super initWithContentRect:NSMakeRect(100, 500, 800, 450) styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable backing:NSBackingStoreBuffered defer:NO];",
        "  [self setTitle:@\"Window1\"];",
        "  [self setIsVisible:YES];",
        "  return self;",
        "}",
        "",
        "- (BOOL)windowShouldClose:(id)sender {",
        "   [NSApp terminate:sender];",
        "   return NO;",
        "}",
        "@end",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.m").string(), lines);
    }
    
    void create_cocoa_gui_main(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"Window1.h\"",
        "",
        "// The main entry point for the application.",
        "int main(int argc, char* argv[]) {",
        "  [NSApplication sharedApplication];",
        "  [[[[Window1 alloc] init] autorelease] makeMainWindow];",
        "  [NSApp run];",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.m").string(), lines);
    }

    void create_fltk_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_fltk_gui_solution_cmakelists_txt(name);
      create_fltk_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_fltk_gui_include(name, create_solution ? path_/name.c_str() : path_);
      create_fltk_gui_source(name, create_solution ? path_/name.c_str() : path_);
      create_fltk_gui_main(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_fltk_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt).string()").string(), lines);
    }
    
    void create_fltk_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Window1.h",
        "  src/Window1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(FLTK REQUIRED)",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})",
        "target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_fltk_gui_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#pragma once",
        "#include <FL/Fl_Window.H>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public Fl_Window {",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.h").string(), lines);
    }
    
    void create_fltk_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "Window1::Window1() : Fl_Window(100, 100, 800, 450, \"Window1\") {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.cpp").string(), lines);
    }
    
    void create_fltk_gui_main(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "#include <FL/Fl.H>",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "// The main entry point for the application.",
        "int main(int argc, char* argv[]) {",
        "  Window1 window;",
        "  window.show(argc, argv);",
        "  return Fl::run();",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.cpp").string(), lines);
    }

    void create_gtk2_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_gtk2_gui_solution_cmakelists_txt(name);
      create_gtk2_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_gtk2_gui_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_gtk2_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtk2_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/program.c",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTK gtk+-2.0)",
        "include_directories(${GTK_INCLUDE_DIRS})",
        "link_directories(${GTK_LIBRARY_DIRS})",
        "link_libraries(${GTK_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtk2_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <gtk/gtk.h>",
        "",
        "/* The main entry point for the application. */",
        "int main(int argc, char* argv[]) {",
        "  gtk_init(&argc, &argv);",
        "  GtkWidget* window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);",
        "  gtk_window_set_title(GTK_WINDOW(window1), \"Window1\");",
        "  gtk_window_move(GTK_WINDOW(window1), 100, 100);",
        "  gtk_window_resize(GTK_WINDOW(window1), 800, 450);",
        "  g_signal_connect (window1, \"destroy\", G_CALLBACK(gtk_main_quit), NULL);",
        "  gtk_widget_show(window1);",
        "  gtk_main();",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"program.c").string(), lines);
    }

    void create_gtk3_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_gtk3_gui_solution_cmakelists_txt(name);
      create_gtk3_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_gtk3_gui_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_gtk3_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtk3_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/program.c",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTK gtk+-3.0)",
        "include_directories(${GTK_INCLUDE_DIRS})",
        "link_directories(${GTK_LIBRARY_DIRS})",
        "link_libraries(${GTK_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtk3_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <gtk/gtk.h>",
        "",
        "/* The main entry point for the application. */",
        "int main(int argc, char* argv[]) {",
        "  gtk_init(&argc, &argv);",
        "  GtkWidget* window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);",
        "  gtk_window_set_title(GTK_WINDOW(window1), \"Window1\");",
        "  gtk_window_move(GTK_WINDOW(window1), 100, 100);",
        "  gtk_window_resize(GTK_WINDOW(window1), 800, 450);",
        "  g_signal_connect (window1, \"destroy\", G_CALLBACK(gtk_main_quit), NULL);",
        "  gtk_widget_show(window1);",
        "  gtk_main();",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"program.c").string(), lines);
    }

    void create_gtkmm_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_gtkmm_gui_solution_cmakelists_txt(name);
      create_gtkmm_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_gtkmm_gui_include(name, create_solution ? path_/name.c_str() : path_);
      create_gtkmm_gui_source(name, create_solution ? path_/name.c_str() : path_);
      create_gtkmm_gui_main(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_gtkmm_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtkmm_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Window1.h",
        "  src/Window1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTKMM gtkmm-3.0)",
        "include_directories(${GTKMM_INCLUDE_DIRS})",
        "link_directories(${GTKMM_LIBRARY_DIRS})",
        "link_libraries(${GTKMM_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtkmm_gui_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#include <gtkmm.h>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public Gtk::Window {",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.h").string(), lines);
    }
    
    void create_gtkmm_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "",
        "using namespace Gtk;",
        xtd::ustring::format("using namespace {};", name),
        "",
        "Window1::Window1() {",
        "  set_title(\"Window1\");",
        "  move(100, 100);",
        "  resize(800, 450);",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/xtd::ustring::format("{}.cpp", name).c_str()).string(), lines);
    }
    
    void create_gtkmm_gui_main(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "",
        "using namespace Gtk;",
        xtd::ustring::format("using namespace {};", name),
        "",
        "// The main entry point for the application.",
        "int main(int argc, char* argv[]) {",
        "  auto application = Application::create(argc, argv);",
        xtd::ustring::format("  {}::Window1 window1;", name),
        "  window1.show_all();",
        "  return application->run(window1);",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.cpp").string(), lines);
    }

    void create_qt5_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) {
        create_qt5_gui_solution_cmakelists_txt(name);
        create_qt5_gui_solution_qmake_pro(name);
      }
      create_qt5_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_qt5_gui_qmake_pro(name, create_solution ? path_/name.c_str() : path_);
      create_qt5_gui_include(name, create_solution ? path_/name.c_str() : path_);
      create_qt5_gui_source(name, create_solution ? path_/name.c_str() : path_);
      create_qt5_gui_main(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_qt5_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_qt5_gui_solution_qmake_pro(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "TEMPLATE = subdirs",
        xtd::ustring::format("SUBDIRS = {}", name),
      };
      xtd::io::file::write_all_lines((path_/xtd::ustring::format("{}.pro", name).c_str()).string(), lines);
    }

    void create_qt5_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Window1.h",
        "  src/Window1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(Qt5 COMPONENTS Widgets REQUIRED)",
        "",
        "# Options",
        "set(CMAKE_AUTOMOC ON)",
        "set(CMAKE_AUTORCC ON)",
        "set(CMAKE_AUTOUIC ON)",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_link_libraries(${PROJECT_NAME} Qt5::Widgets)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_qt5_gui_qmake_pro(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "CONFIG += c++17",
        "QT = widgets",
        "HEADERS = src/Window1.h",
        "SOURCES = src/Window1.cpp src/Program.cpp",
      };
      
      xtd::io::file::write_all_lines((path/xtd::ustring::format("{}.pro", name).c_str()).string(), lines);
    }

    void create_qt5_gui_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#pragma once",
        "#include <QMainWindow>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public QMainWindow {",
        "    Q_OBJECT",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.h").string(), lines);
    }
    
    void create_qt5_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "Window1::Window1() {",
        "  setWindowTitle(\"Window1\");",
        "  move(100, 100);",
        "  resize(800, 450);",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.cpp").string(), lines);
    }
    
    void create_qt5_gui_main(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "#include <QApplication>",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "// The main entry point for the application.",
        "int main(int argc, char* argv[]) {",
        "  QApplication application(argc, argv);",
        "  Window1 window1;",
        "  window1.show();",
        "  return application.exec();",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.cpp").string(), lines);
    }

    void create_win32_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_win32_gui_solution_cmakelists_txt(name);
      create_win32_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_win32_gui_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_win32_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_win32_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Program.c",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:wmainCRTStartup\")",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "add_definitions(-DUNICODE)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_win32_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#pragma comment(linker,\"\\\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")",
        "",
        "#include <Windows.h>",
        "",
        "HWND window1 = NULL;",
        "WNDPROC defWndProc = NULL;",
        "",
        "LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {",
        "  if (message == WM_CLOSE) PostQuitMessage(0);",
        "  return CallWindowProc(defWndProc, hwnd, message, wParam, lParam);",
        "}",
        "",
        "int wmain(int argc, wchar_t* argv[]) {",
        "  window1 = CreateWindowEx(0, WC_DIALOG, L\"Window1\", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 450, NULL, NULL, NULL, NULL);",
        "",
        "  defWndProc = (WNDPROC)SetWindowLongPtr(window1, GWLP_WNDPROC, (LONG_PTR)WndProc);",
        "  ShowWindow(window1, SW_SHOW);",
        "",
        "  MSG message = {};",
        "  while (GetMessage(&message, NULL, 0, 0))",
        "    DispatchMessage(&message);",
        "  return (int)message.wParam;",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.c").string(), lines);
    }

    void create_winforms_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_winforms_gui_solution_cmakelists_txt(name);
      create_winforms_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_winforms_gui_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_winforms_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_winforms_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        "  src/Program.cs",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 ${SOURCES})",
        "set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES",
        "  Microsoft.CSharp",
        "  System",
        "  System.Drawing",
        "  System.Windows.Forms",
        ")",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_winforms_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Form1 class.",
        "using System;",
        "using System.Drawing;",
        "using System.Windows.Forms;",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the Form1 class.",
        "  class Form1 : Form {",
        "    /// @brief Initializes a new instance of the Form1 class.",
        "    public Form1() {",
        "      Text = \"Form1\";",
        "      ClientSize = new Size(800, 450);",
        "    }",
        "",
        "    /// @brief The main entry point for the application.",
        "    [STAThread]",
        "    static void Main(string[] args) {",
        "      Application.EnableVisualStyles();",
        "      Application.Run(new Form1());",
        "    }",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.cs").string(), lines);
    }

    void create_wpf_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_wpf_gui_solution_cmakelists_txt(name);
      create_wpf_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_wpf_gui_source(name, create_solution ? path_/name.c_str() : path_);
      create_wpf_gui_window1_xaml(name, create_solution ? path_/name.c_str() : path_);
      create_wpf_gui_application_config(name, create_solution ? path_/name.c_str() : path_);
      create_wpf_gui_application_source(name, create_solution ? path_/name.c_str() : path_);
      create_wpf_gui_application_xaml(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_wpf_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_wpf_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        "  src/App.config",
        "  src/App.xaml",
        "  src/App.xaml.cs",
        "  src/Window1.xaml",
        "  src/Window1.xaml.cs",
        ")",
        "csharp_set_xaml_cs_properties(",
        "  src/App.xaml",
        "  src/App.xaml.cs",
        "  src/Window1.xaml",
        "  src/Window1.xaml.cs",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "set_property(SOURCE src/App.xaml PROPERTY VS_XAML_TYPE \"ApplicationDefinition\")",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 ${SOURCES})",
        "set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES",
        "  Microsoft.CSharp",
        "  PresentationCore",
        "  PresentationFramework",
        "  System",
        "  System.Xaml",
        "  System.Xml",
        "  System.Xml.Linq",
        "  WindowsBase",
        ")",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_wpf_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "using System.Windows;",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  public partial class Window1 : Window {",
        "    public Window1() {",
        "      InitializeComponent();",
        "    }",
        "  }",
        "}",
      };
      xtd::io::file::write_all_lines((path/"src"/"Window1.xaml.cs").string(), lines);
    }
      
    void create_wpf_gui_window1_xaml(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        xtd::ustring::format("<Window x:Class=\"{}.Window1\"", name),
        "        xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\"",
        "        xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\"",
        "        xmlns:d=\"http://schemas.microsoft.com/expression/blend/2008\"",
        "        xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\"",
        xtd::ustring::format("        xmlns:local=\"clr-namespace:{}\"", name),
        "        mc:Ignorable=\"d\"",
        "        Title=\"Window1\" Height=\"450\" Width=\"800\">",
        "    <Grid>",
        "",
        "    </Grid>",
        "</Window>",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Window1.xaml").string(), lines);
    }
    
    void create_wpf_gui_application_config(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "<?xml version=\"1.0\" encoding=\"utf-8\" ?>",
        "<configuration>",
        "    <startup> ",
        "        <supportedRuntime version=\"v4.0\" sku=\".NETFramework,Version=v4.7.2\" />",
        "    </startup>",
        "</configuration>",
      };
      xtd::io::file::write_all_lines((path/"src"/"App.config").string(), lines);
    }
    
    void create_wpf_gui_application_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "using System.Windows;",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  public partial class App : Application {",
        "  }",
        "}",
      };
      xtd::io::file::write_all_lines((path/"src"/"App.xaml.cs").string(), lines);
    }

    void create_wpf_gui_application_xaml(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        xtd::ustring::format("<Application x:Class=\"{}.App\"", name),
        "        xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\"",
        "        xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\"",
        xtd::ustring::format("    xmlns:local=\"clr-namespace:{}\"", name),
        "        StartupUri=\"src\\Window1.xaml\">",
        "    <Application.Resources>",
        "",
        "    </Application.Resources>",
        "</Application>",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"App.xaml").string(), lines);
    }

    void create_wxwidgets_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_wxwidgets_gui_solution_cmakelists_txt(name);
      create_wxwidgets_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_wxwidgets_gui_include(name, create_solution ? path_/name.c_str() : path_);
      create_wxwidgets_gui_source(name, create_solution ? path_/name.c_str() : path_);
      create_wxwidgets_gui_main(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_wxwidgets_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_wxwidgets_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Frame1.h",
        "  src/Frame1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(wxWidgets REQUIRED)",
        "include(${wxWidgets_USE_FILE})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_wxwidgets_gui_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Frame1 class.",
        "#pragma once",
        "#include <wx/frame.h>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Frame1 : public wxFrame {",
        "  public:",
        "    /// @brief Initializes a new instance of the Frame1 class.",
        "    Frame1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Frame1.h").string(), lines);
    }
    
    void create_wxwidgets_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Frame1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "Frame1::Frame1() : wxFrame(nullptr, wxID_ANY, \"Frame1\", wxDefaultPosition, {800, 450}) {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Frame1.cpp").string(), lines);
    }
    
    void create_wxwidgets_gui_main(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Frame1.h\"",
        "#include <wx/app.h>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  // Represent the application",
        "  class Application : public wxApp {",
        "    bool OnInit() override {",
        "      (new Frame1())->Show();",
        "      return true;",
        "    }",
        "  };",
        "}",
        "",
        "// The main entry point for the application.",
        xtd::ustring::format("wxIMPLEMENT_APP({}::Application);", name),
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Program.cpp").string(), lines);
    }

    void create_xtd_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"properties" : path_/"properties");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"resources" : path_/"resources");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      std::filesystem::copy(get_base_path()/"share"/"xtd"/"resources"/"icons"/"xtd_forms.icns", path_/(create_solution ? name.c_str() : "" )/"resources"/xtd::ustring::format("{}.icns", name).c_str());
      std::filesystem::copy(get_base_path()/"share"/"xtd"/"resources"/"icons"/"xtd_forms.ico", path_/(create_solution ? name.c_str() : "" )/"resources"/xtd::ustring::format("{}.ico", name).c_str());
      std::filesystem::copy(get_base_path()/"share"/"xtd"/"resources"/"icons"/"xtd_forms.png", path_/(create_solution ? name .c_str(): "" )/"resources"/xtd::ustring::format("{}.png", name).c_str());
      if (create_solution) create_xtd_gui_solution_cmakelists_txt(name);
      create_xtd_gui_application_properties(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_gui_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_gui_include(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_gui_source(name, create_solution ? path_/name.c_str() : path_);
    }

    void create_xtd_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_gui_application_properties(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_icon(resources/{})", name),
        xtd::ustring::format("target_name(\"{}\")", name),
        xtd::ustring::format("target_startup(\"{}::form1\" src/form1.h)", name),
      };
      
      xtd::io::file::write_all_lines((path/"properties"/"target_properties.cmake").string(), lines);
    }

    void create_xtd_gui_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/form1.h",
        "  src/form1.cpp",
        ")",
        "target_type(GUI_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_gui_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains form1 class.",
        "#pragma once",
        "#include <xtd/xtd.forms>",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the main form.",
        "  class form1 : public xtd::forms::form {",
        "  public:",
        "    /// @brief Initializes a new instance of the form1 class.",
        "    form1();",
        "",
        "    /// @brief The main entry point for the application.",
        "    static void main();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"form1.h").string(), lines);
    }
    
    void create_xtd_gui_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"form1.h\"",
        "",
        "using namespace xtd::forms;",
        xtd::ustring::format("using namespace {};", name),
        "",
        "form1::form1() {",
        "  text(\"form1\");",
        "  client_size({800, 450});",
        "}",
        "",
        "void form1::main() {",
        "  application::run(form1());",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"form1.cpp").string(), lines);
    }

    void create_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      if (sdk == project_sdk::xtd)
        create_xtd_shared_library(name, sdk, language, create_solution);
      else
        std::map<project_language, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_language::c, {*this, &project_management::create_c_shared_library}}, {project_language::cpp, {*this, &project_management::create_cpp_shared_library}}, {project_language::csharp, {*this, &project_management::create_csharp_shared_library}}, {project_language::objectivec, {*this, &project_management::create_objectivec_shared_library}}}[language](name, sdk, language, create_solution);
    }
    
    void create_c_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_c_shared_library_solution_cmakelists_txt(name);
      create_c_shared_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_c_shared_library_export(name, create_solution ? path_/name.c_str() : path_);
      create_c_shared_library_include(name, create_solution ? path_/name.c_str() : path_);
      create_c_shared_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_c_shared_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_c_shared_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(INCLUDES",
        "  include/export.h",
        "  include/file1.h",
        ")",
        "set(SOURCES",
        "  src/file1.c",
        ")",
        "source_group(include FILES ${INCLUDES})",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        xtd::ustring::format("add_definitions(-D{0}_EXPORT)", name.to_upper()),
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} SHARED ${INCLUDES} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_c_shared_library_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/**",
        " * @file",
        " * @brief Contains do_stuff method.",
        " */",
        "#pragma once",
        "#include \"export.h\"",
        "",
        "/** ",
        " * @brief Represent do_stuff method.",
        " */",
        xtd::ustring::format("{}_export_ void do_stuff();", name.to_lower()),
      };
      
      xtd::io::file::write_all_lines((path/"include"/"file1.h").string(), lines);
    }
    
    void create_c_shared_library_export(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/**",
        " * @file",
        " * @brief Contains export.",
        " */",
        "#pragma once",
        "",
        "/** @cond */",
        "#if defined(WIN32)",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __declspec(dllexport)", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_ __declspec(dllimport)", name.to_lower()),
        "#  endif",
        "#else",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_", name.to_lower()),
        "#  endif",
        "#endif",
        "/** @endcond */",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"export.h").string(), lines);
    }

    void create_c_shared_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"../include/file1.h\"",
        "",
        "void do_stuff() {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"file1.c").string(), lines);
    }

    void create_cpp_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_cpp_shared_library_solution_cmakelists_txt(name);
      create_cpp_shared_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_cpp_shared_library_include(name, create_solution ? path_/name.c_str() : path_);
      create_cpp_shared_library_export(name, create_solution ? path_/name.c_str() : path_);
      create_cpp_shared_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_cpp_shared_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_cpp_shared_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(INCLUDES",
        "  include/class1.h",
        "  include/export.h",
        ")",
        "set(SOURCES",
        "  src/class1.cpp",
        ")",
        "source_group(include FILES ${INCLUDES})",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        xtd::ustring::format("add_definitions(-D{0}_EXPORT)", name.to_upper()),
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} SHARED ${INCLUDES} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_cpp_shared_library_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "#include \"export.h\"",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        xtd::ustring::format("  class {}_export_ class1 {{", name.to_lower()),
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"class1.h").string(), lines);
    }
    
    void create_cpp_shared_library_export(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains export.",
        "#pragma once",
        "",
        "/// @cond",
        "#if defined(WIN32)",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __declspec(dllexport)", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_ __declspec(dllimport)", name.to_lower()),
        "#  endif",
        "#else",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_", name.to_lower()),
        "#  endif",
        "#endif",
        "/// @endcond",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"export.h").string(), lines);
    }

    void create_cpp_shared_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"../include/class1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "class1::class1() {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"class1.cpp").string(), lines);
    }

    void create_csharp_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_csharp_shared_library_solution_cmakelists_txt(name);
      create_csharp_shared_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_csharp_shared_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_csharp_shared_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_csharp_shared_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        "  src/Class1.cs",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} SHARED ${SOURCES})",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_csharp_shared_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Class1 class.",
        "using System;",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        "  public class Class1 {",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    public Class1() {",
        "    }",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Class1.cs").string(), lines);
    }

    void create_objectivec_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_objectivec_shared_library_solution_cmakelists_txt(name);
      create_objectivec_shared_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_objectivec_shared_library_header(name, create_solution ? path_/name.c_str() : path_);
      create_objectivec_shared_library_export(name, create_solution ? path_/name.c_str() : path_);
      create_objectivec_shared_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_objectivec_shared_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_objectivec_shared_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(HEADERS",
        "  include/Class1.h",
        "  include/Export.h",
        ")",
        "set(SOURCES",
        "  src/Class1.m",
        ")",
        "source_group(include FILES ${HEADERS})",
        "source_group(src FILES ${SOURCES})",
        xtd::ustring::format("add_definitions(-D{0}_EXPORT)", name.to_upper()),
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_objectivec_shared_library_export(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#pragma once",
        xtd::ustring::format("#if defined({0}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#  define {0}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#else",
        xtd::ustring::format("#  define {0}_export_", name.to_lower()),
        "#endif",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"Export.h").string(), lines);
    }
    
    void create_objectivec_shared_library_header(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"Export.h\"",
        "#import <Foundation/Foundation.h>",
        "",
        xtd::ustring::format("{0}_export_ @interface Class1 : NSObject", name.to_lower()),
        "",
        "@end",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"Class1.h").string(), lines);
    }

    void create_objectivec_shared_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"../include/Class1.h\"",
        "",
        "@implementation Class1",
        "",
        "@end"
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Class1.m").string(), lines);
    }

    void create_xtd_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"properties" : path_/"properties");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_xtd_shared_library_solution_cmakelists_txt(name);
      create_xtd_shared_library_application_properties(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_shared_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_shared_library_include(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_shared_library_export(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_shared_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_xtd_shared_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_shared_library_application_properties(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_name(\"{}\")", name),
      };
      
      xtd::io::file::write_all_lines((path/"properties"/"target_properties.cmake").string(), lines);
    }
    
    void create_xtd_shared_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_include_directories(include)",
        "add_sources(",
        "  include/class1.h",
        "  include/export.h",
        "  src/class1.cpp",
        ")",
        "target_type(SHARED_LIBRARY)",
        "",
        "# Install",
        "add_install_include_directories(include)",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_shared_library_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "#include \"export.h\"",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        xtd::ustring::format("  class {}_export_ class1 {{", name.to_lower()),
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"class1.h").string(), lines);
    }
    
    void create_xtd_shared_library_export(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains export.",
        "#pragma once",
        "",
        "/// @cond",
        "#if defined(WIN32)",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __declspec(dllexport)", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_ __declspec(dllimport)", name.to_lower()),
        "#  endif",
        "#else",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_", name.to_lower()),
        "#  endif",
        "#endif",
        "/// @endcond",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"export.h").string(), lines);
    }
    
    void create_xtd_shared_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"../include/class1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "class1::class1() {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"class1.cpp").string(), lines);
    }

    void create_static_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      if (sdk == project_sdk::xtd)
        create_xtd_static_library(name, sdk, language, create_solution);
      else
        std::map<project_language, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_language::c, {*this, &project_management::create_c_static_library}}, {project_language::cpp, {*this, &project_management::create_cpp_static_library}}, {project_language::csharp, {*this, &project_management::create_csharp_static_library}}, {project_language::objectivec, {*this, &project_management::create_objectivec_static_library}}}[language](name, sdk, language, create_solution);
    }
    
    void create_c_static_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_c_static_library_solution_cmakelists_txt(name);
      create_c_static_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_c_static_library_include(name, create_solution ? path_/name.c_str() : path_);
      create_c_static_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_c_static_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name),
        "",
        "# Install",
        "set(INSTALL_PROJECT_NAME ${PROJECT_NAME})",
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_c_static_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(INCLUDES",
        "  include/file1.h",
        ")",
        "set(SOURCES",
        "  src/file1.c",
        ")",
        "source_group(include FILES ${INCLUDES})",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        "if (NOT INSTALL_PROJECT_NAME)",
        "  set(INSTALL_PROJECT_NAME ${PROJECT_NAME})",
        "endif()",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(FILES $<TARGET_FILE_DIR:${INSTALL_PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${INSTALL_PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${INSTALL_PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${INSTALL_PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_c_static_library_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/**",
        " * @file",
        " * @brief Contains do_stuff method.",
        " */",
        "#pragma once",
        "",
        "/** ",
        " * @brief Represent do_stuff method.",
        " */",
        "void do_stuff();",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"file1.h").string(), lines);
    }
    
    void create_c_static_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"../include/file1.h\"",
        "",
        "void do_stuff() {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"file1.c").string(), lines);
    }

    void create_cpp_static_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_cpp_static_library_solution_cmakelists_txt(name);
      create_cpp_static_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_cpp_static_library_include(name, create_solution ? path_/name.c_str() : path_);
      create_cpp_static_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_cpp_static_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_cpp_static_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(INCLUDES",
        "  include/class1.h",
        ")",
        "set(SOURCES",
        "  src/class1.cpp",
        ")",
        "source_group(include FILES ${INCLUDES})",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_cpp_static_library_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        "  class class1 {",
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"class1.h").string(), lines);
    }
    
    void create_cpp_static_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"../include/class1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "class1::class1() {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"class1.cpp").string(), lines);
    }

    void create_csharp_static_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      create_csharp_shared_library(name, sdk, language, create_solution);
    }
    
    void create_objectivec_static_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_objectivec_static_library_solution_cmakelists_txt(name);
      create_objectivec_static_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_objectivec_static_library_header(name, create_solution ? path_/name.c_str() : path_);
      create_objectivec_static_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_objectivec_static_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_objectivec_static_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(HEADERS",
        "  include/Class1.h",
        ")",
        "set(SOURCES",
        "  src/Class1.m",
        ")",
        "source_group(include FILES ${HEADERS})",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_objectivec_static_library_header(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#import <Foundation/Foundation.h>",
        "",
        "@interface Class1 : NSObject",
        "",
        "@end",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"Class1.h").string(), lines);
    }
    
    void create_objectivec_static_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"../include/Class1.h\"",
        "",
        "@implementation Class1",
        "",
        "@end"
      };
      
      xtd::io::file::write_all_lines((path/"src"/"Class1.m").string(), lines);
    }
    
    void create_xtd_static_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"include" : path_/"include");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"properties" : path_/"properties");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_xtd_static_library_solution_cmakelists_txt(name);
      create_xtd_static_library_application_properties(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_static_library_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_static_library_include(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_static_library_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_xtd_static_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_static_library_application_properties(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_name(\"{}\")", name),
      };
      
      xtd::io::file::write_all_lines((path/"properties"/"target_properties.cmake").string(), lines);
    }
    
    void create_xtd_static_library_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_include_directories(include)",
        "add_sources(",
        "  include/class1.h",
        "  src/class1.cpp",
        ")",
        "target_type(STATIC_LIBRARY)",
        "",
        "# Install",
        "add_install_include_directories(include)",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_static_library_include(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        "  class class1 {",
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"include"/"class1.h").string(), lines);
    }
    
    void create_xtd_static_library_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"../include/class1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "class1::class1() {",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"class1.cpp").string(), lines);
    }

    void create_unit_test_application(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::map<project_sdk, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {{project_sdk::catch2, {*this, &project_management::create_catch2_unit_test_application}}, {project_sdk::gtest, {*this, &project_management::create_gtest_unit_test_application}}, {project_sdk::xtd, {*this, &project_management::create_xtd_unit_test_application}}}[sdk](name, sdk, language, create_solution);
    }
    
    void create_catch2_unit_test_application(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_catch2_unit_test_application_solution_cmakelists_txt(name);
      create_catch2_unit_test_application_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_catch2_unit_test_application_source(name, create_solution ? path_/name.c_str() : path_);
      create_catch2_unit_test_application_main(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_catch2_unit_test_application_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "enable_testing()",
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_catch2_unit_test_application_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "find_package(Catch2 REQUIRED)",
        "set(SOURCES",
        "  src/main.cpp",
        "  src/unit_test1.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
        "target_link_libraries(${PROJECT_NAME} Catch2::Catch2)",
        "",
        "add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_catch2_unit_test_application_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <catch2/catch.hpp>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  TEST_CASE(\"unit_test1::test_method1\") {",
        "    REQUIRE(true);",
        "    WARN(\"Hello, World!\");",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"unit_test1.cpp").string(), lines);
    }
    
    void create_catch2_unit_test_application_main(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#define CATCH_CONFIG_MAIN",
        "#include <catch2/catch.hpp>",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"main.cpp").string(), lines);
    }

    void create_gtest_unit_test_application(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_gtest_unit_test_application_solution_cmakelists_txt(name);
      create_gtest_unit_test_application_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_gtest_unit_test_application_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_gtest_unit_test_application_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "enable_testing()",
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtest_unit_test_application_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "find_package(GTest REQUIRED)",
        "set(SOURCES",
        "  src/unit_test1.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "if (WIN32)",
        "  set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:wmainCRTStartup\")",
        "endif ()",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
        "target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)",
        "",
        "add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_gtest_unit_test_application_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <gtest/gtest.h>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  TEST(unit_test1, test_method1) {",
        "    ASSERT_TRUE(false) << \"Hello, World!\";",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"unit_test1.cpp").string(), lines);
    }
    
    void create_gtest_unit_test_application_main(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <gtest/gtest.h>",
        "",
        "int main(int argc, char* argv[]) {",
        "  testing::InitGoogleTest(&argc, argv);",
        "  return RUN_ALL_TESTS();",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"main.cpp").string(), lines);
    }

    void create_xtd_unit_test_application(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"properties" : path_/"properties");
      std::filesystem::create_directories(create_solution ? path_/name.c_str()/"src" : path_/"src");
      if (create_solution) create_xtd_unit_test_application_solution_cmakelists_txt(name);
      create_xtd_unit_test_application_application_properties(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_unit_test_application_cmakelists_txt(name, create_solution ? path_/name.c_str() : path_);
      create_xtd_unit_test_application_source(name, create_solution ? path_/name.c_str() : path_);
    }
    
    void create_xtd_unit_test_application_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines((path_/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_unit_test_application_application_properties(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_name(\"{}\")", name),
        xtd::ustring::format("target_startup(tunit_main_)", name),
      };
      
      xtd::io::file::write_all_lines((path/"properties"/"target_properties.cmake").string(), lines);
    }
    
    void create_xtd_unit_test_application_cmakelists_txt(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/unit_test1.cpp",
        ")",
        "target_type(TEST_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines((path/"CMakeLists.txt").string(), lines);
    }
    
    void create_xtd_unit_test_application_source(const xtd::ustring& name, const std::filesystem::path& path) const {
      std::vector<xtd::ustring> lines {
        "#include <xtd/xtd.tunit>",
        "",
        "using namespace xtd::tunit;",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  class test_class_(unit_test1) {",
        "  public:",
        "    void test_method_(test_method1) {",
        "      assert::ignore(\"Hello, World!\");",
        "    }",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines((path/"src"/"unit_test1.cpp").string(), lines);
    }

    void create_doxygen_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "#---------------------------------------------------------------------------",
        "# Project related configuration options",
        "#---------------------------------------------------------------------------",
        "",
        xtd::ustring::format("PROJECT_NAME           = \"{} - Reference Guide\"", name),
        "PROJECT_NUMBER         = 0.1.0",
        "PROJECT_BRIEF          = ",
        "PROJECT_LOGO           = ",
        "OUTPUT_DIRECTORY       = ",
        "ALWAYS_DETAILED_SEC    = YES",
        "INLINE_INHERITED_MEMB  = NO",
        "FULL_PATH_NAMES        = NO",
        "STRIP_FROM_PATH        = ",
        "STRIP_FROM_INC_PATH    = ",
        "TAB_SIZE               = 2",
        "TOC_INCLUDE_HEADINGS   = 0",
        "",
        "#---------------------------------------------------------------------------",
        "# Build related configuration options",
        "#---------------------------------------------------------------------------",
        "",
        "SORT_BRIEF_DOCS        = YES",
        "SORT_MEMBERS_CTORS_1ST = YES",
        "SORT_GROUP_NAMES       = YES",
        "SORT_BY_SCOPE_NAME     = YES",
        "#MAX_INITIALIZER_LINES  = 0",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to warning and progress messages",
        "#---------------------------------------------------------------------------",
        "",
        "WARN_LOGFILE           = doxygen_warnings.txt",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the input files",
        "#---------------------------------------------------------------------------",
        "",
        "INPUT                  = .",
        "RECURSIVE              = YES",
        "EXCLUDE_PATTERNS       = ",
        "EXAMPLE_PATH           = ",
        "EXAMPLE_PATTERNS       = *",
        "EXAMPLE_RECURSIVE      = YES",
        "IMAGE_PATH             = ",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to source browsing",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the alphabetical class index",
        "#---------------------------------------------------------------------------",
        "",
        "COLS_IN_ALPHA_INDEX    = 1",
        "IGNORE_PREFIX          = ",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the HTML output",
        "#---------------------------------------------------------------------------",
        "",
        "HTML_OUTPUT            = ReferenceGuide",
        "HTML_HEADER            = ",
        "HTML_FOOTER            = ",
        "HTML_STYLESHEET        = ",
        "HTML_EXTRA_STYLESHEET  = ",
        "HTML_EXTRA_FILES       = ",
        "HTML_COLORSTYLE_HUE    = 220",
        "HTML_COLORSTYLE_SAT    = 100",
        "HTML_COLORSTYLE_GAMMA  = 80",
        "HTML_TIMESTAMP         = YES",
        "HTML_DYNAMIC_SECTIONS  = NO",
        "HTML_INDEX_NUM_ENTRIES = 100",
        "GENERATE_DOCSET        = NO",
        "GENERATE_HTMLHELP      = NO",
        "GENERATE_QHP           = NO",
        "QCH_FILE               = ",
        "GENERATE_ECLIPSEHELP   = NO",
        "DISABLE_INDEX          = NO",
        "GENERATE_TREEVIEW      = YES",
        "ENUM_VALUES_PER_LINE   = 1",
        "TREEVIEW_WIDTH         = 250",
        "EXT_LINKS_IN_WINDOW    = NO",
        "FORMULA_FONTSIZE       = 10",
        "FORMULA_TRANSPARENT    = YES",
        "USE_MATHJAX            = NO",
        "SEARCHENGINE           = YES",
        "SERVER_BASED_SEARCH    = NO",
        "EXTERNAL_SEARCH        = NO",
        "SEARCHENGINE_URL       = ",
        "SEARCHDATA_FILE        = searchdata.xml",
        "EXTERNAL_SEARCH_ID     = ",
        "EXTRA_SEARCH_MAPPINGS  = ",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the LaTeX output",
        "#---------------------------------------------------------------------------",
        "",
        "GENERATE_LATEX         = NO",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the RTF output",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the man page output",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the XML output",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the DOCBOOK output",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options for the AutoGen Definitions output",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the Perl module output",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the preprocessor",
        "#---------------------------------------------------------------------------",
        "",
        "MACRO_EXPANSION        = YES",
        "EXPAND_ONLY_PREDEF     = YES",
        "SEARCH_INCLUDES        = YES",
        "INCLUDE_PATH           = ",
        "INCLUDE_FILE_PATTERNS  = ",
        "PREDEFINED             = \"final static_=final : public xtd::static\"",
        "EXPAND_AS_DEFINED      = ",
        "SKIP_FUNCTION_MACROS   = YES",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to external references",
        "#---------------------------------------------------------------------------",
        "",
        "#---------------------------------------------------------------------------",
        "# Configuration options related to the dot tool",
        "#---------------------------------------------------------------------------",
        "",
        "CLASS_DIAGRAMS         = YES",
        "DIA_PATH               = ",
        "HIDE_UNDOC_RELATIONS   = YES",
        "HAVE_DOT               = NO",
        "DOT_NUM_THREADS        = 0",
        "DOT_FONTNAME           = Helvetica",
        "DOT_FONTSIZE           = 10",
        "DOT_FONTPATH           = ",
        "CLASS_GRAPH            = YES",
        "COLLABORATION_GRAPH    = YES",
        "GROUP_GRAPHS           = YES",
        "UML_LOOK               = NO",
        "UML_LIMIT_NUM_FIELDS   = 10",
        "TEMPLATE_RELATIONS     = NO",
        "INCLUDE_GRAPH          = YES",
        "INCLUDED_BY_GRAPH      = YES",
        "CALL_GRAPH             = NO",
        "CALLER_GRAPH           = NO",
        "GRAPHICAL_HIERARCHY    = YES",
        "DIRECTORY_GRAPH        = YES",
        "DOT_IMAGE_FORMAT       = png",
        "INTERACTIVE_SVG        = NO",
        "DOT_PATH               = ",
        "DOTFILE_DIRS           = ",
        "MSCFILE_DIRS           = ",
        "DIAFILE_DIRS           = ",
        "PLANTUML_JAR_PATH      = ",
        "PLANTUML_CFG_FILE      = ",
        "PLANTUML_INCLUDE_PATH  = ",
        "DOT_GRAPH_MAX_NODES    = 50",
        "MAX_DOT_GRAPH_DEPTH    = 0",
        "DOT_TRANSPARENT        = NO",
        "DOT_MULTI_TARGETS      = NO",
        "GENERATE_LEGEND        = YES",
        "DOT_CLEANUP            = YES",
      };
      xtd::io::file::write_all_lines((path_/".doxygen.txt").string(), lines);
    }
    
    void create_readme_md(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        xtd::ustring::format("# {}", name),
      };
      xtd::io::file::write_all_lines((path_/"README.md").string(), lines);
    }

    void generate() const {generate(path_.filename().string());}

    void generate(xtd::ustring name) const {
      bool first_generation = !std::filesystem::exists(build_path());
      std::filesystem::create_directories(build_path());
      change_current_directory current_directory {build_path()};
      if (!first_generation && name.empty()) name = get_name();
      if (xtd::environment::os_version().is_windows_platform() && (first_generation || !std::filesystem::exists(build_path()/xtd::ustring::format("{}.sln", name).c_str())))
        launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {}", path_, build_path()));
      else if (xtd::environment::os_version().is_macos_platform() && (first_generation || !std::filesystem::exists(build_path()/xtd::ustring::format("{}.xcodeproj", name).c_str())))
        launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {} -G \"Xcode\"", path_, build_path()));
      else if (xtd::environment::os_version().is_linux_platform()) {
        if (first_generation || !std::filesystem::exists(build_path()/"Debug"/xtd::ustring::format("{}.cbp", name).c_str())) {
          change_current_directory current_directory_debug {build_path()/"Debug"};
          std::filesystem::create_directories(build_path()/"Debug");
          launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", path_, build_path()/"Debug"));
          patch_cbp_file(name, "Debug");
        }
        if (first_generation || !std::filesystem::exists(build_path()/"Release"/xtd::ustring::format("{}.cbp", name).c_str())) {
          change_current_directory current_directory_release {build_path()/"Release"};
          std::filesystem::create_directories(build_path()/"Release");
          launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", path_, build_path()/"Release"));
          patch_cbp_file(name, "Release");
        }
      }
    }
    
    bool is_path_already_exist_and_not_empty(const std::filesystem::path& path) const {
      if (!std::filesystem::exists({path_})) return false;
      if (std::filesystem::is_empty({path_})) return false;
      if (xtd::environment::os_version().is_macos_platform() && std::count_if(std::filesystem::directory_iterator(path_), std::filesystem::directory_iterator(), [](auto item) {return item.path().filename().string() != ".DS_Store";}) == 0) return false;
      return true;
    }
    
    void launch_and_wait_process(const xtd::ustring& file_name) const {
      launch_and_wait_process(file_name, false);
    }
    
    void launch_and_wait_process(const xtd::ustring& file_name, bool shell_execute) const {
      launch_and_wait_process(file_name, "", shell_execute);
    }
    
    void launch_and_wait_process(const xtd::ustring& file_name, const xtd::ustring& arguments) const {
      launch_and_wait_process(file_name, arguments, false);
    }
    
    void launch_and_wait_process(const xtd::ustring& file_name, const xtd::ustring& arguments, bool shell_execute) const {
      xtd::diagnostics::process process;
      process.start_info({file_name, arguments});
      process.start_info().use_shell_execute(shell_execute);
      process.start();
      process.wait_for_exit();
      last_exit_code_ = process.exit_code();
    }
    
    void patch_cbp_file(const xtd::ustring& name, const xtd::ustring& build_config) const {
      if (xtd::io::file::read_all_text(std::filesystem::exists((path_/name.c_str()/"CMakeLists.txt").string()) ? (path_/name.c_str()/"CMakeLists.txt").string() : (path_/"CMakeLists.txt").string()).contains("GUI_APPLICATION")) {
        auto cbp_file_lines = xtd::io::file::read_all_lines((build_path()/build_config.c_str()/xtd::ustring::format("{}.cbp", name).c_str()).string());
        for (auto iterator = std::find(cbp_file_lines.begin(), cbp_file_lines.end(), xtd::ustring::format("\t\t\t<Target title=\"{}\">", name)); iterator != cbp_file_lines.end(); ++iterator) {
          if (*iterator == "\t\t\t\t<Option type=\"1\"/>") {
            *iterator = "\t\t\t\t<Option type=\"0\"/>";
            break;
          }
        }
        xtd::io::file::write_all_lines((build_path()/build_config.c_str()/xtd::ustring::format("{}.cbp", name).c_str()).string(), cbp_file_lines);
      }
    }
    
    mutable std::filesystem::path path_ {xtd::environment::current_directory().c_str()};
    mutable int32_t last_exit_code_ = EXIT_SUCCESS;
  };
}
