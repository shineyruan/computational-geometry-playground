#include "point_set.hpp"

namespace cgzr {
namespace visualization {

bool PointSet::UpdateVertices(const std::vector<Eigen::Vector2d>& vertices) {
  vertices_ = vertices;
  return true;
}

const std::vector<Eigen::Vector2d>& PointSet::Vertices() const {
  return vertices_;
}

}  // namespace visualization
}  // namespace cgzr
