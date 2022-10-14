#include "convex_hull_solver.hpp"

#include <spdlog/spdlog.h>

namespace cgzr {

std::vector<std::unique_ptr<GeometryBase>> ConvexHullSolver::Solve() const {
  std::vector<std::unique_ptr<GeometryBase>> ret;
  if (!points_ || points_->Size() == 0) {
    SPDLOG_ERROR("points_ is nullptr");
    return ret;
  }
  if (points_->Size() < 3UL) {
    ret.emplace_back(points_->Clone());
    return ret;
  }
  if (points_->Size() == 3UL) {
    // construct points as original
    ret.emplace_back(points_->Clone());

    // TODO construct line strings that connects each pair of points
  }

  // 1. Sort the point by x-coordinates, resulting in a sequence p1,p2,...,pn
  auto point_coords = points_->GetCoordinates();
  std::sort(point_coords.begin(), point_coords.end(),
            [](const Eigen::Vector2d& p1, const Eigen::Vector2d& p2) {
              return p1.x() < p2.x();
            });

  // TODO: 2. Put p1, p2 in a list L_upper
  std::vector<Eigen::Vector2d> L_upper{point_coords[0], point_coords[1]};

  return ret;
}

}  // namespace cgzr
