#include "convex_hull_solver.hpp"

#include <spdlog/spdlog.h>

#include <list>

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
    Lines2d* p_lines = dynamic_cast<Lines2d*>(lines_2d.get());

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

  // 2. Construct the upper hull
  std::list<Point2d> L_upper{points[0], points[1]};
  for (size_t i = 2; i < points.size(); ++i) {
    //  2.1 append p_i to L_upper
    L_upper.push_back(points[i]);
    //  2.2 while L_upper has more than 2 points and the last 3 does not make a
    //     right turn
    while (L_upper.size() > 2U && !IsRightTurn(*std::prev(L_upper.end(), 3),
                                               *std::prev(L_upper.end(), 2),
                                               *std::prev(L_upper.end(), 1))) {
      // delete the middle of the last 3 points
      L_upper.erase(std::prev(L_upper.end(), 2));
    }
  }

  // 3. Construct the lower hull
  std::list<Point2d> L_lower{*std::prev(points.end(), 1),
                             *std::prev(points.end(), 2)};
  for (int i = static_cast<int>(points.size() - 3); i >= 0; i--) {
    // 3.1 append p_i to L_lower
    L_lower.push_back(points[i]);
    // 3.2 while L_lower contains more than 2 points and the last 3 does not
    //    make a right turn
    while (L_lower.size() > 2U && !IsRightTurn(*std::prev(L_lower.end(), 3),
                                               *std::prev(L_lower.end(), 2),
                                               *std::prev(L_lower.end(), 1))) {
      // delete the middle of the last 3 points
      L_lower.erase(std::prev(L_lower.end(), 2));
    }
  }

  // 4. Remove the 1st and last point from L_lower to avoid duplication at where
  // the upper & lower hull meet
  assert(L_lower.size() >= 2U);
  L_lower.erase(L_lower.begin());
  L_lower.erase(std::prev(L_lower.end()));

  // 5. Append L_lower to L_upper, and form L
  std::vector<Point2d> L{L_upper.begin(), L_upper.end()};
  L.insert(L.end(), L_lower.begin(), L_lower.end());

  // 6. Construct return
  //
  // 6.1 construct points
  ret.emplace_back(std::make_unique<Points2d>(L));

  // 6.2 construct connecting lines
  auto lines_2d = GeometryBase::Create(GeometryType::LINES_2D);
  Lines2d* p_lines = dynamic_cast<Lines2d*>(lines_2d.get());

  std::vector<std::pair<size_t, size_t>> line_indices{};
  line_indices.reserve(L.size());
  for (size_t i = 0; i < L.size(); ++i) {
    if (i == L.size() - 1) {
      line_indices.emplace_back(i, 0U);
    } else {
      line_indices.emplace_back(i, i + 1);
    }
  }

  p_lines->UpdatePoints(L);
  p_lines->UpdateLineAsIndices(line_indices);
  ret.emplace_back(std::move(lines_2d));

  return ret;
}

bool ConvexHullSolver::IsRightTurn(const Eigen::Vector2d& p1,
                                   const Eigen::Vector2d& p2,
                                   const Eigen::Vector2d& p3) const {
  Eigen::Vector3d v1{p2.x() - p1.x(), p2.y() - p1.y(), 0.};
  Eigen::Vector3d v2{p3.x() - p2.x(), p3.y() - p2.y(), 0.};
  return v1.cross(v2).z() < std::numeric_limits<double>::epsilon();
}

}  // namespace cgzr
