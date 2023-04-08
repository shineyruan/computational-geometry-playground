/**
 * @file main.cpp
 * @author Zhihao Ruan (shineyruan@gmail.com)
 * @date 2022-05-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <spdlog/spdlog.h>

#include "algorithm/solver/convex_hull_solver.hpp"
#include "common/geometry/points2d.hpp"
#include "visualization/drawable/line_string.hpp"
#include "visualization/drawable/point_set.hpp"
#include "visualization/visualizer/sciplot_visualizer.hpp"

using namespace cgzr;

int main() {
  SPDLOG_INFO("Hello!");

  SPDLOG_INFO("Creating 3 points...");
  auto points_2d = GeometryBase::CreateRandom(GeometryType::POINTS_2D, 100);

  SPDLOG_INFO("Creating convex hull solver...");
  auto convex_hull_solver = std::make_unique<ConvexHullSolver>();

  SPDLOG_INFO("Collecting input geometries for solver...");
  std::vector<const GeometryBase*> input_geometries{points_2d.get()};

  SPDLOG_INFO("Solving convex hull...");
  auto results = convex_hull_solver->Solve(input_geometries);

  SPDLOG_INFO("Creating visualizer...");
  visualization::SciplotVisualizer visualizer;

  SPDLOG_INFO("Adding items to visualizer...");
  for (const auto& out_geometry : results) {
    visualizer.Add(out_geometry->ToDrawable(colors::COLOR_RED));
  }
  visualizer.Add(points_2d->ToDrawable(colors::COLOR_BLACK));

  SPDLOG_INFO("Visualizing results...");
  visualizer.Visualize();

  SPDLOG_INFO("Bye!");

  return 0;
}
