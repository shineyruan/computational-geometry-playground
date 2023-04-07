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
  opencv_core
  opencv_highgui
  opencv_imgcodecs
  opencv_imgproc
)

target_include_directories(test_opencv PUBLIC
  ${OpenCV_INCLUDE_DIRS}
)

find_package(implot CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
add_executable(test_implot test_implot.cpp)
target_link_libraries(test_implot PUBLIC
  implot::implot
  imgui::imgui
  ${OPENGL_LIBRARIES}
)
