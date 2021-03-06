# DeVAS version of FindZLIB that supports Windows cross-build

if ( NOT CMAKE_SYSTEM_NAME STREQUAL "Windows" )
  message ( FATAL_ERROR "FindZLIB_Windows: not Windows cross-compile!" )
endif ( )

set_property ( GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS ON )

set ( CMAKE_FIND_ROOT_PATH
	${CMAKE_CURRENT_SOURCE_DIR}/external-libs/windowsinstall )

find_path ( ZLIB_INCLUDE_DIR zlib.h )

find_library ( ZLIB_LIBRARY libz.a )

# handle the QUIETLY and REQUIRED arguments and set ZLIB_FOUND to TRUE if
# all listed variables are TRUE
include ( FindPackageHandleStandardArgs )
FIND_PACKAGE_HANDLE_STANDARD_ARGS ( ZLIB
	  DEFAULT_MSG
	  ZLIB_LIBRARY
	  ZLIB_INCLUDE_DIR
	  )

if ( ZLIB_FOUND )
  set ( ZLIB_LIBRARIES ${ZLIB_LIBRARY} )
endif ( )

# Deprecated declarations.
set ( NATIVE_ZLIB_INCLUDE_PATH ${ZLIB_INCLUDE_DIR} )
  if ( ZLIB_LIBRARY )
    get_filename_component ( NATIVE_ZLIB_LIB_PATH ${ZLIB_LIBRARY} PATH )
  endif ( )

mark_as_advanced ( ZLIB_LIBRARY ZLIB_INCLUDE_DIR )

