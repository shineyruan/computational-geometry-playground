#ifndef SRC_ALGORITHM_SOLVER_LINE_SEGMENT_INTERSECTION_SOLVER_HPP_
#define SRC_ALGORITHM_SOLVER_LINE_SEGMENT_INTERSECTION_SOLVER_HPP_

#include "solver_base.hpp"

namespace cgzr {

/**
 * @brief Given a set of lines in 2D, find all intersections among the set of
 * lines in O(n log n) time.
 *
 * Applies a sweep-line algorithm.
 */
class LineSegmentIntersectionSolver : public SolverBase {
 public:
  LineSegmentIntersectionSolver()
      : SolverBase(SolverType::LINE_SEGMENT_INTERSECTION) {}

  /**
   * @param in_geometries   A set of 2d lines. Should only contain {lines_2d}.
   * @return A set of 2d points as all intersections. Should only contain
   * {points_2d}.
   */
  std::vector<std::unique_ptr<GeometryBase>> Solve(
      const std::vector<const GeometryBase*>& in_geometries) const override;
};

}  // namespace cgzr

#endif  // SRC_ALGORITHM_SOLVER_LINE_SEGMENT_INTERSECTION_SOLVER_HPP_
