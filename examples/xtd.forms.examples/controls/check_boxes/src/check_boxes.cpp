#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  auto main_form = form::create("Check boxes example");
  auto font_group_box = control::create<group_box>(main_form, system_texts::font(), {10, 10}, {150, 180});
  auto bold_check_box = check_boxes::bold(font_group_box, false, check_state::unchecked, {20, 20});
  auto italic_check_box = check_boxes::italic(font_group_box, false, check_state::unchecked, {20, 50});
  auto underline_check_box = check_boxes::underline(font_group_box, false, check_state::unchecked, {20, 80});
  auto strikeout_check_box = check_boxes::strikeout(font_group_box, false, check_state::unchecked, {20, 110});
  application::run(main_form);
}
