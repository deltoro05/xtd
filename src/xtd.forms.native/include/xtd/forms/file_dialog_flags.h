/// @file
/// @brief Contains file dialog flags constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

#if !defined(OFN_READONLY)
/// @brief Causes the Read Only check box to be selected initially when the dialog box is created. This flag indicates the state of the Read Only check box when the dialog box is closed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_READONLY = 0x00000001;
/// @brief Causes the Save As dialog box to generate a message box if the selected file already exists. The user must confirm whether to overwrite the file.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_OVERWRITEPROMPT = 0x00000002;
/// @brief Hides the Read Only check box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_HIDEREADONLY = 0x00000004;
/// @brief Restores the current directory to its original value if the user changed the directory while searching for files.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_NOCHANGEDIR = 0x00000008;
/// @brief Causes the dialog box to display the Help button. The hwndOwner member must specify the window to receive the HELPMSGSTRING registered messages that the dialog box sends when the user clicks the Help button. An Explorer-style dialog box sends a CDN_HELP notification message to your hook procedure when the user clicks the Help button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_SHOWHELP = 0x00000010;
/// @brief Enables the hook function specified in the lpfnHook member.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_ENABLEHOOK = 0x00000020;
/// @brief The lpTemplateName member is a pointer to the name of a dialog template resource in the module identified by the hInstance member. If the OFN_EXPLORER flag is set, the system uses the specified template to create a dialog box that is a child of the default Explorer-style dialog box. If the OFN_EXPLORER flag is not set, the system uses the template to create an old-style dialog box that replaces the default dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_ENABLETEMPLATE = 0x00000040;
/// @brief The hInstance member identifies a data block that contains a preloaded dialog box template. The system ignores lpTemplateName if this flag is specified. If the OFN_EXPLORER flag is set, the system uses the specified template to create a dialog box that is a child of the default Explorer-style dialog box. If the OFN_EXPLORER flag is not set, the system uses the template to create an old-style dialog box that replaces the default dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_ENABLETEMPLATEHANDLE = 0x00000080;
/// @brief The common dialog boxes allow invalid characters in the returned file name. Typically, the calling application uses a hook procedure that checks the file name by using the FILEOKSTRING message. If the text box in the edit control is empty or contains nothing but spaces, the lists of files and directories are updated. If the text box in the edit control contains anything else, nFileOffset and nFileExtension are set to values generated by parsing the text. No default extension is added to the text, nor is text copied to the buffer specified by lpstrFileTitle. If the value specified by nFileOffset is less than zero, the file name is invalid. Otherwise, the file name is valid, and nFileExtension and nFileOffset can be used as if the OFN_NOVALIDATE flag had not been specified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_NOVALIDATE = 0x00000100;
/// @brief The File Name list box allows multiple selections. If you also set the OFN_EXPLORER flag, the dialog box uses the Explorer-style user interface; otherwise, it uses the old-style user interface.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_ALLOWMULTISELECT = 0x00000200;
/// @brief The user typed a file name extension that differs from the extension specified by lpstrDefExt. The function does not use this flag if lpstrDefExt is NULL.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_EXTENSIONDIFFERENT = 0x00000400;
/// @brief The user can type only valid paths and file names. If this flag is used and the user types an invalid path and file name in the File Name entry field, the dialog box function displays a warning in a message box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_PATHMUSTEXIST = 0x00000800;
/// @brief The user can type only names of existing files in the File Name entry field. If this flag is specified and the user enters an invalid name, the dialog box procedure displays a warning in a message box. If this flag is specified, the OFN_PATHMUSTEXIST flag is also used. This flag can be used in an Open dialog box. It cannot be used with a Save As dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_FILEMUSTEXIST = 0x00001000;
/// @brief If the user specifies a file that does not exist, this flag causes the dialog box to prompt the user for permission to create the file. If the user chooses to create the file, the dialog box closes and the function returns the specified name; otherwise, the dialog box remains open. If you use this flag with the OFN_ALLOWMULTISELECT flag, the dialog box allows the user to specify only one nonexistent file.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_CREATEPROMPT = 0x00002000;
/// @brief pecifies that if a call to the OpenFile function fails because of a network sharing violation, the error is ignored and the dialog box returns the selected file name. If this flag is not set, the dialog box notifies your hook procedure when a network sharing violation occurs for the file name specified by the user. If you set the OFN_EXPLORER flag, the dialog box sends the CDN_SHAREVIOLATION message to the hook procedure. If you do not set OFN_EXPLORER, the dialog box sends the SHAREVISTRING registered message to the hook procedure.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_SHAREAWARE = 0x00004000;
/// @brief The returned file does not have the Read Only check box selected and is not in a write-protected directory.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_NOREADONLYRETURN = 0x00008000;
/// @brief The file is not created before the dialog box is closed. This flag should be specified if the application saves the file on a create-nonmodify network share. When an application specifies this flag, the library does not check for write protection, a full disk, an open drive door, or network protection. Applications using this flag must perform file operations carefully, because a file cannot be reopened once it is closed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_NOTESTFILECREATE = 0x00010000;
/// @brief Hides and disables the Network button.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_NONETWORKBUTTON = 0x00020000;
/// @brief For old-style dialog boxes, this flag causes the dialog box to use short file names (8.3 format). Explorer-style dialog boxes ignore this flag and always display long file names.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_NOLONGNAMES = 0x00040000;
/// @brief Indicates that any customizations made to the Open or Save As dialog box use the Explorer-style customization methods.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_EXPLORER = 0x00080000;
/// @brief Directs the dialog box to return the path and file name of the selected shortcut (.LNK) file. If this value is not specified, the dialog box returns the path and file name of the file referenced by the shortcut.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_NODEREFERENCELINKS = 0x00100000;
/// @brief For old-style dialog boxes, this flag causes the dialog box to use long file names. If this flag is not specified, or if the OFN_ALLOWMULTISELECT flag is also set, old-style dialog boxes use short file names (8.3 format) for file names with spaces. Explorer-style dialog boxes ignore this flag and always display long file names.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_LONGNAMES = 0x00200000;
/// @brief Causes the dialog box to send CDN_INCLUDEITEM notification messages to your OFNHookProc hook procedure when the user opens a folder. The dialog box sends a notification for each item in the newly opened folder. These messages enable you to control which items the dialog box displays in the folder's item list.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_ENABLEINCLUDENOTIFY = 0x00400000;
/// @brief Enables the Explorer-style dialog box to be resized using either the mouse or the keyboard. By default, the Explorer-style Open and Save As dialog boxes allow the dialog box to be resized regardless of whether this flag is set. This flag is necessary only if you provide a hook procedure or custom template. The old-style dialog box does not permit resizing.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_ENABLESIZING = 0x00800000;
/// @brief Prevents the system from adding a link to the selected file in the file system directory that contains the user's most recently used documents. To retrieve the location of this directory, call the SHGetSpecialFolderLocation function with the CSIDL_RECENT flag.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_DONTADDTORECENT = 0x02000000;
/// @brief Forces the showing of system and hidden files, thus overriding the user setting to show or not show hidden files. However, a file that is marked both system and hidden is not shown.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_FORCESHOWHIDDEN = 0x10000000;
#endif
/// @brief Causes the dialog box to display the preview panel.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_SHOWPREVIEW = 0x40000000;
/// @brief Cause the dialog box automatically adds an extension to a file name if the user omits the extension.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native
/// @warning Internal use only
constexpr size_t OFN_ADDEXTENSION = 0x80000000;
