#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <string>

namespace xtd::tunit::tests {
  class test_class_(valid_is_empty_string_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::string s = "string";
      xtd::tunit::valid::is_empty(s);
    }
  };
}

void test_(valid_is_empty_string_failed_tests, test_output) {
  auto [result, output] = run_test_("valid_is_empty_string_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_is_empty_string_failed_tests.test_case_failed\n"
    "    Expected: collection <empty>\n"
    "    But was:  < 's', 't', 'r', 'i', 'n', 'g' >\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_is_empty_string_failed_tests, test_result) {
  auto [result, output] = run_test_("valid_is_empty_string_failed_tests.*");
  assert_value_(1, result);
}
