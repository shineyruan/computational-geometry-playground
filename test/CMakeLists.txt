cmake_minimum_required(VERSION 3.15)

# add eigen examples
add_executable(test_eigen test_eigen.cpp)
target_link_libraries(test_eigen PUBLIC
  Eigen3::Eigen
  spdlog::spdlog
  fmt::fmt
)

# add opencv examples
# DEPRECATED
# add_executable(test_opencv test_opencv.cpp)
# target_link_libraries(test_opencv PUBLIC
#   opencv_core
#   opencv_highgui
#   opencv_imgcodecs
#   opencv_imgproc
# )
# target_include_directories(test_opencv PUBLIC
#   ${OpenCV_INCLUDE_DIRS}
# )

find_package(sciplot CONFIG REQUIRED)
add_executable(test_sciplot test_sciplot.cpp)
target_link_libraries(test_sciplot PUBLIC sciplot::sciplot)

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
add_executable(test_sfml test_sfml.cpp)
target_link_libraries(test_sfml PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::System)
