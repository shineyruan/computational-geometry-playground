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
  NAME eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.4.0
  OPTIONS
    "EIGEN_BUILD_DOC Off"
    "BUILD_TESTING Off"
    "EIGEN_BUILD_PKGCONFIG Off"
)
# -------------------------

# ----- Install spdlog -----
CPMAddPackage(
  NAME spdlog
  GIT_TAG v1.10.0
  GITHUB_REPOSITORY gabime/spdlog
)
# --------------------------

# ----- Install sciplot -----
CPMAddPackage(
  NAME sciplot
  GIT_TAG cmake-subproject-support
  GITHUB_REPOSITORY Ram-Z/sciplot
  OPTIONS
    "SCIPLOT_BUILD_EXAMPLES Off"
    "SCIPLOT_BUILD_TESTS Off"
    "SCIPLOT_BUILD_DOCS Off"
)
# ---------------------------

add_subdirectory(src)
add_subdirectory(examples)


