#ifndef SRC_ALGORITHM_SOLVER_CONVEX_HULL_SOLVER_HPP_
#define SRC_ALGORITHM_SOLVER_CONVEX_HULL_SOLVER_HPP_

#include "common/geometry/points2d.hpp"
#include "solver_base.hpp"

namespace cgzr {

class ConvexHullSolver : public SolverBase {
 public:
  ConvexHullSolver() : SolverBase(SolverType::CONVEX_HULL) {}

  std::vector<std::unique_ptr<GeometryBase>> Solve(
      const std::vector<const GeometryBase*>& in_geometries) const override;

 private:
  bool IsRightTurn(const Eigen::Vector2d& p1, const Eigen::Vector2d& p2,
                   const Eigen::Vector2d& p3) const;
};

}  // namespace cgzr

#endif  // SRC_ALGORITHM_SOLVER_CONVEX_HULL_SOLVER_HPP_
