#ifndef __COMMON_GEOMETRIC_GEOMETRY_BASE__HPP__
#define __COMMON_GEOMETRIC_GEOMETRY_BASE__HPP__

/**
 * @file geometry_base.hpp
 * @author Zhihao Ruan (shineyruan@gmail.com)
 * @brief Geometry is the main class for computational geometric algorithms &
 *    computations.
 * @date 2022-08-30
 */

#include <memory>

#include "common/geometry/geometry_type.hpp"
#include "visualization/drawable/drawable_base.hpp"

namespace cgzr {

class GeometryBase {
public:
  GeometryBase() = default;

  GeometryType Type() const { return type_; }

  virtual std::unique_ptr<visualization::DrawableBase> ToDrawable() const = 0;

protected:
  GeometryType type_;
};

}  // namespace cgzr

#endif /* __COMMON_GEOMETRIC_GEOMETRY_BASE__HPP__ */
