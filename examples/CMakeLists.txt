cmake_minimum_required(VERSION 3.15)

include_directories(
  ${CMAKE_SOURCE_DIR}/src
)

# convex hull solver
add_executable(convex_hull convex_hull.cpp)
target_link_libraries(convex_hull PUBLIC
  ${PROJECT_NAME}
)
target_compile_options(convex_hull PRIVATE
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

# line segment intersection solver
add_executable(line_segment_intersection line_segment_intersection.cpp)
target_link_libraries(line_segment_intersection PUBLIC
  ${PROJECT_NAME}
)
target_compile_options(line_segment_intersection PRIVATE
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
