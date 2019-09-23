#include <map>
#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/drawing/system_fonts.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/control.hpp>
#include "hdc_wrapper.hpp"
#include "wx_button.hpp"
#include "wx_check_box.hpp"
#include "wx_control.hpp"
#include "wx_form.hpp"
#include "wx_group_box.hpp"
#include "wx_label.hpp"
#include "wx_list_box.hpp"
#include "wx_panel.hpp"
#include "wx_progress_bar.hpp"
#include "wx_radio_button.hpp"
#include "wx_text_box.hpp"
#include "wx_track_bar.hpp"
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcscreen.h>
#include <wx/font.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

extern int32_t __mainloop_runnning__;

color control::back_color(intptr_t control) {
  if (control == 0) return color::empty;
  wxColour colour = reinterpret_cast<control_handler*>(control)->control()->GetBackgroundColour();
#if defined (__WXOSX__)
  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void control::back_color(intptr_t control, const color& color) {
  if (control == 0) return;
#if defined (__WXOSX__)
  if (color.handle())
    reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
}

intptr_t control::create(const forms::create_params& create_params) {
  application::initialize(); // Must be first
  if (create_params.class_name() == "button") return reinterpret_cast<intptr_t>(new wx_button(create_params));
  if (create_params.class_name() == "checkbox") return reinterpret_cast<intptr_t>(new wx_check_box(create_params));
  if (create_params.class_name() == "form") return reinterpret_cast<intptr_t>(new wx_form(create_params));
  if (create_params.class_name() == "groupbox") return reinterpret_cast<intptr_t>(new wx_group_box(create_params));
  if (create_params.class_name() == "label") return reinterpret_cast<intptr_t>(new wx_label(create_params));
  if (create_params.class_name() == "listbox") return reinterpret_cast<intptr_t>(new wx_list_box(create_params));
  if (create_params.class_name() == "panel") return reinterpret_cast<intptr_t>(new wx_panel(create_params));
  if (create_params.class_name() == "progressbar") return reinterpret_cast<intptr_t>(new wx_progress_bar(create_params));
  if (create_params.class_name() == "radiobutton") return reinterpret_cast<intptr_t>(new wx_radio_button(create_params));
  if (create_params.class_name() == "textbox") return reinterpret_cast<intptr_t>(new wx_text_box(create_params));
  if (create_params.class_name() == "trackbar") return reinterpret_cast<intptr_t>(new wx_track_bar(create_params));
  return reinterpret_cast<intptr_t>(new wx_control(create_params));
}

intptr_t control::create_paint_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper();
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else  hdc_wrapper->create<wxPaintDC>(reinterpret_cast<control_handler*>(control)->control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::create_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper();
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else  hdc_wrapper->create<wxClientDC>(reinterpret_cast<control_handler*>(control)->control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
  if (!control || handle == 0) return 0;
  return reinterpret_cast<control_handler*>(control)->call_def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
}

font control::default_font() {
  return system_fonts::default_font();
}

void control::destroy(intptr_t control) {
  if (control == 0) return;
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  if (wxTheApp) reinterpret_cast<control_handler*>(control)->destroy();
  delete reinterpret_cast<class control_handler*>(control);
}

void control::init() {
  application::initialize(); // Must be first
}

drawing::rectangle control::client_rectangle(intptr_t control) {
  if (control == 0) return {};
  wxRect rect = reinterpret_cast<control_handler*>(control)->control()->GetClientRect();
  return {rect.GetX(), rect.GetY(), rect.GetWidth(), rect.GetHeight()};
}

drawing::size control::client_size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::client_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetClientSize(size.width(), size.height());
}

void control::cursor(intptr_t control, intptr_t cursor) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetCursor(*reinterpret_cast<wxCursor*>(cursor));
}

bool control::enabled(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void control::enabled(intptr_t control, bool enabled) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

color control::fore_color(intptr_t control) {
  if (control == 0) return color::empty;
  wxColour colour = reinterpret_cast<control_handler*>(control)->control()->GetForegroundColour();
#if defined (__WXOSX__)
  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void control::fore_color(intptr_t control, const color& color) {
  if (control == 0) return;
#if defined (__WXOSX__)
  if (color.handle())
    reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
}

drawing::font control::font(intptr_t control) {
  return drawing::font::from_hfont(reinterpret_cast<intptr_t>(new wxFont(reinterpret_cast<control_handler*>(control)->control()->GetFont())));
}

void control::font(intptr_t control, const drawing::font& font) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetFont(*reinterpret_cast<wxFont*>(font.handle()));
}

point control::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  return {location.x, location.y};
}

void control::location(intptr_t control, const point& location) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetPosition({location.x(), location.y()});
}

void control::resume_drawing(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

drawing::size control::size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->SetSize(size.width(), size.height());
}

void control::suspend_drawing(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

string control::text(intptr_t control) {
  if (control == 0) return {};
  return reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString();
}

void control::text(intptr_t control, const string& text) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetLabel(text);
}

bool control::visible(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsShown();
}

void control::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Show(visible);
}

void control::refresh(intptr_t control) {
  if (control == 0) return;
  
  if (!reinterpret_cast<control_handler*>(control)->control()->IsBeingDeleted())
    reinterpret_cast<control_handler*>(control)->control()->Refresh();
}


void control::register_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc += wnd_proc;
}

void control::unregister_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc -= wnd_proc;
}

intptr_t control::send_message(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  if (hwnd == 0) return -1;
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}
