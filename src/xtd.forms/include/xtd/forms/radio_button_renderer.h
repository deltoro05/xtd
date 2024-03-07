/// @file
/// @brief Contains xtd::forms::radio_button_renderer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/radio_button_state.h"
#include "../forms_export.h"
#include "text_format_flags.h"
#include "application.h"
#include <xtd/optional>
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/graphics>
#include <xtd/drawing/image>
#include <xtd/drawing/rectangle>
#include <xtd/drawing/system_fonts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides radio button renderer methods.
    /// @par Header
    /// @code #include <xtd/forms/radio_button_renderer> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ radio_button_renderer final static_ {
    public:
      /// @name Static methods
      
      /// @{
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::radio_button_state& state) {draw_radio_button(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::radio_button_state& state) {draw_radio_button(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(default_theme(), g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(default_theme(), g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(default_theme(), g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(default_theme(), g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(default_theme(), g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {draw_radio_button(default_theme(), g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::radio_button_state& state) {draw_radio_button(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::radio_button_state& state) {draw_radio_button(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(theme, g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(theme, g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(theme, g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(theme, g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_radio_button(theme, g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_radio_button(const xtd::ustring& theme, xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::radio_button_state& state) {draw_flat_radio_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::radio_button_state& state) {draw_flat_radio_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_flat_radio_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_flat_radio_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_flat_radio_button(g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_flat_radio_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_flat_radio_button(g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_flat_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::radio_button_state& state) {draw_popup_radio_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, bool focused, xtd::forms::visual_styles::radio_button_state& state) {draw_popup_radio_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), true, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_popup_radio_button(g, bounds, "", xtd::drawing::system_fonts::default_font(), xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_popup_radio_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_popup_radio_button(g, bounds, text, font, flags, xtd::drawing::image::empty, xtd::drawing::rectangle(0, 0, 0, 0), false, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_popup_radio_button(g, bounds, text, font, xtd::forms::text_format_flags::default_format, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state) {draw_popup_radio_button(g, bounds, text, font, flags, image, image_bounds, focused, state, application::style_sheet().system_colors().control(), application::style_sheet().system_colors().control_text());}
      static void draw_popup_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      /// @}
      
    private:
      static xtd::ustring default_theme() {return application::style_sheet().theme().name();}
      static void draw_radio_button_kde(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_kde_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_kde_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_gnome(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_gnome_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_gnome_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_macos(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_macos_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_macos_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_symbolic(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_symbolic_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_symbolic_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_windows(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_windows_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_windows_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_xtd(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_xtd_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_radio_button_xtd_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_flat_radio_button_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_flat_radio_button_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_popup_radio_button_dark(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
      static void draw_popup_radio_button_light(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color);
    };
  }
}
