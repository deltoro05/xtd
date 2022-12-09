#include <cmath>
#include <limits>
#include "../../../include/xtd/drawing/font.h"
#include "../../../include/xtd/drawing/graphics.h"
#include <xtd/argument_exception.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

font::font(const font& prototype, float em_size) {
  *data_ = *prototype.data_;
  data_->size_ = em_size;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(const font& prototype, float em_size, font_style style) {
  *data_ = *prototype.data_;
  data_->size_ = em_size;
  data_->style_ = style;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(const font& prototype, font_style style) {
  *data_ = *prototype.data_;
  data_->style_ = style;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(ustring family_name, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set, bool gdi_vertical_font) {
  if (em_size <= 0 || em_size == std::numeric_limits<float>::infinity() || std::isnan(em_size)) throw xtd::argument_exception("em_size is less than or equal to 0, evaluates to infinity, or is not a valid number."_t, current_stack_frame_);
  if (unit == graphics_unit::display) throw xtd::argument_exception("unit can't be equal to graphics_unit::display."_t, current_stack_frame_);
  try {
    data_->font_family_ = drawing::font_family(family_name);
  } catch (...) {
    data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  data_->original_font_name_ = data_->font_family_.name();
  data_->size_ = em_size;
  data_->style_ = style;
  data_->unit_ = unit;
  data_->gdi_char_set_ = gdi_char_set;
  data_->gdi_vertical_font_ = gdi_vertical_font;
  data_->handle_ = native::font::create(data_->original_font_name_, size_in_points(), (data_->style_ & font_style::bold) == font_style::bold, (data_->style_ & font_style::italic) == font_style::italic, (data_->style_ & font_style::underline) == font_style::underline, (data_->style_ & font_style::strikeout) == font_style::strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
}

font::font(intptr_t handle) {
  data_->handle_ = handle;
  ustring family_name;
  bool bold = false, italic = false, underline = false, strikeout = false;
  native::font::get_information(data_->handle_, family_name, data_->size_, bold, italic, underline, strikeout, data_->gdi_char_set_, data_->gdi_vertical_font_);
  try {
    data_->font_family_ = drawing::font_family(family_name);
  } catch (...) {
    data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  if (bold) data_->style_ |= font_style::bold;
  if (italic) data_->style_ |= font_style::italic;
  if (underline) data_->style_ |= font_style::underline;
  if (strikeout) data_->style_ |= font_style::strikeout;
  data_->original_font_name_ = family_name;
  data_->system_font_name_ = family_name;
  data_->is_system_font_ = true;
  data_->unit_ = graphics_unit::point;
}

font::font(const font& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font::destroy(data_->handle_);
  data_ = value.data_;
}

font::font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set, bool gdi_vertical_font) : font(font_family.name(), em_size, style, unit, gdi_char_set, gdi_vertical_font) {
}

font::font(xtd::ustring family_name, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set) : font(family_name, em_size, style, unit, gdi_char_set, false) {
}

font::font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit, uint8_t gdi_char_set) : font(font_family, em_size, style, unit, gdi_char_set, false) {
}

font::font(xtd::ustring family_name, float em_size, font_style style, graphics_unit unit) : font(family_name, em_size, style, unit, 0, false) {
}

font::font(const drawing::font_family& font_family, float em_size, font_style style, graphics_unit unit) : font(font_family, em_size, style, unit, 0, false) {
}

font::font(xtd::ustring family_name, float em_size, font_style style) : font(family_name, em_size, style, graphics_unit::point, 0, false) {
}

font::font(const drawing::font_family& font_family, float em_size, font_style style) : font(font_family, em_size, style, graphics_unit::point, 0, false) {
}

font::font(xtd::ustring family_name, float em_size, graphics_unit unit) : font(family_name, em_size, font_style::regular, unit, 0, false) {
}

font::font(const drawing::font_family& font_family, float em_size, graphics_unit unit) : font(font_family, em_size, font_style::regular, unit, 0, false) {
}

font::font(xtd::ustring family_name, float em_size) : font(family_name, em_size, font_style::regular, graphics_unit::point, 0, false) {
}

font::font(const drawing::font_family& font_family, float em_size) : font(font_family, em_size, font_style::regular, graphics_unit::point, 0, false) {
}

font& font::operator =(const font& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

font::~font() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font::destroy(data_->handle_);
}

bool font::bold() const noexcept {
  return (data_->style_ & font_style::bold) == font_style::bold;
}

drawing::font_family font::font_family() const noexcept {
  return data_->font_family_;
}

uint8_t font::gdi_char_set() const noexcept {
  return data_->gdi_char_set_;
}

bool font::gdi_vertical_font() const noexcept {
  return data_->gdi_vertical_font_;
}

intptr_t font::handle() const noexcept {
  return data_->handle_;
}

int32_t font::height() const noexcept {
  return static_cast<int32_t>(std::ceil(get_height()));
}

bool font::is_system_font() const noexcept {
  return data_->is_system_font_;
}

bool font::italic() const noexcept {
  return (data_->style_ & font_style::italic) == font_style::italic;
}

const xtd::ustring& font::name() const noexcept {
  return data_->font_family_.name();
}

const xtd::ustring& font::original_font_name() const noexcept {
  return data_->original_font_name_;
}

float font::size() const noexcept {
  return data_->size_;
}

float font::size_in_points() const noexcept {
  switch (data_->unit_) {
    case graphics_unit::world:
    case graphics_unit::display:
    case graphics_unit::pixel: return data_->size_ / 96.0f * native::font::dpi();
    case graphics_unit::point: return data_->size_;
    case graphics_unit::inch: return data_->size_ * native::font::dpi();
    case graphics_unit::document: return data_->size_ / 300.0f * native::font::dpi();
    case graphics_unit::millimeter: return data_->size_ / 25.4f * native::font::dpi();
    default: return data_->size_;
  }
}

bool font::strikeout() const noexcept {
  return (data_->style_ & font_style::strikeout) == font_style::strikeout;
}

font_style font::style() const noexcept {
  return data_->style_;
}

bool font::underline() const noexcept {
  return (data_->style_ & font_style::underline) == font_style::underline;
}

graphics_unit font::unit() const noexcept {
  return data_->unit_;
}

bool font::equals(const font& value) const noexcept {
  return data_->font_family_ == value.data_->font_family_ && data_->gdi_char_set_ == value.data_->gdi_char_set_ && data_->gdi_vertical_font_ == value.data_->gdi_vertical_font_ && data_->style_ == value.data_->style_ && data_->size_ == value.data_->size_ && data_->unit_ == value.data_->unit_;
}

font font::from_hdc(const intptr_t hdc) {
  font font;
  font.data_->handle_ = native::font::create_from_hdc(hdc);
  ustring family_name;
  bool bold = false, italic = false, underline = false, strikeout = false;
  native::font::get_information(font.data_->handle_, family_name, font.data_->size_, bold, italic, underline, strikeout, font.data_->gdi_char_set_, font.data_->gdi_vertical_font_);
  try {
    font.data_->font_family_ = drawing::font_family(family_name);
  } catch (...) {
    font.data_->font_family_ = drawing::font_family::generic_sans_serif();
  }
  if (bold) font.data_->style_ |= font_style::bold;
  if (italic) font.data_->style_ |= font_style::italic;
  if (underline) font.data_->style_ |= font_style::underline;
  if (strikeout) font.data_->style_ |= font_style::strikeout;
  font.data_->original_font_name_ = family_name;
  font.data_->is_system_font_ = true;
  font.data_->unit_ = graphics_unit::point;
  return font;
}

font font::from_hfont(const intptr_t hfont) {
  return font(native::font::create_from_hfont(hfont));
}

float font::get_height() const {
  return native::font::height(data_->handle_);
}

float font::get_height(const graphics& graphics) const {
  return native::font::height(data_->handle_, graphics.data_->handle);
}

float font::get_height(float dpi) const {
  //return native::font::height(data_->handle_,dpi);
  if (data_->unit_ == graphics_unit::pixel) return get_height();
  return get_height() / native::font::dpi() * dpi;
}

intptr_t font::to_hfont() const {
  return native::font::create_from_hfont(data_->handle_);
}

xtd::ustring font::to_string() const noexcept {
  return ustring::format("[{}: name={}, size={}, units={}, gdi_char_set={}, gdi_vertical_font={}]", ustring::class_name(*this), data_->font_family_.name(), data_->size_, (int32_t)data_->unit_, data_->gdi_char_set_, data_->gdi_vertical_font_);
}
