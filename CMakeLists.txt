cmake_minimum_required(VERSION 3.15)
project(cgsolver)

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

# setup CMake toolchain (Conan by default)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_BINARY_DIR}/conan_toolchain.cmake" CACHE PATH "toolchain file")
message(STATUS "Used CMake toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

# required packages
find_package(spdlog REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(sciplot REQUIRED)
find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)

# --------------------------
add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(test)
