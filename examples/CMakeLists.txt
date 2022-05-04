cmake_minimum_required(VERSION 3.15)

# add sciplot examples
add_executable(example_sciplot example_sciplot.cpp)
target_link_libraries(example_sciplot PUBLIC
  sciplot
)

# add eigen examples
add_executable(example_eigen example_eigen.cpp)
target_link_libraries(example_eigen PUBLIC
  eigen
  spdlog
)
