#include "line_string.hpp"

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace cgzr {
namespace visualization {

bool LineString::UpdateVertices(const std::vector<Eigen::Vector2d>& vertices) {
  vertices_ = vertices;

  // reinit neighbors
  neighbors_.clear();
  neighbors_.resize(vertices_.size());

  return true;
}

bool LineString::UpdateEdges(
    const std::vector<std::pair<size_t, size_t>>& edges) {
  size_t vert_len = vertices_.size();

  // sanity check
  for (const auto& edge : edges) {
    if (edge.first >= vert_len) {
      spdlog::error("1st index of edge {} is greater than vertex number {}",
                    edge.first, vert_len);
      return false;
    }
    if (edge.second >= vert_len) {
      spdlog::error("2nd index of edge {} is greater than vertex number {}",
                    edge.second, vert_len);
      return false;
    }
  }

  edges_ = edges;
  return true;
}

bool LineString::AddEdge(Eigen::Vector2d p1, Eigen::Vector2d p2) {
  // sanity check
  auto p1_ptr = std::find(vertices_.begin(), vertices_.end(), p1);
  if (p1_ptr == vertices_.end()) {
    spdlog::error("p1 is not a vertex: {}", p1.transpose());
    return false;
  }
  size_t p1_idx = p1_ptr - vertices_.begin();

  auto p2_ptr = std::find(vertices_.begin(), vertices_.end(), p2);
  if (std::find(vertices_.begin(), vertices_.end(), p2) == vertices_.end()) {
    spdlog::error("p2 is not a vertex: {}", p2.transpose());
    return false;
  }
  size_t p2_idx = p2_ptr - vertices_.begin();

  edges_.emplace_back(p1_idx, p2_idx);
  neighbors_[p1_idx].push_back(p2_idx);
  neighbors_[p2_idx].push_back(p1_idx);
  return true;
}

bool LineString::AddEdge(size_t p1_idx, size_t p2_idx) {
  if (p1_idx >= vertices_.size()) {
    spdlog::error("p1_idx {} out of bound {}", p1_idx, vertices_.size());
    return false;
  }
  if (p2_idx >= vertices_.size()) {
    spdlog::error("p2_idx {} out of bound {}", p2_idx, vertices_.size());
    return false;
  }

  edges_.emplace_back(p1_idx, p2_idx);
  neighbors_[p1_idx].push_back(p2_idx);
  neighbors_[p2_idx].push_back(p1_idx);
  return true;
}

const std::vector<Eigen::Vector2d>& LineString::Vertices() const {
  return vertices_;
}

bool LineString::IsEdge(Eigen::Vector2d p1, Eigen::Vector2d p2) const {
  auto p1_ptr = std::find(vertices_.begin(), vertices_.end(), p1);
  if (p1_ptr == vertices_.end()) {
    spdlog::error("p1 is not a vertex: {}", p1.transpose());
    return false;
  }
  size_t p1_idx = p1_ptr - vertices_.begin();

  auto p2_ptr = std::find(vertices_.begin(), vertices_.end(), p2);
  if (std::find(vertices_.begin(), vertices_.end(), p2) == vertices_.end()) {
    spdlog::error("p2 is not a vertex: {}", p2.transpose());
    return false;
  }
  size_t p2_idx = p2_ptr - vertices_.begin();

  bool is_edge = !neighbors_[p1_idx].empty() &&
                 std::find(neighbors_[p1_idx].begin(), neighbors_[p1_idx].end(),
                           p2_idx) == neighbors_[p1_idx].end();
  return is_edge;
}

const std::vector<std::pair<size_t, size_t>>& LineString::Edges() const {
  return edges_;
}

}  // namespace visualization
}  // namespace cgzr
