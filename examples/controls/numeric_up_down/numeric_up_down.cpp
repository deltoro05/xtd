#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Numeric up down example");

      numeric_up_down1.location({80, 50});
      numeric_up_down1.value(50);
      numeric_up_down1.parent(*this);
      numeric_up_down1.value_changed +=[&] {
        label1.text(strings::format("value = {}", numeric_up_down1.value()));
      };
      
      numeric_up_down2.location({80, 100});
      numeric_up_down2.decimal_place(2);
      numeric_up_down2.increment(.01);
      numeric_up_down2.minimum(10.0);
      numeric_up_down2.maximum(11.0);
      numeric_up_down2.parent(*this);
      
      label1.location({80, 150});
      label1.parent(*this);
      label1.text(strings::format("value = {}", numeric_up_down1.value()));
    }
    
  private:
    label label1;
    numeric_up_down numeric_up_down1;
    numeric_up_down numeric_up_down2;
  };
}

int main() {
  application::run(examples::form1());
}
