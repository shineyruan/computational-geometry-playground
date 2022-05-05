cmake_minimum_required(VERSION 3.15)

add_executable(${PROJECT_NAME})

# Source files
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)
file(GLOB_RECURSE HEADER_FILES *.hpp *.inl *.h)

# Add target sources
target_sources(${PROJECT_NAME} PUBLIC ${SOURCE_FILES} ${HEADER_FILES})

# Source group
source_group("Sources"  FILES ${SOURCE_FILES})
source_group("Headers"  FILES ${HEADER_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
  spdlog
)
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
  /W4>
)
