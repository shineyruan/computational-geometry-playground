#ifndef __COMMON_GEOMETRY_POINT2D__HPP__
#define __COMMON_GEOMETRY_POINT2D__HPP__

#include <vector>

#include "geometry_base.hpp"
#include "utils/include_eigen.hpp"

namespace cgzr {

// TODO refactor points as point
class Points : public GeometryBase {
public:
  Points() : GeometryBase(GeometryType::POINTS) {}
  Points(const std::vector<Eigen::Vector2d>& points)
      : GeometryBase(GeometryType::POINTS), positions_(points) {}

  // random initialization with designated size
  Points(size_t num_points);

  // get point coordinates
  const std::vector<Eigen::Vector2d>& GetCoordinates() const;

  size_t Size() const override { return positions_.size(); }
  std::unique_ptr<GeometryBase> Clone() const override;

  std::unique_ptr<visualization::DrawableBase> ToDrawable() const override;

private:
  std::vector<Eigen::Vector2d> positions_;
};

}  // namespace cgzr

#endif /* __COMMON_GEOMETRY_POINT2D__HPP__ */
