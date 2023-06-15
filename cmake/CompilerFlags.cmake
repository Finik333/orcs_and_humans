# Check compiler and set flags.

include(ForceAddFlags)

# Only set the cxx_standard if it is not set by someone else.
if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

# Strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled.
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CXX_COMPILER "Clang")
  force_add_flags(CMAKE_CXX_FLAGS
    -fPIC
    -stdlib=libc++
    -ftemplate-depth=1024
  )

elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CXX_COMPILER "GCC")
  force_add_flags(CMAKE_CXX_FLAGS
    -fPIC
  )

elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set(CXX_COMPILER "MSVC")

  # About STRICT see https://msdn.microsoft.com/en-us/library/windows/desktop/aa383681(v=vs.85).aspx.
  force_add_flags(CMAKE_CXX_FLAGS /bigobj /DUNICODE /D_UNICODE /DSTRICT /utf-8)

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
endif()

message(STATUS "Compiler id: ${CXX_COMPILER}")
