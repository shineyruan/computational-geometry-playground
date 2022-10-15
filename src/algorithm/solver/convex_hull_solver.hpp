#ifndef __ALGORITHM_CONVEX_HULL_SOLVER__HPP__
#define __ALGORITHM_CONVEX_HULL_SOLVER__HPP__

#include "common/geometry/points2d.hpp"
#include "solver_base.hpp"

namespace cgzr {

class ConvexHullSolver : public SolverBase {
public:
  ConvexHullSolver() : SolverBase(SolverType::CONVEX_HULL) {}

  std::vector<std::unique_ptr<GeometryBase>> Solve(
      const std::vector<std::unique_ptr<GeometryBase>>& in_geometries)
      const override;
};

}  // namespace cgzr

#endif /* __ALGORITHM_CONVEX_HULL_SOLVER__HPP__ */
