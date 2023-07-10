#ifndef SRC_ALGORITHM_SOLVER_CONVEX_HULL_SOLVER_HPP_
#define SRC_ALGORITHM_SOLVER_CONVEX_HULL_SOLVER_HPP_

#include "common/geometry/points2d.hpp"
#include "solver_base.hpp"

namespace cgzr {

/**
 * @brief Given a set of points in 2D, find the convex hull of all the points
 * representing in {vertices, line_strings} form.
 */
class ConvexHullSolver : public SolverBase {
 public:
  ConvexHullSolver() : SolverBase(SolverType::CONVEX_HULL) {}

  /**
   * @param in_geometries   A set of points. Should only contain {points_2d}
   * @return  A convex hull representation. Should only contain {points_2d,
   * lines_2d}
   */
  std::vector<std::unique_ptr<GeometryBase>> Solve(
      const std::vector<const GeometryBase*>& in_geometries) const override;

 private:
  // Checks whether p2-p1 --> p3-p2 forms a right turn
  bool IsRightTurn(const Eigen::Vector2d& p1, const Eigen::Vector2d& p2,
                   const Eigen::Vector2d& p3) const;
};

}  // namespace cgzr

#endif  // SRC_ALGORITHM_SOLVER_CONVEX_HULL_SOLVER_HPP_
