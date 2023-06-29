#include <xtd/tunit/assume.h>
#include <xtd/tunit/test_class_attribute.h>
#include <xtd/tunit/test_method_attribute.h>
#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <stdexcept>

namespace xtd::tunit::tests {
  class test_class_(assume_is_instance_of_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::invalid_argument e("invalid argument");
      xtd::tunit::assume::is_instance_of<std::bad_cast>(e);
    }
  };
}

void test_(assume_is_instance_of_failed_tests, test_output) {
  auto [output, result] = run_test_("assume_is_instance_of_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  ABORTED assume_is_instance_of_failed_tests.test_case_failed\n"
    "    Test aborted\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(assume_is_instance_of_failed_tests, test_result) {
  auto [output, result] = run_test_("assume_is_instance_of_failed_tests.*");
  assert_value_(0, result);
}
