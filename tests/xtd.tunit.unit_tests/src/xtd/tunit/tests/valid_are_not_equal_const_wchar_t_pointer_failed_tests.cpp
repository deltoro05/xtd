#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(valid_are_not_equal_const_wchar_t_pointer_failed__tests) {
  public:
    void test_method_(test_case_failed) {
      const wchar* s = L"value";
      xtd::tunit::valid::are_not_equal(L"value", s);
    }
  };
}

void test_(valid_are_not_equal_const_wchar_t_pointer_failed__tests, test_output) {
  auto [result, output] = run_test_("valid_are_not_equal_const_wchar_t_pointer_failed__tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_are_not_equal_const_wchar_t_pointer_failed__tests.test_case_failed\n"
    "    Expected: not \"value\"\n"
    "    But was:  \"value\"\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_are_not_equal_const_wchar_t_pointer_failed__tests, test_result) {
  auto [result, output] = run_test_("valid_are_not_equal_const_wchar_t_pointer_failed__tests.*");
  assert_value_(1, result);
}
