#include <xtd/xtd>

using namespace xtd;

enum_class_(enum_test, {
  value_one,
  value_two,
  value_three,
  value_four
});

int main() {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_int32());
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write("entries = [");
  for (auto entry : enum_object<>::get_entries<enum_test>()) {
    static auto index = 0;
    console::write("{}({}, {})", index++ == 0 ? "" : ", ", as<int>(entry.first), entry.second);
  }
  console::write_line("]");
}
