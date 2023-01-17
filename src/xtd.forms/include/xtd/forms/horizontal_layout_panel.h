/// @file
/// @brief Contains xtd::forms::horizontal_layout_panel container.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "horizontal_control_layout_style_collection.h"
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Used to group collections of horizontally aligned controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
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
    ///     <td>@image html containers_horizontal_layout_panel_w.png</td>
    ///     <td>@image html containers_horizontal_layout_panel_m.png</td>
    ///     <td>@image html containers_horizontal_layout_panel_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <td>Dark</td>
    ///     <td>@image html containers_horizontal_layout_panel_wd.png</td>
    ///     <td>@image html containers_horizontal_layout_panel_md.png</td>
    ///     <td>@image html containers_horizontal_layout_panel_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrates the use of horizontal_layout_panel container.
    /// @include horizontal_layout_panel.cpp
    class horizontal_layout_panel : public panel {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialises a new instance of horizontal layout panel class.
      horizontal_layout_panel() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets horizontal control layout style for all child controls.
      /// @return The horizontal control layout style collection.
      const horizontal_control_layout_style_collection& control_layout_styles() const noexcept;
      
      /// @brief Gets horizontal control layout style for specified child controls.
      /// @param control The control to get horizontal control layout style.
      /// @return The horizontal control layout style for the specified control.
      /// @exception xtd::argument_exception container does not contains control.
      const horizontal_control_layout_style& control_layout_style(const control_ref& control) const;
      /// @brief Sets horizontal control layout style for specified child controls.
      /// @param control The control to get horizontal control layout style.
      /// @param value The horizontal control layout style for the specified control.
      /// @exception xtd::argument_exception container does not contains control.
      horizontal_layout_panel& control_layout_style(const control_ref& control, const horizontal_control_layout_style& value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::horizontal_layout_panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::horizontal_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::horizontal_layout_panel.
      /// @param name The name of the xtd::forms::horizontal_layout_panel.
      /// @return New xtd::forms::horizontal_layout_panel created.
      static horizontal_layout_panel create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::horizontal_layout_panel with specified parent, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::horizontal_layout_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::horizontal_layout_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::horizontal_layout_panel.
      /// @param name The name of the xtd::forms::horizontal_layout_panel.
      /// @return New xtd::forms::horizontal_layout_panel created.
      static horizontal_layout_panel create(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      void on_control_added(const xtd::forms::control_event_args& e) override;
      void on_control_removed(const xtd::forms::control_event_args& e) override;
      void on_layout(const xtd::event_args& e) override;
      /// @}
      
    private:
      horizontal_control_layout_style_collection control_layout_styles_;
    };
  }
}
