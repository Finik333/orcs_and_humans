cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(OrcsAndHumans
  VERSION 0.1.0
  LANGUAGES CXX C
)

message(STATUS "${PROJECT_NAME} ${PROJECT_VERSION}")

#
# Include specific modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(TargetArch)
include(UtilMacro)

#
# Fix installation path
file(TO_CMAKE_PATH ${CMAKE_INSTALL_PREFIX} CMAKE_INSTALL_PREFIX)

#
# User specified build options
option(TREAT_WARN_AS_ERROR "Treat all compiler warnings as errors" OFF)
option(USE_THREAD_SANITIZER "Use ThreadSanitizer for clang or gcc compiler" OFF)
option(USE_ADDRESS_SANITIZER "Use AddressSanitizer for clang or gcc compiler" OFF)
option(USE_LEAK_SANITIZER "Use LeakSanitizer for clang or gcc compiler" OFF)

#
# Checking system
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(SYSTEM_NAME "Linux")
  message(STATUS "System: Linux")
  add_definitions(-DOS_LINUX=1)
  set(LINUX 1)

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  set(SYSTEM_NAME "Windows")
  message(STATUS "System: Windows")
  add_definitions(-DOS_WIN=1)
  set(WINDOWS 1)

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(SYSTEM_NAME "macOS")
  message(STATUS "System: macOS")
  add_definitions(-DOS_MACOS=1)
  set(OSX 1)

  set(CMAKE_MACOSX_RPATH ON)
  set(CMAKE_SKIP_BUILD_RPATH FALSE)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
  set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
  list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES ${CMAKE_INSTALL_PREFIX}/lib IS_SYSTEM_DIR)
  if("${IS_SYSTEM_DIR}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
  endif()

else()
  set(SYSTEM_NAME "Unknown")
  message(STATUS "System: unknown")
endif()

#
# Checking arch
target_architecture(ARCHITECTURE)
message(STATUS "Arch: ${ARCHITECTURE}")

#
# Enable all project inclusions
include_directories(src)

#
# Checking compiler
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CXX_COMPILER "Clang")
  add_definitions(-DCLANG_COMPILER=1)
  set(CLANG_COMPILER 1)

  force_add_flags(CMAKE_CXX_FLAGS -std=c++17 -Wno-sign-compare -Wno-unused -Wno-unused-parameter -fPIC -stdlib=libc++ -ftemplate-depth=1024)
  if(TREAT_WARN_AS_ERROR)
    force_add_flags(CMAKE_CXX_FLAGS -Werror)
  endif()
  if (USE_THREAD_SANITIZER)
    force_add_flags(CMAKE_CXX_FLAGS -fsanitize=thread -fno-omit-frame-pointer -pie -static-libtsan -g)
  endif()
  if (USE_ADDRESS_SANITIZER)
    force_add_flags(CMAKE_CXX_FLAGS -fsanitize=address -fno-omit-frame-pointer -g)
  endif()
  if (USE_LEAK_SANITIZER)
    force_add_flags(CMAKE_CXX_FLAGS -fsanitize=leak -fno-omit-frame-pointer -g)
  endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CXX_COMPILER "GCC")
  add_definitions(-DGCC_COMPILER=1)
  set(GCC_COMPILER 1)

  force_add_flags(CMAKE_CXX_FLAGS -std=c++17 -Wno-sign-compare -Wno-unused -Wno-unused-parameter -fPIC)
  if(TREAT_WARN_AS_ERROR)
    force_add_flags(CMAKE_CXX_FLAGS -Werror)
  endif()
  if (USE_THREAD_SANITIZER)
    force_add_flags(CMAKE_CXX_FLAGS -fsanitize=thread -fno-omit-frame-pointer -pie -static-libtsan -g)
  endif()
  if (USE_ADDRESS_SANITIZER)
    force_add_flags(CMAKE_CXX_FLAGS -fsanitize=address -fno-omit-frame-pointer -g)
  endif()
  if (USE_LEAK_SANITIZER)
    force_add_flags(CMAKE_CXX_FLAGS -fsanitize=leak -fno-omit-frame-pointer -g)
  endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set(CXX_COMPILER "MSVC")
  add_definitions(-DMSVC_COMPILER=1)
  set(MSVC_COMPILER 1)

  # About STRICT see https://msdn.microsoft.com/en-us/library/windows/desktop/aa383681(v=vs.85).aspx.
  force_add_flags(CMAKE_CXX_FLAGS /bigobj /DUNICODE /D_UNICODE /DSTRICT)

  if(TREAT_WARN_AS_ERROR)
    force_add_flags(CMAKE_CXX_FLAGS /WX)
  endif()

  # Suppress some warnings.
  # Got from Kaldi: base/kaldi-utils.h
  force_add_flags(CMAKE_CXX_FLAGS  /wd4056 /wd4244 /wd4267 /wd4305 /wd4661 /wd4756 /wd4800 /wd4996)
  # Got from OpenFstPort:
  force_add_flags(CMAKE_CXX_FLAGS  /wd4305 /wd4291 /wd4267 /wd4244 /wd4018 /wd4996)

  # Enable exceptions, see http://msdn.microsoft.com/en-us/library/1deeycx5.aspx.
  force_add_flags(CMAKE_CXX_FLAGS /EHsc)

  # Calling any one of the potentially unsafe methods in the Standard C++ Library
  # will result in Compiler Warning (level 3) C4996.
  # To disable this warning, define that macro.
  # See https://msdn.microsoft.com/en-us/library/aa985974.aspx.
  force_add_flags(CMAKE_CXX_FLAGS /D_SCL_SECURE_NO_WARNINGS)

  # Fix min/max issue while windows.h using
  # See https://support.microsoft.com/en-us/help/143208/prb-using-stl-in-windows-program-can-cause-min-max-conflicts.
  force_add_flags(CMAKE_CXX_FLAGS /DNOMINMAX)

  # Specifies that the minimum required platform is Windows 7.
  # Change this to the appropriate value to target other versions of Windows.
  # See https://msdn.microsoft.com/en-us/library/6sehtctf.aspx.
  force_add_flags(CMAKE_CXX_FLAGS /DWINVER=0x0601 /D_WIN32_WINNT=0x0601)
endif()
message(STATUS "Compiler id: ${CXX_COMPILER}")

#
# Bin
add_executable(OrcsAndHumans
  src/Main.cpp
)
