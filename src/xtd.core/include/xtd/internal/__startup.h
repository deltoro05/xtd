/// @file
/// @brief Contains __startup__ struct.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../collections/specialized/string_vector.h"
#include "../environment.h"
#include "../static.h"
#include "../ustring.h"

/// @cond
struct __startup__ final static_ {
  static int run(void (*main_function)(), int, char* []) {main_function(); return xtd::environment::exit_code();}
  static int run(void (*main_function)()) {main_function(); return xtd::environment::exit_code();}
  static int run(void (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {main_function(argc, argv); return xtd::environment::exit_code();}
  static int run(void (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {main_function({argv + 1, argv + argc}); return xtd::environment::exit_code();}
  static int run(int (*main_function)(), int, char* []) {return main_function();}
  static int run(int (*main_function)()) {return main_function();}
  static int run(int (*main_function)(int argc, char* argv[]), int argc, char* argv[]) {return main_function(argc, argv);}
  static int run(int (*main_function)(const xtd::collections::specialized::string_vector&), int argc, char* argv[]) {return main_function({argv + 1, argv + argc});}
};
/// @endcond
