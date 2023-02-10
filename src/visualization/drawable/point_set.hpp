#ifndef SRC_VISUALIZATION_DRAWABLE_POINT_SET_HPP_
#define SRC_VISUALIZATION_DRAWABLE_POINT_SET_HPP_

#include "drawable_base.hpp"

namespace cgzr {
namespace visualization {

class PointSet : public DrawableBase {
 public:
  PointSet(ColorRGB color = ColorRGB())
      : DrawableBase(DrawableType::POINT_SET, color) {}

  bool UpdateVertices(const std::vector<Eigen::Vector2d>& vertices);
  const std::vector<Eigen::Vector2d>& Vertices() const;

 private:
  std::vector<Eigen::Vector2d> vertices_;
};

}  // namespace visualization
}  // namespace cgzr

#endif  // SRC_VISUALIZATION_DRAWABLE_POINT_SET_HPP_
