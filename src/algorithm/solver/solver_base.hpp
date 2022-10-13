#ifndef __ALGORITHM_SOLVER_BASE__HPP__
#define __ALGORITHM_SOLVER_BASE__HPP__

#include "common/geometry/geometry_base.hpp"
#include "solver_type.hpp"

namespace cgzr {

class SolverBase {
public:
  SolverBase(SolverType type) : type_(type) {}

  virtual std::unique_ptr<GeometryBase> Solve() const = 0;

protected:
  SolverType type_;
};

}  // namespace cgzr

#endif /* __ALGORITHM_SOLVER_BASE__HPP__ */
