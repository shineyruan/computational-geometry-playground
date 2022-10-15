#ifndef __COMMON_GEOMETRY_POINT2D__HPP__
#define __COMMON_GEOMETRY_POINT2D__HPP__

#include <vector>

#include "geometry_base.hpp"
#include "utils/include_eigen.hpp"

namespace cgzr {

class Points2d : public GeometryBase {
public:
  Points2d() : GeometryBase(GeometryType::POINTS_2D) {}
  Points2d(const std::vector<Eigen::Vector2d>& points)
      : GeometryBase(GeometryType::POINTS_2D), positions_(points) {}

  // random initialization with designated size
  Points2d(size_t num_points);

  // get points in std::vector
  const std::vector<Eigen::Vector2d>& AsVector2ds() const;

  size_t Size() const override { return positions_.size(); }
  std::unique_ptr<GeometryBase> Clone() const override;

  std::unique_ptr<visualization::DrawableBase> ToDrawable() const override;

private:
  std::vector<Eigen::Vector2d> positions_;
};

}  // namespace cgzr

#endif /* __COMMON_GEOMETRY_POINT2D__HPP__ */
