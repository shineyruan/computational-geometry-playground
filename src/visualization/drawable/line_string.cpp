#include "line_string.hpp"

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace cgzr {
namespace visualization {

bool LineString::UpdateVertices(const std::vector<Eigen::Vector2d>& vertices) {
  vertices_ = vertices;

  // update vertex pool
  vertex_pool_.clear();
  for (const auto& vertex : vertices) {
    vertex_pool_.emplace(vertex);
  }

  return true;
}

bool LineString::UpdateEdges(
    const std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>>& edges) {
  // sanity check
  for (const auto& edge : edges) {
    if (vertex_pool_.find(edge.first) == vertex_pool_.end()) {
      spdlog::error(
          "Invalid edge: edge vertex {} does not match stored vertex list",
          edge.first);
      return false;
    }
    if (vertex_pool_.find(edge.second) == vertex_pool_.end()) {
      spdlog::error(
          "Invalid edge: edge vertex {} does not match stored vertex list",
          edge.second);
      return false;
    }
  }

  edges_ = edges;
  return true;
}

const std::vector<Eigen::Vector2d>& LineString::Vertices() const {
  return vertices_;
}

const std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>>&
LineString::Edges() const {
  return edges_;
}

}  // namespace visualization
}  // namespace cgzr
