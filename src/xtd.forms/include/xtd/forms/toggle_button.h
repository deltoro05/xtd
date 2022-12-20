/// @file
/// @brief Contains xtd::forms::toggle_button control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "button_base.h"
#include "check_state.h"
#include "visual_styles/toggle_button_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows toggle_button.
    /// @code
    /// class forms_export_ toggle_button : public xtd::forms::button_base
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::toggle_button
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks Use a toggle_button to give the user an option, such as true/false or yes/no. The toggle_button control can display an image or text or both.
    /// @remarks toggle_button and radio_button controls have a similar function: they allow the user to choose from a list of options. toggle_button controls let the user pick a combination of options. In contrast, radio_button controls allow a user to choose from mutually exclusive options.
    /// @remarks The appearance property determines whether the toggle_button appears as a typical toggle_button or as a button.
    /// @remarks The three_state property determines whether the control supports two or three states. Use the checked property to get or set the value of a two-state toggle_button control and use the check_state property to get or set the value of a three-state toggle_button control.
    /// @note If the three_state property is set to true, the checked property will return true for either a checked or indeterminate state.
    /// @remarks The flat_style property determines the style and appearance of the control. If the flat_style property is set to flat_style::system, the user's operating system determines the appearance of the control.
    /// @note When the flat_style property is set to flat_style::system, the check_align property is ignored and the control is displayed using the content_alignment::middle_left or content_alignment::middle_right alignment. If the check_align property is set to one of the right alignments, the control is displayed using the content_alignment::middle_right alignment; otherwise, it is displayed using the content_alignment::middle_left alignment.
    /// @remarks The following describes an indeterminate state: You have a toggle_button that determines if the selected text in a rich_text_box is bold. When you select text you can click the toggle_button to bold the selection. Likewise, when you select some text, the toggle_button displays whether the selected text is bold. If your selected text contains text that is bold and normal, the toggle_button will have an indeterminate state.
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
    ///     <td>@image html control_toggle_button_w.png</td>
    ///     <td>@image html control_toggle_button_m.png</td>
    ///     <td>@image html control_toggle_button_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html control_toggle_button_wd.png</td>
    ///     <td>@image html control_toggle_button_md.png</td>
    ///     <td>@image html control_toggle_button_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of toggle_button control.
    /// @include toggle_button.cpp
    class forms_export_ toggle_button : public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the CheckBox class.
      /// @remarks By default, when a new toggle_button is instantiated, auto_check is set to true, checked is set to false, and appearance is set to normal.
      toggle_button();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the checked or check_state values and the toggle_button's appearance are automatically changed when the toggle_button is clicked.
      /// @return true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      virtual bool auto_check() const noexcept;
      /// @brief Sets a value indicating whether the checked or check_state values and the toggle_button's appearance are automatically changed when the toggle_button is clicked.
      /// @param auto_check true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      virtual toggle_button& auto_check(bool auto_check);
      
      /// @brief Gets the horizontal and vertical alignment of the check mark on a toggle_button control.
      /// @return One of the content_alignment values. The default value is middle_left.
      virtual content_alignment check_align() const noexcept;
      /// @brief Sets the horizontal and vertical alignment of the check mark on a toggle_button control.
      /// @param check_align One of the content_alignment values. The default value is middle_left.
      virtual toggle_button& check_align(content_alignment check_align);
      
      /// @brief Gets a value indicating whether the toggle_button is in the checked state.
      /// @return true if the toggle_button is in the checked state; otherwise, false. The default value is false. If the three_state property is set to true, the checked property will return true for either a checked or indeterminate check_state.
      /// @remarks When the value is true, the toggle_button portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is true and raised like a standard button when false.
      virtual bool checked() const noexcept;
      /// @brief Sets a value indicating whether the toggle_button is in the checked state.
      /// @param checked true if the toggle_button is in the checked state; otherwise, false. The default value is false.
      /// @remarks When the value is true, the toggle_button portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is true and raised like a standard button when false.
      virtual toggle_button& checked(bool checked);
      
      /// @brief Gets the state of the toggle_button.
      /// @return One of the check_state enumeration values. The default value is unchecked.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to check_state::Indeterminate in code and not by u ser interaction.
      /// @remarks The following table describes the xtd::forms::appearance of the toggle_button control in its different states for the normal and button style control toggle_button::appearance.
      /// | Check_state   |  appearance::normal                               | appearance::button          |
      /// |---------------|---------------------------------------------------|-----------------------------|
      /// | checked       | The toggle_button displays a check mark.          | The control appears sunken. |
      /// | unchecked     | The CheckBox is empty.                            | The control appears raised. |
      /// | indeterminate | The CheckBox displays a check mark and is shaded. | The control appears flat.   |
      virtual forms::check_state check_state() const noexcept;
      /// @brief Sets the state of the toggle_button.
      /// @param chexk_state One of the check_state enumeration values. The default value is unchecked.
      /// @remarks The following table describes the xtd::forms::appearance of the toggle_button control in its different states for the normal and button style control toggle_button::appearance.
      /// | Check_state   |  appearance::normal                               | appearance::button          |
      /// |---------------|---------------------------------------------------|-----------------------------|
      /// | checked       | The toggle_button displays a check mark.          | The control appears sunken. |
      /// | unchecked     | The CheckBox is empty.                            | The control appears raised. |
      /// | indeterminate | The CheckBox displays a check mark and is shaded. | The control appears flat.   |
      virtual toggle_button& check_state(forms::check_state check_state);
      
      /// @brief Gets a value indicating whether the toggle_button will allow three check states rather than two.
      /// @return true if the toggle_button is able to display three check states; otherwise, false. The default value is false.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      virtual bool three_state() const noexcept;
      /// @brief Gets a value indicating whether the toggle_button will allow three check states rather than two.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false. The default value is false.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      virtual toggle_button& three_state(bool three_state);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the checked property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/handle_and_raise_events.md">Handling and Raising Events</a>.
      event<toggle_button, event_handler> checked_changed;
      
      /// @brief Occurs when the value of the check_state property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/handle_and_raise_events.md">Handling and Raising Events</a>.
      event<toggle_button, event_handler> check_state_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const noexcept override;
      /// @}

      /// @name Protected methods
      
      /// @{
      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This metod is not relevant for this class.
      drawing::size measure_control() const noexcept override;
      
      /// @brief Raises the toggle_button::checked_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_checked_changed(const event_args& e);
      
      /// @brief Raises the toggle_button::check_state_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_check_state_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_check_state_changed(const event_args& e);
      
      void on_enabled_changed(const event_args& e) override;
      
      /// @brief Raises the handle_created event.
      /// @param e An event_args that contains the event data.
      void on_handle_created(const event_args& e) override;
      
      void on_mouse_down(const mouse_event_args& e) override;
      void on_mouse_enter(const event_args& e) override;
      void on_mouse_leave(const event_args& e) override;
      void on_mouse_up(const mouse_event_args& e) override;
      void on_paint(paint_event_args& e) override;
      
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::toggle_button_state values.
      xtd::forms::visual_styles::toggle_button_state state() const noexcept;

      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_mouse_double_click(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_up(message& message);

      std::shared_ptr<data> data_;
    };
  }
}
