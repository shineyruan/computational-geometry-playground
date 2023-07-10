#include "line_segment_intersection_solver.hpp"

#include <spdlog/spdlog.h>

#include "common/geometry/lines2d.hpp"
#include "common/geometry/points2d.hpp"

namespace cgzr {

namespace {
// For line segments, there must be only one input geometry, and it must be
// Lines2D.
const Lines2D* ExtractInput(
    const std::vector<const GeometryBase*>& in_geometries) {
  // 1. Check input size
  if (in_geometries.size() != 1) {
    SPDLOG_ERROR("input does not contain only 1 geometry");
    return nullptr;
  }
  // 2. Check if it's Lines2d
  auto lines_2d = dynamic_cast<const Lines2D*>(in_geometries.front());
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

  return result;
}

}  // namespace cgzr
