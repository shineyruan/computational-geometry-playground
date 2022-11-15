cmake_minimum_required(VERSION 3.15)

add_library(${PROJ_NAME})

# Source files
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
file(GLOB_RECURSE HEADER_FILES *.hpp *.inl *.h)

# Add target sources
target_sources(${PROJ_NAME} PUBLIC ${SOURCE_FILES} ${HEADER_FILES})

# Source group
source_group("Sources"  FILES ${SOURCE_FILES})
source_group("Headers"  FILES ${HEADER_FILES})

# link libraries
target_link_libraries(${PROJ_NAME}
  ${CONAN_LIBS_EIGEN}
  ${CONAN_LIBS_OPENCV}
  ${CONAN_LIBS_SPDLOG}
  ${CONAN_LIBS_FMT}
)

# Linux specific libraries
if (UNIX AND NOT APPLE)
  target_link_libraries(${PROJ_NAME}
    ${GTK_LIBRARIES}
  )
  target_include_directories(${PROJ_NAME} PUBLIC
    ${GTK_INCLUDE_DIRS}
  )
endif()

# include dirs
target_include_directories(${PROJ_NAME} PUBLIC
  ${CONAN_INCLUDE_DIRS_EIGEN}
  ${CONAN_INCLUDE_DIRS_OPENCV}
  ${CONAN_INCLUDE_DIRS_SPDLOG}
)
target_include_directories(${PROJ_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# compile options
target_compile_options(${PROJ_NAME} PRIVATE
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
