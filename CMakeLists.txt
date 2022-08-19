cmake_minimum_required(VERSION 3.15)
project(cg_playground)
set(PROJ_NAME ${PROJECT_NAME}) # avoid confusion with Conan pkgs

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# cmake configuration type
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

if (UNIX)
  # suppress MacOS visibility warning:
  # https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/CppRuntimeEnv/Articles/SymbolVisibility.html
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")

  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -fno-omit-frame-pointer")
endif()

# Compile with -march=native
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
if(COMPILER_SUPPORTS_MARCH_NATIVE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# find GTK-2.0 for OpenCV highgui
if (UNIX AND NOT APPLE)
  find_package(PkgConfig REQUIRED)
  PKG_CHECK_MODULES(GTK REQUIRED gtk+-2.0)
  message(STATUS "GTK Libraries: ${GTK_LIBRARIES}")
endif()

# --------------------------
add_subdirectory(src)
add_subdirectory(examples)
