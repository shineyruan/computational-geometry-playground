#include "points2d.hpp"

#include "visualization/drawable/point_set.hpp"

namespace cgzr {

std::unique_ptr<GeometryBase> Points2d::Clone() const {
  return std::make_unique<Points2d>(positions_);
}

const std::vector<Eigen::Vector2d>& Points2d::AsVector2ds() const {
  return positions_;
}

Points2d::Points2d(size_t num_points) : GeometryBase(GeometryType::POINTS_2D) {
  positions_.reserve(num_points);
  for (size_t i = 0; i < num_points; ++i) {
    positions_.push_back(Eigen::Vector2d::Random());
  }
}

std::unique_ptr<visualization::DrawableBase> Points2d::ToDrawable(
    ColorRGB color) const {
  auto point_set = std::make_unique<visualization::PointSet>(color);
  point_set->UpdateVertices(positions_);
  return point_set;
}

}  // namespace cgzr
