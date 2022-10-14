#include "points.hpp"

#include "visualization/drawable/point_set.hpp"

namespace cgzr {

std::unique_ptr<GeometryBase> Points::Clone() const {
  return std::make_unique<Points>(positions_);
}

const std::vector<Eigen::Vector2d>& Points::GetCoordinates() const {
  return positions_;
}

Points::Points(size_t num_points) : GeometryBase(GeometryType::POINTS) {
  positions_.reserve(num_points);
  for (size_t i = 0; i < num_points; ++i) {
    positions_.push_back(Eigen::Vector2d::Random());
  }
}

std::unique_ptr<visualization::DrawableBase> Points::ToDrawable() const {
  auto point_set = std::make_unique<visualization::PointSet>();
  point_set->UpdateVertices(positions_);
  return point_set;
}

}  // namespace cgzr
