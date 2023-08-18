#include "line_segment_intersection_solver.hpp"

#include <spdlog/spdlog.h>

#include <map>

#include "common/geometry/lines2d.hpp"
#include "common/geometry/points2d.hpp"

namespace cgzr {

namespace {
// For line segments, there must be only one input geometry, and it must be
// Lines2d.
const Lines2d* ExtractInput(
    const std::vector<const GeometryBase*>& in_geometries) {
  // 1. Check input size
  if (in_geometries.size() != 1) {
    SPDLOG_ERROR("input does not contain only 1 geometry");
    return nullptr;
  }
  // 2. Check if it's Lines2d
  auto lines_2d = dynamic_cast<const Lines2d*>(in_geometries.front());
  if (!lines_2d) {
    SPDLOG_ERROR("input {} is not correct type {}",
                 ToString(GeometryType::LINES_2D),
                 ToString(in_geometries.front()->Type()));
    return nullptr;
  }
  // 3. Check if lines_2d has >=2 lines
  if (lines_2d->Size() < 2UL) {
    SPDLOG_ERROR("input has <=2 line segments; no valid intersection is found");
    return nullptr;
  }
  // 4. Return
  return lines_2d;
}
}  // namespace

std::vector<std::unique_ptr<GeometryBase>> LineSegmentIntersectionSolver::Solve(
    const std::vector<const GeometryBase*>& in_geometries) const {
  std::vector<std::unique_ptr<GeometryBase>> result;

  // 0. Extract input & input check
  auto lines_2d = ExtractInput(in_geometries);
  if (!lines_2d) {
    return result;
  }

  using Point2d = Eigen::Vector2d;
  using Segment2d = std::pair<Eigen::Vector2d, Eigen::Vector2d>;

  //  0.1 construct line segment from Lines2d
  std::vector<Segment2d> segments;
  auto lines = lines_2d->Lines();
  for (const auto& [p1, p2] : lines) {
    segments.emplace_back(p1, p2);
  }

  // 1. Initialize event queue
  // Event queue is a mapping from segment endpoints to pointer to segments
  auto point_cmp = [](const Point2d& p1, const Point2d& p2) {
    return p1.y() > p2.y() || (p1.y() == p2.y() && p1.x() < p2.x());
  };
  std::map<Point2d, const Segment2d*, decltype(point_cmp)> event_q(point_cmp);

  return result;
}

}  // namespace cgzr
