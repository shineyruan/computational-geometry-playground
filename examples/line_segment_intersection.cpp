/**
 * @file main.cpp
 * @author Zhihao Ruan (shineyruan@gmail.com)
 * @date 2022-05-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <spdlog/spdlog.h>

#include "algorithm/solver/line_segment_intersection_solver.hpp"
#include "common/geometry/lines2d.hpp"
#include "visualization/visualizer/sfml_visualizer.hpp"

using namespace cgzr;

int main() {
  SPDLOG_INFO("Hello!");

  size_t N = 10;
  SPDLOG_INFO("Creating {} line segments...", N);
  auto lines_2d = GeometryBase::CreateRandom(GeometryType::LINES_2D, N);

  SPDLOG_INFO("Creating line intersection solver...");
  auto line_intersection_solver =
      std::make_unique<LineSegmentIntersectionSolver>();

  SPDLOG_INFO("Collecting input geometries for solver...");
  std::vector<const GeometryBase*> input_geometries{lines_2d.get()};

  SPDLOG_INFO("Solving line segment intersection...");
  auto results = line_intersection_solver->Solve(input_geometries);

  SPDLOG_INFO("Creating visualizer...");
  visualization::SfmlVisualizer visualizer;

  SPDLOG_INFO("Adding items to visualizer...");
  for (const auto& out_geometry : results) {
    visualizer.Add(out_geometry->ToDrawable(colors::COLOR_RED));
  }
  visualizer.Add(lines_2d->ToDrawable(colors::COLOR_BLACK));

  SPDLOG_INFO("Visualizing results...");
  visualizer.Visualize();

  SPDLOG_INFO("Bye!");

  return 0;
}
