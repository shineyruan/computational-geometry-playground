#ifndef __ALGORITHM_CONVEX_HULL_SOLVER__HPP__
#define __ALGORITHM_CONVEX_HULL_SOLVER__HPP__

#include "common/geometry/points.hpp"
#include "solver_base.hpp"

namespace cgzr {

class ConvexHullSolver : public SolverBase {
public:
  ConvexHullSolver(const Points* points = nullptr)
      : SolverBase(SolverType::CONVEX_HULL), points_(points) {}

  std::vector<std::unique_ptr<GeometryBase>> Solve() const override;

private:
  const Points* points_{nullptr};
};

}  // namespace cgzr

#endif /* __ALGORITHM_CONVEX_HULL_SOLVER__HPP__ */
