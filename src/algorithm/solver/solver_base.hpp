#ifndef SRC_ALGORITHM_SOLVER_SOLVER_BASE_HPP_
#define SRC_ALGORITHM_SOLVER_SOLVER_BASE_HPP_

/**
 * @file solver_base.hpp
 * @author Zhihao Ruan (shineyruan@gmail.com)
 * @brief Solvers are the basic containers of actual algorithms. They shall
 * clearly define the input/output of each algorithms.
 * @date 2022-10-15
 */

#include "common/geometry/geometry_base.hpp"
#include "solver_type.hpp"

namespace cgzr {

class SolverBase {
 public:
  SolverBase(SolverType type) : type_(type) {}
  virtual ~SolverBase() = default;

  virtual std::vector<std::unique_ptr<GeometryBase>> Solve(
      const std::vector<const GeometryBase*>& in_geometries) const = 0;

 protected:
  SolverType type_;
};

}  // namespace cgzr

#endif  // SRC_ALGORITHM_SOLVER_SOLVER_BASE_HPP_
