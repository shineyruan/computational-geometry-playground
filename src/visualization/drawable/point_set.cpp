#include "point_set.hpp"

namespace cgzr {
namespace visualization {

bool PointSet::UpdateVertices(const std::vector<Eigen::Vector2d>& vertices) {
  vertices_ = vertices;

  // update bounds
  auto comp_x = [](Eigen::Vector2d p1, Eigen::Vector2d p2) {
    return p1.x() < p2.x();
  };
  auto comp_y = [](Eigen::Vector2d p1, Eigen::Vector2d p2) {
    return p1.y() < p2.y();
  };
  min_coords_.x() =
      std::min_element(vertices_.begin(), vertices_.end(), comp_x)->x();
  min_coords_.y() =
      std::min_element(vertices_.begin(), vertices_.end(), comp_y)->y();
  max_coords_.x() =
      std::max_element(vertices_.begin(), vertices_.end(), comp_x)->x();
  max_coords_.y() =
      std::max_element(vertices_.begin(), vertices_.end(), comp_y)->y();

  return true;
}

const std::vector<Eigen::Vector2d>& PointSet::Vertices() const {
  return vertices_;
}

}  // namespace visualization
}  // namespace cgzr
