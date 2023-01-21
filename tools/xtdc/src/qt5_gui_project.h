#pragma once
#include "base_project.h"

namespace xtdc_command {
  class qt5_gui_project : public base_project {
  public:
    explicit qt5_gui_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) {
        create_solution_cmakelists_txt(name);
        create_solution_qmake_pro(name);
      }
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_qmake_pro(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_main(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_solution_qmake_pro(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "TEMPLATE = subdirs",
        xtd::ustring::format("SUBDIRS = {}", name),
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), xtd::ustring::format("{}.pro", name)), lines);
    }
    
    void create_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
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
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_qmake_pro(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "CONFIG += c++17",
        "QT = widgets",
        "HEADERS = src/Window1.h",
        "SOURCES = src/Window1.cpp src/Program.cpp",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", xtd::ustring::format("{}.pro", name)), lines);
    }
    
    void create_include(const xtd::ustring& name, const xtd::ustring& path) const {
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
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.h"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
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
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.cpp"), lines);
    }
    
    void create_main(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Window1.h\"",
        "#include <QApplication>",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "// The main entry point for the application.",
        "auto main(int argc, char* argv[])->int {",
        "  QApplication application(argc, argv);",
        "  Window1 window1;",
        "  window1.show();",
        "  return application.exec();",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cpp"), lines);
    }
  };
}
