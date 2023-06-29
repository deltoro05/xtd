#include <xtd/tunit/assume.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>
#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <memory>

namespace xtd::tunit::tests {
  class test_class_(assume_is_not_null_weak_ptr_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      std::shared_ptr<int> i = std::make_shared<int>(42);
      std::weak_ptr<int> p = i;
      xtd::tunit::assume::is_not_null(p);
    }
  };
}

void test_(assume_is_not_null_weak_ptr_succeed_tests, test_output) {
  auto [output, result] = run_test_("assume_is_not_null_weak_ptr_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED assume_is_not_null_weak_ptr_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_is_not_null_weak_ptr_succeed_tests, test_result) {
  auto [output, result] = run_test_("assume_is_not_null_weak_ptr_succeed_tests.*");
  assert_value_(0, result);
}
