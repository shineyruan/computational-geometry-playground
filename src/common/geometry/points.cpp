#include "points.hpp"

#include "visualization/drawable/point_set.hpp"

namespace cgzr {

std::unique_ptr<visualization::DrawableBase> Points::ToDrawable() const {
  auto point_set = std::make_unique<visualization::PointSet>();
  point_set->UpdateVertices(positions_);
  return point_set;
}

}  // namespace cgzr
