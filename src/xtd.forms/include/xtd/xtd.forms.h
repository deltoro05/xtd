/// @file
/// @brief Contains  xtd.forms library headers.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

/// @defgroup application application
/// @brief application definitions.

/// @defgroup components components
/// @brief Components are objects that an application uses in conjunction with another window.

/// @defgroup containers containers
/// @brief Containers are  container for other controls.

/// @defgroup controls  controls
/// @brief Controls are childs windows that an application uses in conjunction with another window to enable interaction with the user.

/// @defgroup dialogs dialogs
/// @brief Common  dialogs consist of the open file, save file, open folder, find and replace, print, page setup, font, color dialog boxes, about, busy, message dialog boxes.

/// @defgroup events events
/// @brief events are event args and event handler needed to response to window messages.

/// @defgroup menus_and_toolbars   menus and toolbars
/// @brief  menus and toolbars definitions.

/// @defgroup xtd_forms xtd.forms
/// @brief The xtd.foms library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.

#include <xtd/xtd.core>
#include <xtd/xtd.drawing>
#include <xtd/forms/create_params.h>
#include <xtd/forms/window_messages.h>

#include "xtd/forms/layout/arranged_element_collection.h"
#include "xtd/forms/layout/sorter_none.h"
#include "xtd/forms/properties/resources.h"
#include "xtd/forms/about_box.h"
#include "xtd/forms/about_dialog.h"
#include "xtd/forms/busy_box.h"
#include "xtd/forms/busy_dialog.h"
#include "xtd/forms/dialog_style.h"
#include "xtd/forms/anchor_styles.h"
#include "xtd/forms/appearance.h"
#include "xtd/forms/application.h"
#include "xtd/forms/application_context.h"
#include "xtd/forms/application_informations.h"
#include "xtd/forms/arrange_direction.h"
#include "xtd/forms/arrange_starting_position.h"
#include "xtd/forms/auto_size_mode.h"
#include "xtd/forms/background_worker.h"
#include "xtd/forms/boot_mode.h"
#include "xtd/forms/border_style.h"
#include "xtd/forms/bounds_specified.h"
#include "xtd/forms/button.h"
#include "xtd/forms/button_base.h"
#include "xtd/forms/button_images.h"
#include "xtd/forms/button_renderer.h"
#include "xtd/forms/buttons.h"
#include "xtd/forms/cancel_event_args.h"
#include "xtd/forms/cancel_event_handler.h"
#include "xtd/forms/character_casing.h"
#include "xtd/forms/check_box.h"
#include "xtd/forms/check_box_renderer.h"
#include "xtd/forms/check_boxes.h"
#include "xtd/forms/check_state.h"
#include "xtd/forms/checked_list_box.h"
#include "xtd/forms/choice.h"
#include "xtd/forms/close_reason.h"
#include "xtd/forms/collapsible_panel.h"
#include "xtd/forms/color_box.h"
#include "xtd/forms/color_box_styles.h"
#include "xtd/forms/color_dialog.h"
#include "xtd/forms/color_picker.h"
#include "xtd/forms/combo_box.h"
#include "xtd/forms/combo_box_style.h"
#include "xtd/forms/command_link_button.h"
#include "xtd/forms/common_dialog.h"
#include "xtd/forms/common_dialog_closed_event_args.h"
#include "xtd/forms/common_dialog_closed_event_handler.h"
#include "xtd/forms/component.h"
#include "xtd/forms/container_control.h"
#include "xtd/forms/content_alignment.h"
#include "xtd/forms/control.h"
#include "xtd/forms/control_event_args.h"
#include "xtd/forms/control_event_handler.h"
#include "xtd/forms/control_paint.h"
#include "xtd/forms/control_styles.h"
#include "xtd/forms/control_trace_listener.h"
#include "xtd/forms/countries.h"
#include "xtd/forms/country.h"
#include "xtd/forms/cursor.h"
#include "xtd/forms/cursors.h"
#include "xtd/forms/date_time_picker.h"
#include "xtd/forms/debug_form.h"
#include "xtd/forms/dialog_result.h"
#include "xtd/forms/do_work_event_args.h"
#include "xtd/forms/do_work_event_handler.h"
#include "xtd/forms/dock_style.h"
#include "xtd/forms/domain_up_down.h"
#include "xtd/forms/dot_matrix_display.h"
#include "xtd/forms/dot_matrix_style.h"
#include "xtd/forms/emoticon.h"
#include "xtd/forms/emoticons.h"
#include "xtd/forms/enable_debug.h"
#include "xtd/forms/exception_dialog.h"
#include "xtd/forms/flat_style.h"
#include "xtd/forms/folder_browser_dialog.h"
#include "xtd/forms/font_dialog.h"
#include "xtd/forms/font_picker.h"
#include "xtd/forms/form.h"
#include "xtd/forms/form_border_style.h"
#include "xtd/forms/form_button_images.h"
#include "xtd/forms/form_closed_event_args.h"
#include "xtd/forms/form_closed_event_handler.h"
#include "xtd/forms/form_closing_event_args.h"
#include "xtd/forms/form_closing_event_handler.h"
#include "xtd/forms/form_start_position.h"
#include "xtd/forms/form_window_state.h"
#include "xtd/forms/fourteen_segment_display.h"
#include "xtd/forms/group_box.h"
#include "xtd/forms/help_event_args.h"
#include "xtd/forms/help_event_handler.h"
#include "xtd/forms/ibutton_control.h"
#include "xtd/forms/icontrol_trace.h"
#include "xtd/forms/image_list.h"
#include "xtd/forms/imessage_filter.h"
#include "xtd/forms/input_box.h"
#include "xtd/forms/input_box_style.h"
#include "xtd/forms/input_dialog.h"
#include "xtd/forms/item_check_event_args.h"
#include "xtd/forms/item_check_event_handler.h"
#include "xtd/forms/iwin32_window.h"
#include "xtd/forms/key_event_args.h"
#include "xtd/forms/key_event_handler.h"
#include "xtd/forms/key_press_event_args.h"
#include "xtd/forms/key_press_event_handler.h"
#include "xtd/forms/keys.h"
#include "xtd/forms/known_themed_color.h"
#include "xtd/forms/label.h"
#include "xtd/forms/lcd_label.h"
#include "xtd/forms/list_box.h"
#include "xtd/forms/list_control.h"
#include "xtd/forms/main_menu.h"
#include "xtd/forms/menu.h"
#include "xtd/forms/menu_item.h"
#include "xtd/forms/menu_item_kind.h"
#include "xtd/forms/menu_images.h"
#include "xtd/forms/message.h"
#include "xtd/forms/message_box.h"
#include "xtd/forms/message_box_buttons.h"
#include "xtd/forms/message_box_default_button.h"
#include "xtd/forms/message_box_icon.h"
#include "xtd/forms/message_box_options.h"
#include "xtd/forms/message_dialog.h"
#include "xtd/forms/message_dialog_buttons.h"
#include "xtd/forms/message_dialog_default_button.h"
#include "xtd/forms/message_dialog_icon.h"
#include "xtd/forms/message_dialog_options.h"
#include "xtd/forms/message_loop_callback.h"
#include "xtd/forms/mouse_buttons.h"
#include "xtd/forms/mouse_event_args.h"
#include "xtd/forms/mouse_event_handler.h"
#include "xtd/forms/nine_segment_display.h"
#include "xtd/forms/numeric_up_down.h"
#include "xtd/forms/open_file_dialog.h"
#include "xtd/forms/orientation.h"
#include "xtd/forms/paint_event_args.h"
#include "xtd/forms/paint_event_handler.h"
#include "xtd/forms/panel.h"
#include "xtd/forms/picture_box.h"
#include "xtd/forms/progress_bar.h"
#include "xtd/forms/progress_bar_style.h"
#include "xtd/forms/progress_changed_event_args.h"
#include "xtd/forms/progress_changed_event_handler.h"
#include "xtd/forms/progress_dialog.h"
#include "xtd/forms/radio_button.h"
#include "xtd/forms/radio_button_renderer.h"
#include "xtd/forms/radio_buttons.h"
#include "xtd/forms/renderer.h"
#include "xtd/forms/run_worker_completed_event_args.h"
#include "xtd/forms/run_worker_completed_event_handler.h"
#include "xtd/forms/save_file_dialog.h"
#include "xtd/forms/screen.h"
#include "xtd/forms/scroll_bar.h"
#include "xtd/forms/scrollable_control.h"
#include "xtd/forms/selection_mode.h"
#include "xtd/forms/segment_style.h"
#include "xtd/forms/segments.h"
#include "xtd/forms/settings.h"
#include "xtd/forms/seven_segment_display.h"
#include "xtd/forms/shortcut.h"
#include "xtd/forms/sixteen_segment_display.h"
#include "xtd/forms/split_container.h"
#include "xtd/forms/splitter.h"
#include "xtd/forms/splitter_panel.h"
#include "xtd/forms/splitter_style.h"
#include "xtd/forms/switch_button.h"
#include "xtd/forms/system_information.h"
#include "xtd/forms/tab_control.h"
#include "xtd/forms/tab_page.h"
#include "xtd/forms/text_box.h"
#include "xtd/forms/text_box_base.h"
#include "xtd/forms/text_format_flags.h"
#include "xtd/forms/texts.h"
#include "xtd/forms/theme.h"
#include "xtd/forms/theme_base.h"
#include "xtd/forms/theme_colors.h"
#include "xtd/forms/theme_images.h"
#include "xtd/forms/theme_style.h"
#include "xtd/forms/toggle_button.h"
#include "xtd/forms/toggle_buttons.h"
#include "xtd/forms/tool_bar_images.h"
#include "xtd/forms/tick_style.h"
#include "xtd/forms/timer.h"
#include "xtd/forms/trace_form.h"
#include "xtd/forms/track_bar.h"
#include "xtd/forms/up_down_base.h"
#include "xtd/forms/up_down_button.h"
#include "xtd/forms/user_control.h"
#include "xtd/forms/use_wait_cursor.h"
#include "xtd/forms/visual_styles/check_box_state.h"
#include "xtd/forms/visual_styles/push_button_state.h"
#include "xtd/forms/visual_styles/radio_button_state.h"
