#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "xtd" for configuration "Debug"
set_property(TARGET xtd APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(xtd PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libxtd.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS xtd )
list(APPEND _IMPORT_CHECK_FILES_FOR_xtd "${_IMPORT_PREFIX}/lib/libxtd.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
