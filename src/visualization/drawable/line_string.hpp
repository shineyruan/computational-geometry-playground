#ifndef __VISUALIZATION_DRAWABLE_LINE_STRING__HPP__
#define __VISUALIZATION_DRAWABLE_LINE_STRING__HPP__

#include "drawable_base.hpp"

template <>
struct std::hash<Eigen::Vector2d> {
  size_t operator()(const Eigen::Vector2d& pt_2d) const noexcept {
    return std::hash<double>()(pt_2d.x());
  }
};

namespace cgzr {
namespace visualization {

class LineString : public DrawableBase {
public:
  LineString() : DrawableBase(DrawableType::LINE_STRING) {}

  bool UpdateVertices(const std::vector<Eigen::Vector2d>& vertices);
  const std::vector<Eigen::Vector2d>& Vertices() const;

  bool UpdateEdges(
      const std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>>& edges);
  const std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>>& Edges() const;

protected:
  std::vector<Eigen::Vector2d> vertices_;
  std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>> edges_;

  std::unordered_set<Eigen::Vector2d> vertex_pool_;
};

}  // namespace visualization
}  // namespace cgzr

#endif /* __VISUALIZATION_DRAWABLE_LINE_STRING__HPP__ */
