#ifndef __COMMON_GEOMETRY_POINT2D__HPP__
#define __COMMON_GEOMETRY_POINT2D__HPP__

#include <vector>

#include "geometry_base.hpp"
#include "utils/include_eigen.hpp"

namespace cgzr {

class Points : public GeometryBase {
public:
  Points() : GeometryBase(GeometryType::POINTS) {}
  Points(const std::vector<Eigen::Vector2d>& points)
      : GeometryBase(GeometryType::POINTS), positions_(points) {}

  std::unique_ptr<visualization::DrawableBase> ToDrawable() const override;

private:
  std::vector<Eigen::Vector2d> positions_;
};

}  // namespace cgzr

#endif /* __COMMON_GEOMETRY_POINT2D__HPP__ */
