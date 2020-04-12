#include "main_form.h"
#include "../properties/settings.h"
#include <list>
#include <filesystem>
#include <xtd/environment.h>
#include <xtd/forms/application.h>
#include <xtd/forms/folder_browser_dialog.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtdc_gui;

main_form::main_form() {
  client_size({1000, 710});
  minimize_box(false);
  maximize_box(false);
  start_position(form_start_position::center_screen);
  
  startup_panel_.parent(*this);
  startup_panel_.size(client_size() - xtd::drawing::size {0, 100});
  startup_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  
  startup_title_label_.parent(startup_panel_);
  startup_title_label_.location({50, 50});
  startup_title_label_.auto_size(true);
  startup_title_label_.text("xtdc-gui");
  startup_title_label_.font({startup_title_label_.font(), 24.0});
  
  startup_open_recent_project_title_label_.parent(startup_panel_);
  startup_open_recent_project_title_label_.location({50, 115});
  startup_open_recent_project_title_label_.auto_size(true);
  startup_open_recent_project_title_label_.text("Open recent");
  startup_open_recent_project_title_label_.font({startup_open_recent_project_title_label_.font(), 16.0});
  
  startup_open_recent_projects_list_box_.parent(startup_panel_);
  startup_open_recent_projects_list_box_.location({50, 175});
  startup_open_recent_projects_list_box_.size({500, startup_panel_.size().height() - 175});
  startup_open_recent_projects_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  startup_open_recent_projects_list_box_.key_down += [&](control& sender, key_event_args& e) {
    if (e.key_code() == keys::del && startup_open_recent_projects_list_box_.selected_index() != -1)
      delete_project(properties::settings::default_settings().open_recent_propjects()[startup_open_recent_projects_list_box_.selected_index()]);
  };

  startup_open_recent_projects_list_box_.double_click += [&] {
    if (startup_open_recent_projects_list_box_.selected_index() != -1) {
      open_project(properties::settings::default_settings().open_recent_propjects()[startup_open_recent_projects_list_box_.selected_index()]);
      if (properties::settings::default_settings().auto_close()) close();
    }
  };
  
  startup_get_started_title_label_.parent(startup_panel_);
  startup_get_started_title_label_.location({startup_panel_.size().width() - 400, 115});
  startup_get_started_title_label_.auto_size(true);
  startup_get_started_title_label_.text("Get started");
  startup_get_started_title_label_.font({startup_get_started_title_label_.font(), 16.0});
  startup_get_started_title_label_.anchor(anchor_styles::top|anchor_styles::right);

  startup_open_project_button_.parent(startup_panel_);
  startup_open_project_button_.text("Open a project or solution");
  startup_open_project_button_.location({startup_panel_.size().width() - 400, 175});
  startup_open_project_button_.size({350, 100});
  startup_open_project_button_.font({startup_open_project_button_.font(), 16.0});
  startup_open_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_open_project_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().open_propject_folder());
    if (dialog.show_dialog() == dialog_result::ok) {
      open_project(dialog.selected_path());
      if (properties::settings::default_settings().auto_close()) close();
    }
  };

  startup_run_project_button_.parent(startup_panel_);
  startup_run_project_button_.text("Run a project");
  startup_run_project_button_.location({startup_panel_.size().width() - 400, 285});
  startup_run_project_button_.size({350, 100});
  startup_run_project_button_.font({startup_run_project_button_.font(), 16.0});
  startup_run_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_run_project_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().open_propject_folder());
    if (dialog.show_dialog() == dialog_result::ok) {
      run_project(dialog.selected_path());
      if (properties::settings::default_settings().auto_close()) close();
    }
  };

  startup_new_project_button_.parent(startup_panel_);
  startup_new_project_button_.text("Create a new project");
  startup_new_project_button_.location({startup_panel_.size().width() - 400, 395});
  startup_new_project_button_.size({350, 100});
  startup_new_project_button_.font({startup_new_project_button_.font(), 16.0});
  startup_new_project_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_new_project_button_.click += [&] {
    startup_panel_.visible(false);
    create_panel_.visible(true);
    previous_button_.visible(true);
    next_button_.text("&Next");
    next_button_.visible(true);
  };

  startup_open_xtd_examples_button_.parent(startup_panel_);
  startup_open_xtd_examples_button_.text("Open xtd examples");
  startup_open_xtd_examples_button_.location({startup_panel_.size().width() - 400, 505});
  startup_open_xtd_examples_button_.size({350, 100});
  startup_open_xtd_examples_button_.font({startup_new_project_button_.font(), 16.0});
  startup_open_xtd_examples_button_.anchor(anchor_styles::top|anchor_styles::right);
  startup_open_xtd_examples_button_.click += [&] {
    startup_panel_.visible(false);
    open_xtd_examples_panel_.visible(true);
    previous_button_.visible(true);
    next_button_.text("&Open");
    next_button_.visible(true);
  };

  open_xtd_examples_panel_.parent(*this);
  open_xtd_examples_panel_.size(client_size() - xtd::drawing::size {0, 100});
  open_xtd_examples_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  //create_panel_.back_color(color::red);
  open_xtd_examples_panel_.visible(false);

  open_xtd_examples_title_label_.parent(open_xtd_examples_panel_);
  open_xtd_examples_title_label_.location({50, 50});
  open_xtd_examples_title_label_.auto_size(true);
  open_xtd_examples_title_label_.text("Open xtd examples");
  open_xtd_examples_title_label_.font({open_xtd_examples_title_label_.font(), 24.0});

  create_panel_.parent(*this);
  create_panel_.size(client_size() - xtd::drawing::size {0, 100});
  create_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  //create_panel_.back_color(color::red);
  create_panel_.visible(false);

  create_title_label_.parent(create_panel_);
  create_title_label_.location({50, 50});
  create_title_label_.auto_size(true);
  create_title_label_.text("Create a new project");
  create_title_label_.font({create_title_label_.font(), 24.0});
  
  create_recent_project_title_label_.parent(create_panel_);
  create_recent_project_title_label_.location({50, 115});
  create_recent_project_title_label_.auto_size(true);
  create_recent_project_title_label_.text("Recent project templates");
  create_recent_project_title_label_.font({create_title_label_.font(), 16.0});
  
  create_recent_projects_list_box_.parent(create_panel_);
  create_recent_projects_list_box_.location({50, 175});
  create_recent_projects_list_box_.size({400, create_panel_.size().height() - 175});
  create_recent_projects_list_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  create_recent_projects_list_box_.items().push_back_range({"xtd GUI Application (c++)", "xtd Console Application (c++)"});
  create_recent_projects_list_box_.selected_index_changed += [&] {
    if (create_recent_projects_list_box_.selected_index() == -1)
      next_button_.enabled(false);
    else {
      create_project_type_items_control_.selected_index(-1);
      //current_project_type_ = create_recent_projects_list_box_.selected_item();
      next_button_.enabled(true);
    }
  };

  create_language_choice_.parent(create_panel_);
  create_language_choice_.width(140);
  create_language_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 400, 50});
  create_language_choice_.anchor(anchor_styles::top|anchor_styles::right);
  create_language_choice_.items().push_back_range({{"All languages", project_language::all}, {"xtd (c++)", project_language::xtd}, {"c++", project_language::cpp}, {"c", project_language::c}, {"c#", project_language::csharp}, {"objective-c", project_language::objectivec}});
  create_language_choice_.selected_value_changed += [&] {
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_language_choice_.selected_index(1);

  create_platform_choice_.parent(create_panel_);
  create_platform_choice_.width(140);
  create_platform_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 230, 50});
  create_platform_choice_.anchor(anchor_styles::top|anchor_styles::right);
  create_platform_choice_.items().push_back_range({{"All platforms", project_platform::all}, {"Windows", project_platform::windows}, {"Linux", project_platform::linux}, {"macOS", project_platform::macos}});
  create_platform_choice_.selected_value_changed += [&] {
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_platform_choice_.selected_index(environment::os_version().is_windows_platform() ? 1 : environment::os_version().is_linux_platform() ? 2 : 3);
  
  create_type_choice_.parent(create_panel_);
  create_type_choice_.width(140);
  create_type_choice_.location({create_panel_.size().width() - create_type_choice_.width() - 50, 50});
  create_type_choice_.anchor(anchor_styles::top|anchor_styles::right);
  create_type_choice_.items().push_back_range({{"All project types", project_type::all}, {"Gui", project_type::gui}, {"Console", project_type::console}, {"Shared library", project_type::shared_library}, {"Static library", project_type::static_library}, {"UnitTest Project", project_type::unit_tests_project}, {"Solution File", project_type::solution_file}});
  create_type_choice_.selected_value_changed += [&] {
    create_project_type_items_control_.filter_items(create_language_choice_.selected_item().tag().has_value() ? any_cast<project_language>(create_language_choice_.selected_item().tag()) : project_language::all, create_platform_choice_.selected_item().tag().has_value() ? any_cast<project_platform>(create_platform_choice_.selected_item().tag()) : project_platform::all, create_type_choice_.selected_item().tag().has_value() ? any_cast<project_type>(create_type_choice_.selected_item().tag()) : project_type::all);
  };
  create_type_choice_.selected_index(0);

  create_project_type_items_control_.parent(create_panel_);
  create_project_type_items_control_.location({create_panel_.size().width() - 475 - 50, 100});
  create_project_type_items_control_.size({475, create_panel_.size().height() - 100});
  create_project_type_items_control_.anchor(anchor_styles::top|anchor_styles::bottom|anchor_styles::right);
  create_project_type_items_control_.selected_index_changed += [&] {
    if (create_project_type_items_control_.selected_index() == -1)
      next_button_.enabled(false);
    else {
      create_recent_projects_list_box_.selected_index(-1);
      current_project_type_ = create_project_type_items_control_.selected_project_type_item();
      next_button_.enabled(true);
    }
  };

  configure_panel_.parent(*this);
  configure_panel_.size(client_size() - xtd::drawing::size {0, 100});
  configure_panel_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
  //configure_panel_.back_color(color::red);
  configure_panel_.visible(false);

  configure_title_label_.parent(configure_panel_);
  configure_title_label_.location({50, 50});
  configure_title_label_.auto_size(true);
  configure_title_label_.text("Configure your new project");
  configure_title_label_.font({create_title_label_.font(), 24.0});
  
  configure_project_type_title_label_.parent(configure_panel_);
  configure_project_type_title_label_.location({50, 115});
  configure_project_type_title_label_.auto_size(true);
  configure_project_type_title_label_.text("Project type information");
  configure_project_type_title_label_.font({create_title_label_.font(), 16.0});

  configure_project_name_label_.parent(configure_panel_);
  configure_project_name_label_.location({50, 180});
  configure_project_name_label_.auto_size(true);
  configure_project_name_label_.text("Project name");
  
  configure_project_name_text_box_.parent(configure_panel_);
  configure_project_name_text_box_.location({50, 210});
  configure_project_name_text_box_.width(550);

  configure_project_location_label_.parent(configure_panel_);
  configure_project_location_label_.location({50, 270});
  configure_project_location_label_.auto_size(true);
  configure_project_location_label_.text("Project location");
  
  configure_project_location_text_box_.parent(configure_panel_);
  configure_project_location_text_box_.location({50, 300});
  configure_project_location_text_box_.width(550);
  configure_project_location_text_box_.text(properties::settings::default_settings().create_propject_folder());
  
  configure_project_location_button_.parent(configure_panel_);
  configure_project_location_button_.location({620, 300});
  configure_project_location_button_.width(37);
  configure_project_location_button_.text("...");
  configure_project_location_button_.click += [&] {
    folder_browser_dialog dialog;
    dialog.selected_path(properties::settings::default_settings().create_propject_folder());
    if (dialog.show_dialog() == dialog_result::ok) {
      properties::settings::default_settings().create_propject_folder(dialog.selected_path());
      properties::settings::default_settings().save();
      configure_project_location_text_box_.text(properties::settings::default_settings().create_propject_folder());
    }
  };

  previous_button_.parent(*this);
  previous_button_.text("&Back");
  previous_button_.visible(false);
  previous_button_.location(client_size() - xtd::drawing::size {215, 75});
  previous_button_.anchor(anchor_styles::bottom|anchor_styles::right);
  previous_button_.click += [&] {
    if (open_xtd_examples_panel_.visible()) {
      startup_panel_.visible(true);
      open_xtd_examples_panel_.visible(false);
      previous_button_.visible(false);
      next_button_.visible(false);
    } else if (create_panel_.visible()) {
      startup_panel_.visible(true);
      create_panel_.visible(false);
      previous_button_.visible(false);
      next_button_.visible(false);
    } else {
      previous_button_.text("&Back");
      next_button_.text("&Next");
      create_panel_.visible(true);
      configure_panel_.visible(false);
    }
  };

  next_button_.parent(*this);
  next_button_.text("&Next");
  next_button_.visible(false);
  next_button_.enabled(false);
  next_button_.location(client_size() - xtd::drawing::size {125, 75});
  next_button_.anchor(anchor_styles::bottom|anchor_styles::right);
  next_button_.click += [&] {
    if (create_panel_.visible()) {
      auto project_name = std::map<project_type, std::string> {{project_type::gui, "gui_app"}, {project_type::console, "console_app"}, {project_type::shared_library, "class_library"}, {project_type::static_library, "class_library"}, {project_type::unit_tests_project, "unit_test_project"}, {project_type::solution_file, "solution_file"}}[current_project_type_.project_type()];
      auto index = 1;
      while (std::filesystem::exists(std::filesystem::path {configure_project_location_text_box_.text()}/xtd::strings::format("{}{}", project_name, index))) index++;
      configure_project_name_text_box_.text(xtd::strings::format("{}{}", project_name, index));
      previous_button_.text("&Back");
      next_button_.text("&Create");
      create_panel_.visible(false);
      configure_panel_.visible(true);
    } else {
      auto project_path = std::filesystem::path {std::filesystem::path {configure_project_location_text_box_.text()}/configure_project_name_text_box_.text()}.string();
      new_project(project_path, current_project_type_.project_type(), current_project_type_.project_language());
      startup_panel_.visible(true);
      configure_panel_.visible(false);
      previous_button_.visible(false);
      next_button_.text("&Next");
      next_button_.visible(false);
      if (properties::settings::default_settings().auto_close()) close();
    }
  };
  
  init();
}

void main_form::delete_project(const std::string& project_path) {
  auto open_recent_projects = properties::settings::default_settings().open_recent_propjects();
  open_recent_projects.erase(std::find(open_recent_projects.begin(), open_recent_projects.end(), project_path));
  properties::settings::default_settings().open_recent_propjects(open_recent_projects);
  properties::settings::default_settings().save();
  init_startup_open_recent_projects_list_box();
}

void main_form::init() {
  init_startup_open_recent_projects_list_box();
}

void main_form::init_startup_open_recent_projects_list_box() {
  startup_open_recent_projects_list_box_.items().clear();
  for (auto item : properties::settings::default_settings().open_recent_propjects())
    startup_open_recent_projects_list_box_.items().push_back(xtd::strings::format("{} ({})", std::filesystem::path(item).stem().string(), item));
  startup_open_recent_projects_list_box_.selected_index(startup_open_recent_projects_list_box_.items().size() == 0 ? -1 : 0);
}

void main_form::add_to_open_recent_projects(const std::string& project_path) {
  auto open_recent_projects_from_settings = properties::settings::default_settings().open_recent_propjects();
  std::list<std::string> open_recent_projects {open_recent_projects_from_settings.begin(), open_recent_projects_from_settings.end()};
  if (std::find(open_recent_projects.begin(), open_recent_projects.end(), project_path) != open_recent_projects.end())
    open_recent_projects.erase(std::find(open_recent_projects.begin(), open_recent_projects.end(), project_path));

  open_recent_projects.push_front(project_path);
  properties::settings::default_settings().open_recent_propjects(std::vector<std::string> {open_recent_projects.begin(), open_recent_projects.end()});
  properties::settings::default_settings().open_propject_folder(project_path);
  properties::settings::default_settings().save();

  init_startup_open_recent_projects_list_box();
}

void main_form::new_project(const std::string& project_path, project_type type, project_language language) {
  add_to_open_recent_projects(project_path);
  application::do_events();
  system(strings::format("xtdc new {} -s {} {}", std::map<project_type, std::string> {{project_type::gui, "gui"}, {project_type::console, "console"}, {project_type::shared_library, "sharedlib"}, {project_type::static_library, "staticlib"}, {project_type::unit_tests_project, "test"}, {project_type::solution_file, "sln"}, }[type], std::map<project_language, std::string> {{project_language::xtd, "xtd"}, {project_language::cpp, "c++"}, {project_language::c, "c"}, {project_language::csharp, "c#"}, {project_language::objectivec, "objective-c"}, }[language], project_path).c_str());
  system(strings::format("xtdc open {}", project_path).c_str());
}

void main_form::open_project(const std::string& project_path) {
  add_to_open_recent_projects(project_path);
  application::do_events();
  system(strings::format("xtdc open {}", project_path).c_str());
}

void main_form::run_project(const std::string& project_path) {
  add_to_open_recent_projects(project_path);
  application::do_events();
  system(strings::format("xtdc run {}", project_path).c_str());
}

void main_form::main() {
  application::enable_visual_styles();
  application::run(main_form());
}
