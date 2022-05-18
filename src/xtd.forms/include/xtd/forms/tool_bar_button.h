/// @file
/// @brief Contains xtd::forms::tool_bar_button container.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "component.h"
#include <xtd/event.h>
#include <xtd/event_handler.h>
#include <xtd/forms/image_list.h>
#include <xtd/forms/menu.h>
#include <xtd/forms/tool_bar_button_style.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class tool_bar;
    /// @endcond
    
    /// @brief Represents a toolbar button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms  menus_and_toolbars
    class tool_bar_button : public xtd::forms::component {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of xtd::forms::tool_bar_button class.
      tool_bar_button() = default;
      explicit tool_bar_button(const xtd::ustring& text);
      tool_bar_button(const xtd::ustring& text, const xtd::event_handler& on_click);
      explicit tool_bar_button(size_t image_index);
      tool_bar_button(size_t image_index, const xtd::event_handler& on_click);
      tool_bar_button(const xtd::ustring& text, size_t image_index);
      tool_bar_button(const xtd::ustring& text, size_t image_index, const xtd::event_handler& on_click);
      /// @}
      
      /// @cond
      template<typename delegate_type>
      tool_bar_button(const xtd::ustring& text, size_t image_index, delegate_type on_click) : tool_bar_button(text, image_index, xtd::event_handler(on_click)) {}
      /// @endcond
      
      /// @name Properties
      
      /// @{
      bool enabled() const;
      tool_bar_button& enabled(bool value);
      
      size_t image_index() const;
      tool_bar_button& image_index(size_t value);

      bool pushed() const;
      tool_bar_button& pushed(bool value);
      
      const xtd::ustring& text() const;
      tool_bar_button& text(const xtd::ustring& value);

      xtd::forms::tool_bar_button_style style() const;
      tool_bar_button& style(xtd::forms::tool_bar_button_style value);

      bool visible() const;
      tool_bar_button& visible(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Generates a click event for the xtd::forms::tool_bar_item.
      virtual void perform_click();
      /// @}
      
      /// @name Events
      
      /// @{
      xtd::event<tool_bar_button, xtd::event_handler> click;
      /// @}
      
    protected:
      /// @name protected methods
      
      /// @{
      void on_click(const xtd::event_args& e);
      /// @}
      
    private:
      friend xtd::forms::tool_bar;
      struct data {
        std::optional<std::reference_wrapper<xtd::forms::menu>> drop_down_menu_;
        bool enabled = true;
        size_t image_index = xtd::forms::image_list::image_collection::npos;
        xtd::drawing::image image_key;
        bool partial_push = false;
        bool pushed = false;
        xtd::drawing::rectangle rectangle;
        xtd::forms::tool_bar_button_style style = xtd::forms::tool_bar_button_style::push_button;
        std::any tag;
        xtd::ustring text;
        xtd::ustring tool_tip_text;
        bool visible = true;
        xtd::forms::tool_bar* parent = nullptr;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
    
    /// @brief Represents a xtd::forms::tool_bar_item reference.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using tool_bar_button_ref = std::reference_wrapper<tool_bar_button>;
  }
}
