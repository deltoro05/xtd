/// @file
/// @brief Contains xtd::forms::item_check_event_handler eventt handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <xtd/event_handler.h>
#include "item_check_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the ItemCheck event of a CheckedListBox or ListView control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @param sender The source of the event.
    /// @param e An ItemCheckEventArgs that contains the event data.
    /// @remarks When you create an item_check_event_handler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate.
    template<typename type_t>
    using item_check_event_handler = delegate<void(type_t sender, item_check_event_args& e)>;
  }
}
