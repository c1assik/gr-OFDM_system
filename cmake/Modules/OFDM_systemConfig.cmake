INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_OFDM_SYSTEM OFDM_system)

FIND_PATH(
    OFDM_SYSTEM_INCLUDE_DIRS
    NAMES OFDM_system/api.h
    HINTS $ENV{OFDM_SYSTEM_DIR}/include
        ${PC_OFDM_SYSTEM_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    OFDM_SYSTEM_LIBRARIES
    NAMES gnuradio-OFDM_system
    HINTS $ENV{OFDM_SYSTEM_DIR}/lib
        ${PC_OFDM_SYSTEM_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/OFDM_systemTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OFDM_SYSTEM DEFAULT_MSG OFDM_SYSTEM_LIBRARIES OFDM_SYSTEM_INCLUDE_DIRS)
MARK_AS_ADVANCED(OFDM_SYSTEM_LIBRARIES OFDM_SYSTEM_INCLUDE_DIRS)
