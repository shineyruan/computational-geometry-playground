cmake_minimum_required(VERSION 3.15)

# add eigen examples
add_executable(example_eigen example_eigen.cpp)
target_link_libraries(example_eigen PUBLIC
  ${CONAN_LIBS_EIGEN}
  ${CONAN_LIBS_SPDLOG}
  ${CONAN_LIBS_FMT}
)

# add opencv examples
add_executable(example_opencv example_opencv.cpp)
target_link_libraries(example_opencv PUBLIC
  ${CONAN_LIBS_OPENCV}
)
target_include_directories(example_opencv PUBLIC
  ${CONAN_INCLUDE_DIRS_OPENCV}
)
