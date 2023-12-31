/// @file
/// @brief Contains xtd::forms::control_event_handler event handler.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control_event_args.h"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the xtd::forms::control::control_added and xtd::forms::control::control_removed events of the control class.
    /// @param sender The source of the event.
    /// @param e A control_event_args that contains the event data.
    /// @par Header
    /// @code #include <xtd/forms/control_event_handler> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks When you create a control_event_args delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate.
    using control_event_handler = delegate<void(object& sender, const control_event_args& e)>;
  }
}
