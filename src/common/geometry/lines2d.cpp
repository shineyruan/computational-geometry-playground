#include "lines2d.hpp"

#include <spdlog/spdlog.h>

#include "visualization/drawable/line_string.hpp"

namespace cgzr {

Lines2d::Lines2d(size_t num_lines) : GeometryBase(GeometryType::LINES_2D) {
  endpoints_.reserve(2 * num_lines);
  for (size_t i = 0; i < num_lines; ++i) {
    endpoints_.push_back(Eigen::Vector2d::Random());
    endpoints_.push_back(Eigen::Vector2d::Random());
    lines_.emplace_back(2 * i, 2 * i + 1);
  }
}

std::unique_ptr<GeometryBase> Lines2d::Clone() const {
  return std::make_unique<Lines2d>(endpoints_, lines_);
}

std::unique_ptr<visualization::DrawableBase> Lines2d::ToDrawable(
    ColorRGB color) const {
  auto line_string = std::make_unique<visualization::LineString>(color);
  line_string->UpdateVertices(endpoints_);
  line_string->UpdateEdges(lines_);
  return line_string;
}

void Lines2d::UpdatePoints(const std::vector<Eigen::Vector2d>& endpoints) {
  endpoints_ = endpoints;
}

bool Lines2d::UpdateLineAsIndices(
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

std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>> Lines2d::Lines()
    const {
  std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>> result;
  for (const auto& line : lines_) {
    auto [p1, p2] = line;
    result.emplace_back(std::make_pair(endpoints_.at(p1), endpoints_.at(p2)));
  }
  return result;
}

}  // namespace cgzr
