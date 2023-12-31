/// @file
/// @brief Contains xtd::argument_null_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "argument_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when one of the arguments provided to a method is null.
  /// @par Header
  /// @code #include <xtd/argument_null_exception> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an argument_null_exception.
  /// @include argument_null_exception.cpp
  class argument_null_exception : public argument_exception {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Create a new instance of class argument_null_exception
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_null_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(default_message(), info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::ustring& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::ustring& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, error, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::ustring& message, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, help_link, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit argument_null_exception(const xtd::ustring& message, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_null_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    argument_null_exception(const argument_null_exception&) = default;
    argument_null_exception& operator =(const argument_null_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "Value cannot be null."_t;}
  };
}

/// @brief Helper on xtd::argument_null_exception to call it with current stack frame information.
/// @par Header
/// @code #include <xtd/argument_null_exception> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core exceptions
/// @remarks Is equivalent to xtd::argument_null_exception {{any argument}, csf_}
/// @code
/// void my_func() {
///   if (invalid_info) throw argument_null_exception_(); // same as : throw argument_null_exception {csf_};
///   if (invalid_value) throw argument_null_exception_("Bad value"); // same as : throw argument_null_exception {"Bad value", csf_};
///   ...
/// }
/// @endcode
#define argument_null_exception_(...) argument_null_exception(add_csf_(__VA_ARGS__))
