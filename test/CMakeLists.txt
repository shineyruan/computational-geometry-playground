cmake_minimum_required(VERSION 3.15)

# add eigen examples
add_executable(test_eigen test_eigen.cpp)
target_link_libraries(test_eigen PUBLIC
  Eigen3::Eigen
  spdlog::spdlog
  fmt::fmt
)

# add opencv examples
add_executable(test_opencv test_opencv.cpp)
target_link_libraries(test_opencv PUBLIC
  ${OpenCV_LIBS}
)
if (UNIX AND NOT APPLE)
  target_link_libraries(test_opencv PUBLIC
    ${GTK_LIBRARIES}
  )
  target_include_directories(test_opencv PUBLIC
    ${GTK_INCLUDE_DIRS}
  )
endif()
target_include_directories(test_opencv PUBLIC
  ${OpenCV_INCLUDE_DIRS}
)
