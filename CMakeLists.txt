cmake_minimum_required(VERSION 3.21)

# Set the project name and language.
project(OrcsAndHumans
  VERSION 0.0.1
  LANGUAGES CXX C
)
message(STATUS "${PROJECT_NAME} ${PROJECT_VERSION}")

# Include CMake modules.
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(PreventInSourceBuild)
include(TargetArch)
include(CompilerFlags)

# Enable all project inclusions.
include_directories(src)

# Bin
add_executable(OrcsAndHumans src/Main.cpp)
