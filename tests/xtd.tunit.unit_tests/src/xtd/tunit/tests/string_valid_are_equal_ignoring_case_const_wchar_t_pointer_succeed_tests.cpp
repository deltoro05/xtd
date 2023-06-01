#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(string_valid_are_equal_ignoring_case_const_wchar_t_pointer_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      const wchar* s = L"VALUE";
      xtd::tunit::string_valid::are_equal_ignoring_case(L"value", s);
    }
  };
}

void test_(string_valid_are_equal_ignoring_case_const_wchar_t_pointer_succeed_tests, test_output) {
  auto [output, result] = run_test_("string_valid_are_equal_ignoring_case_const_wchar_t_pointer_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED string_valid_are_equal_ignoring_case_const_wchar_t_pointer_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(string_valid_are_equal_ignoring_case_const_wchar_t_pointer_succeed_tests, test_result) {
  auto [output, result] = run_test_("string_valid_are_equal_ignoring_case_const_wchar_t_pointer_succeed_tests.*");
  assert_value_(0, result);
}
