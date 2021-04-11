/// @file
/// @brief Contains xtd::forms::native::picture_box API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/image.h>
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains picture_box native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ picture_box final static_ {
      public:
        /// @brief Sets the image that is displayed by picture_box.
        /// @param control Control window handle.
        /// @param image The xtd::drawing::image to display.
        /// @warning Internal use only
        static void image(intptr_t control, const drawing::image& image);
        /// @brief Reset the image that is displayed by picture_box.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void reset(intptr_t control);
      };
    }
  }
}
