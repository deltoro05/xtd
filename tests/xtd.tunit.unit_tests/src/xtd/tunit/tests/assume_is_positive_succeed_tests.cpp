#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(assume_is_positive_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      int i = 1;
      xtd::tunit::assume::is_positive(i);
    }
  };
}

void test_(assume_is_positive_succeed_tests, test_output) {
  auto [output, result] = run_test_("assume_is_positive_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assume_is_positive_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_is_positive_succeed_tests, test_result) {
  auto [output, result] = run_test_("assume_is_positive_succeed_tests.*");
  assert_value_(0, result);
}
