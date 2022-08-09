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
  auto line_string = std::make_unique<visualization::LineString>();
  auto point_set = std::make_unique<visualization::PointSet>();

  std::vector<Eigen::Vector2d> points{
      {0., 10.}, {10., 5.}, {5., 10.}, {5., 5.}};
  point_set->UpdateVertices(std::move(points));

  std::vector<Eigen::Vector2d> vertices{{0., 3.}, {3., 0.}, {3., 3.}, {0., 0.}};
  std::vector<std::pair<size_t, size_t>> edges{{0, 1}, {1, 2}, {2, 3}, {1, 3}};
  line_string->UpdateVertices(std::move(vertices));
  line_string->UpdateEdges(std::move(edges));

  visualizer.Add(std::move(line_string));
  visualizer.Add(std::move(point_set));

  visualizer.Visualize();

  spdlog::info("Bye!");

  return 0;
}
