#include <xtd/tunit>
#include <iostream>

using namespace xtd::tunit;
using namespace std;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
  public:
    // This is the method that is called 1 time before test class run.
    static void class_initialize_(class_initialize) {
    }
    
    // This is the method that is called 1 time after test class run.
    static void class_cleanup_(class_cleanup) {
    }
    
    // This is the method that is called before any tests in a fixture are run.
    static void test_initialize_(test_initialize) {
    }
    
    // This is the method that is called after any tests in a fixture are run.
    static void test_cleanup_(test_cleanup) {
    }
    
    void test_method_(test_case1) {
    }
    
    void test_method_(test_case2) {
    }
    
    void ignore_test_method_(test_case3) {
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
