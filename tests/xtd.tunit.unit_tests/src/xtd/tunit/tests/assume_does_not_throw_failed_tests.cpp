#include <xtd/tunit/assume.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>
#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(assume_does_not_throw_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector v = {1, 2, 3, 4};
      xtd::tunit::assume::does_not_throw([&] {v.at(5);});
    }
  };
}

void test_(assume_does_not_throw_failed_tests, test_output) {
  auto [output, result] = run_test_("assume_does_not_throw_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED assume_does_not_throw_failed_tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_does_not_throw_failed_tests, test_result) {
  auto [output, result] = run_test_("assume_does_not_throw_failed_tests.*");
  assert_value_(0, result);
}
