#include "lines2d.hpp"

#include <spdlog/spdlog.h>

#include "visualization/drawable/line_string.hpp"

namespace cgzr {

std::unique_ptr<GeometryBase> Lines2D::Clone() const {
  return std::make_unique<Lines2D>(endpoints_, lines_);
}

std::unique_ptr<visualization::DrawableBase> Lines2D::ToDrawable() const {
  auto line_string = std::make_unique<visualization::LineString>();
  line_string->UpdateVertices(endpoints_);
  line_string->UpdateEdges(lines_);
  return line_string;
}

void Lines2D::UpdatePoints(const std::vector<Eigen::Vector2d>& endpoints) {
  endpoints_ = endpoints;
}

bool Lines2D::UpdateLineAsIndices(
    const std::vector<std::pair<size_t, size_t>>& lines) {
  size_t num_points = endpoints_.size();

  for (const auto& [idx_p1, idx_p2] : lines) {
    if (idx_p1 >= num_points) {
      SPDLOG_ERROR(
          "1st idx of line exceeds the total number of points: {} > {}", idx_p1,
          num_points);
      return false;
    }
    if (idx_p2 >= num_points) {
      SPDLOG_ERROR(
          "2nd idx of line exceeds the total number of points: {} > {}", idx_p2,
          num_points);
      return false;
    }
  }

  lines_ = lines;
  return true;
}

}  // namespace cgzr
