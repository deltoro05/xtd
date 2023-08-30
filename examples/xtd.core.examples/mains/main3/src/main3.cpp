#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace std;
using namespace xtd;

namespace main3_example {
  class program {
  public:
    static void main(const vector<ustring>& args) {
      // Write arguments to the console output
      for (auto arg : args)
        console::write_line(arg);
        
      // return 42
      environment::exit_code(42);
    }
  };
}

startup_(main3_example::program);
// Is the same as :
//
// auto main(int argc, char* argv[])->int {
//   return startup::safe_run(main3_example::program::main, argc, argv);
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
