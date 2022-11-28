/// @file
/// @brief Contains xtd::forms::font_picker control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "font_picker_event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available fonts along with controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html control_font_picker_w.png</td>
    ///     <td>@image html control_font_picker_m.png</td>
    ///     <td>@image html control_font_picker_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_font_picker_wd.png</td>
    ///     <td>@image html control_font_picker_md.png</td>
    ///     <td>@image html control_font_picker_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of font_picker picker.
    /// @include font_picker.cpp
    class forms_export_ font_picker : public control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the font_picker class.
      font_picker();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the color selected by the user.
      /// @return The color selected by the user. If a color is not selected, the default value is black.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      const drawing::color& color() const noexcept;
      /// @brief Sets the color selected by the user.
      /// @param color The color selected by the user. If a color is not selected.
      /// @brief This instance of control.
      /// @remarks The color selected by the user in the color picker at run time, as defined in color structure.
      control& color(const drawing::color& color);
      
      /// @brief Gets the selected font.
      /// @return The selected font.
      drawing::font font() const noexcept override;
      /// @brief Sets the selected font.
      /// @param font The selected font.
      /// @return Current control.
      control& font(const drawing::font& font) override;
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the font property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<font_picker, font_picker_event_handler> font_picker_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}

      /// @name Protected methods
      
      /// @{
      /// @brief Raises the font_changed event.
      /// @param e An event_args that contains the event data.
      void on_font_picker_changed(const font_picker_event_args& e);
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_command_control(message& message);
      void wm_command_control_selchange(message& message);
      struct data {
        drawing::color color;
        drawing::font font = xtd::drawing::system_fonts::default_font();
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
