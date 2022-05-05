cmake_minimum_required(VERSION 3.15)

# add eigen examples
add_executable(example_eigen example_eigen.cpp)
target_link_libraries(example_eigen PUBLIC
  Eigen
  spdlog
)

# add opencv examples
add_executable(example_opencv example_opencv.cpp)
target_link_libraries(example_opencv PUBLIC
  ${OpenCV_LIBS}
)
target_include_directories(example_opencv PUBLIC
  ${OpenCV_INCLUDE_DIRS}
)
