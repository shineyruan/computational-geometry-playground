#ifndef SRC_COMMON_GEOMETRY_GEOMETRY_BASE_HPP_
#define SRC_COMMON_GEOMETRY_GEOMETRY_BASE_HPP_

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
  GeometryBase(GeometryType type) : type_(type) {}
  virtual ~GeometryBase() = default;

  GeometryType Type() const { return type_; }

  virtual size_t Size() const = 0;
  virtual std::unique_ptr<GeometryBase> Clone() const = 0;

  virtual std::unique_ptr<visualization::DrawableBase> ToDrawable(
      ColorRGB color = ColorRGB()) const = 0;

 public:
  static std::unique_ptr<GeometryBase> Create(GeometryType type);
  static std::unique_ptr<GeometryBase> CreateRandom(GeometryType type,
                                                    size_t size);

 protected:
  GeometryType type_;
};

}  // namespace cgzr

#endif  // SRC_COMMON_GEOMETRY_GEOMETRY_BASE_HPP_
