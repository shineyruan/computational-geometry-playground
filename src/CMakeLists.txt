cmake_minimum_required(VERSION 3.15)

add_library(${PROJECT_NAME})

# Source files
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
file(GLOB_RECURSE HEADER_FILES *.hpp *.inl *.h)

# Deprecate OpenCV visualizer
list(REMOVE_ITEM SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/visualization/visualizer/opencv_visualizer.cpp
)

# Add target sources
target_sources(${PROJECT_NAME} PUBLIC ${SOURCE_FILES} ${HEADER_FILES})

# Source group
source_group("Sources"  FILES ${SOURCE_FILES})
source_group("Headers"  FILES ${HEADER_FILES})

# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
  Eigen3::Eigen
  spdlog::spdlog
  fmt::fmt
  sciplot::sciplot
  SFML::Graphics
  SFML::Window
)

# include dirs
target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# compile options
target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CXX_COMPILER_ID:GNU>:
  -Wall
  -Wextra
  -Werror>
  $<$<CXX_COMPILER_ID:AppleClang>:
  -Wall
  -Wextra
  -Werror>
  $<$<CXX_COMPILER_ID:MSVC>:
  /WX
  /W4
  /wd4127
  /wd4459>
)
