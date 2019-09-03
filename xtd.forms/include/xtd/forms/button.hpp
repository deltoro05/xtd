#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class button : public control {
    public:
      button();

      /// @cond
      button(const button& value) {*this = value;}
      button& operator=(const button& value);
      /// @endcond

      drawing::size default_size() const override {return {75, 25};}

    protected:
      forms::create_params create_params() const override;

    private:
      struct data {
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
