cmake_minimum_required(VERSION 3.15)
project(cg_playground)

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

# Compile with -march=native
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
if(COMPILER_SUPPORTS_MARCH_NATIVE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

# ----- Download CPM.cmake and use it as dependency management -----
set(CPM_DOWNLOAD_VERSION 0.35.0)
if(CPM_SOURCE_CACHE)
  set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
  set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
  set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()
if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
  message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
  file(DOWNLOAD
       https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
       ${CPM_DOWNLOAD_LOCATION}
  )
endif()
include(${CPM_DOWNLOAD_LOCATION})
# ------------------------------------------------------------------

set(FETCHCONTENT_QUIET FALSE)

# ----- Install Eigen -----
CPMAddPackage(
  NAME Eigen
  VERSION 3.4.0
  URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
  # Eigen's CMakelists are not intended for library use
  DOWNLOAD_ONLY YES
)
if(Eigen_ADDED)
  add_library(Eigen INTERFACE IMPORTED)
  target_include_directories(Eigen INTERFACE ${Eigen_SOURCE_DIR})
endif()
# -------------------------

# ----- Install spdlog -----
CPMAddPackage(
  NAME spdlog
  GIT_TAG v1.10.0
  GITHUB_REPOSITORY gabime/spdlog
  GIT_PROGRESS TRUE
)
# --------------------------

# ----- Install OpenCV -----
include(cmake/build_external_project.cmake)
message(STATUS "Using CMake build parallel level: ${CMAKE_BUILD_PARALLEL_LEVEL}")
build_external_project(
	opencv
	${CMAKE_CURRENT_BINARY_DIR}/external
	https://github.com/opencv/opencv.git
	4.5.4
    -DBUILD_LIST=core,highgui,improc,imgcodecs
    -DBUILD_DOCS:BOOL=FALSE
    -DBUILD_EXAMPLES:BOOL=FALSE
    -DBUILD_TESTS:BOOL=FALSE
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DBUILD_SHARED_LIBS:BOOL=TRUE
    -DBUILD_NEW_PYTHON_SUPPORT:BOOL=OFF
    -DBUILD_WITH_DEBUG_INFO=OFF
    -DWITH_CUDA:BOOL=FALSE
    -DWITH_FFMPEG:BOOL=FALSE
    -DWITH_MSMF:BOOL=FALSE
    -DWITH_IPP:BOOL=FALSE
    -DWITH_PROTOBUF:BOOL=FALSE
    -DWITH_QUIRC:BOOL=FALSE
    -DBUILD_PERF_TESTS:BOOL=FALSE
    -DBUILD_PNG:BOOL=ON
    -DBUILD_JPEG:BOOL=ON
    -DBUILD_WITH_STATIC_CRT:BOOL=OFF
    -DBUILD_FAT_JAVA_LIB=OFF
    -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}/opencv
    -DCMAKE_BUILD_PARALLEL_LEVEL=${CMAKE_BUILD_PARALLEL_LEVEL}
)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_CURRENT_BINARY_DIR}/opencv")
find_package(OpenCV REQUIRED)
# --------------------------
add_subdirectory(src)
add_subdirectory(examples)
