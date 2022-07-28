/**
 * @file main.cpp
 * @author Zhihao Ruan (shineyruan@gmail.com)
 * @date 2022-05-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <spdlog/spdlog.h>

#include "visualization/drawable/line_string.hpp"
#include "visualization/drawable/point_set.hpp"
#include "visualization/visualizer/opencv_visualizer.hpp"

using namespace cgzr;

int main() {
  spdlog::info("Hello!");

  visualization::OpenCVVisualizer visualizer;
  visualization::LineString line_string;
  visualization::PointSet point_set;

  visualizer.Add(&line_string);
  visualizer.Add(&point_set);

  spdlog::info("Bye!");

  return 0;
}
