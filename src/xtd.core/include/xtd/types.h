/// @file
/// @brief Contains xtd fundamental types.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <string>
#include <typeinfo>
#include "core_export.h"
/// @cond
#define __XTD_CORE_CHAR8_T_INTERNAL__
#include "internal/__char8_t.h"
#undef __XTD_CORE_CHAR8_T_INTERNAL__
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  using byte_t = uint_least8_t;
  using char_t = char;
  using decimal_t = long double;
  using sbyte_t = int_least8_t;
  using single_t = float;
  using uchar_t = unsigned char;
  using ushort_t = unsigned short;
  using uint_t = unsigned int;
  using ulong_t = unsigned long;

  #if defined(__linux__) && defined(_LP64)
  using llong_t = long long int;
  using ullong_t = unsigned long long int;
  #else
  using llong_t = long;
  using ullong_t = unsigned long;
  #endif
  /// @endcond
  
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using byte = uint_least8_t;
  
  /// @brief Represents a 16-bit unicode character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using char8 = char8_t;
  
  /// @brief Represents a 8-bit unicode character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using char16 = char16_t;
  
  /// @brief Represents a 32-bit unicode character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using char32 = char32_t;
  
  /// @brief Represents a decimal-precision floating-point number.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using decimal = decimal_t;
  
  /// @brief Represents a 16-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using int16 = int_least16_t;
  
  /// @brief Represents a 32-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using int32 = int_least32_t;
  
  /// @brief Represents a 64-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using int64 = int_least64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @ingroup xtd_core types
  using intptr = intmax_t;
  
  /// @brief Represents a null pointer value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// std::unique_ptr<foo_class> foo = std::make_unique<foo_class>();
  /// ...
  /// foo = null; // release the unique pointer.
  /// @endcode
  /// @ingroup xtd_core types
  extern core_export_ std::nullptr_t null;
  
  /// @brief Represents a 8-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using sbyte = int_least8_t;
  
  /// @brief Stores information about a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using type = std::type_info;
  
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uchar = uchar_t;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint = uint_t;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint16 = uint_least16_t;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint32 = uint_least32_t;
  
  /// @brief Represents a 64-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint64 = uint_least64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uintptr = uintmax_t;
  
  /// @brief Represents a 32-bit or 64-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using ulong = ulong_t;

  /// @brief Represents a 16-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using ushort = ushort_t;
  
  /// @brief Represents a wide character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using wchar = wchar_t;
}

/*
/// @cond
namespace __ {
  /// @endcond
  /// @brief The system namespace contains all fundamental classes to access Hardware, Os, System, and more.
  namespace system = xtd;
}
using namespace __;
*/
