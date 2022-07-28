#ifndef __VISUALIZATION_DRAWABLE_LINE_STRING__HPP__
#define __VISUALIZATION_DRAWABLE_LINE_STRING__HPP__

#include "drawable_base.hpp"

namespace cgzr {
namespace visualization {

class LineString : public DrawableBase {
public:
  LineString() : DrawableBase(DrawableType::LINE_STRING) {}

  bool UpdateVertices(const std::vector<Eigen::Vector2d>& vertices);
  const std::vector<Eigen::Vector2d>& Vertices() const;

  bool IsEdge(Eigen::Vector2d p1, Eigen::Vector2d p2) const;
  bool AddEdge(Eigen::Vector2d p1, Eigen::Vector2d p2);
  bool AddEdge(size_t p1_idx, size_t p2_idx);
  bool UpdateEdges(const std::vector<std::pair<size_t, size_t>>& edges);
  const std::vector<std::pair<size_t, size_t>>& Edges() const;

private:
  std::vector<Eigen::Vector2d> vertices_;
  std::vector<std::pair<size_t, size_t>> edges_;
  std::vector<std::vector<size_t>> neighbors_;
};

}  // namespace visualization
}  // namespace cgzr

#endif /* __VISUALIZATION_DRAWABLE_LINE_STRING__HPP__ */
