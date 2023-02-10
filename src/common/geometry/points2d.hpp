#ifndef SRC_COMMON_GEOMETRY_POINTS2D_HPP_
#define SRC_COMMON_GEOMETRY_POINTS2D_HPP_

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

  std::unique_ptr<visualization::DrawableBase> ToDrawable(
      ColorRGB color = ColorRGB()) const override;

 private:
  std::vector<Eigen::Vector2d> positions_;
};

}  // namespace cgzr

#endif  // SRC_COMMON_GEOMETRY_POINTS2D_HPP_
