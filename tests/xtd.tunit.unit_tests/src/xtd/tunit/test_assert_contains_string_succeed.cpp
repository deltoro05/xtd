#include "assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(test_assert_contains_string_succeed) {
  public:
    void test_method_(test_case_succeed) {
      std::string s = "string";
      xtd::tunit::assert::contains('i', s);
    }
  };
}

void test_(test_assert_contains_string_succeed, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_contains_string_succeed.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED test_assert_contains_string_succeed.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_contains_string_succeed, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_contains_string_succeed.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
