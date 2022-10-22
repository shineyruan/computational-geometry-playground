#include "convex_hull_solver.hpp"

#include <spdlog/spdlog.h>

#include "common/geometry/lines2d.hpp"

namespace cgzr {

namespace {
// For Convex Hull, there must be only one input geometry, and it must be
// Points2d.
const Points2d* ExtractInput(
    const std::vector<const GeometryBase*>& in_geometries) {
  // 1. Check input size
  if (in_geometries.size() != 1) {
    SPDLOG_ERROR("input does not contain only 1 geometry");
    return nullptr;
  }
  // 2. Check if it's Point2d
  auto points_2d = dynamic_cast<const Points2d*>(in_geometries.front());
  if (!points_2d) {
    SPDLOG_ERROR("input {} is not correct type {}",
                 ToString(GeometryType::POINTS_2D),
                 ToString(in_geometries.front()->Type()));
    return nullptr;
  }
  // 3. Check if points_2d has >=3 points
  if (points_2d->Size() < 3UL) {
    SPDLOG_ERROR("input has <=3 points; no valid convex hull is found");
    return nullptr;
  }
  // 4. Return
  return points_2d;
}
}  // namespace

std::vector<std::unique_ptr<GeometryBase>> ConvexHullSolver::Solve(
    const std::vector<const GeometryBase*>& in_geometries) const {
  std::vector<std::unique_ptr<GeometryBase>> ret;

  // 0. Input check
  auto points_2d = ExtractInput(in_geometries);
  if (!points_2d) {
    return ret;
  }
  if (points_2d->Size() == 3UL) {
    // construct points as original
    ret.emplace_back(points_2d->Clone());

    // construct lines to form a triangle shape
    auto lines_2d = GeometryBase::Create(GeometryType::LINES_2D);
    Lines2D* p_lines = dynamic_cast<Lines2D*>(lines_2d.get());

    std::vector<std::pair<size_t, size_t>> line_indices{{0, 1}, {1, 2}, {2, 0}};
    p_lines->UpdatePoints(points_2d->AsVector2ds());
    p_lines->UpdateLineAsIndices(line_indices);
    ret.emplace_back(std::move(lines_2d));

    // return
    return ret;
  }

  using Point2d = Eigen::Vector2d;

  // 1. Sort the point by x-coordinates, resulting in a sequence p1,p2,...,pn
  auto points = points_2d->AsVector2ds();
  std::sort(
      points.begin(), points.end(),
      [](const Point2d& p1, const Point2d& p2) { return p1.x() < p2.x(); });

  // TODO: 2. Put p1, p2 in a list L_upper
  std::vector<Point2d> L_upper{points[0], points[1]};

  return ret;
}

}  // namespace cgzr
