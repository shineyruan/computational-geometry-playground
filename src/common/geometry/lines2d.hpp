#ifndef SRC_COMMON_GEOMETRY_LINES2D_HPP_
#define SRC_COMMON_GEOMETRY_LINES2D_HPP_

#include "geometry_base.hpp"

namespace cgzr {

class Lines2d : public GeometryBase {
 public:
  Lines2d() : GeometryBase(GeometryType::LINES_2D) {}
  Lines2d(const std::vector<Eigen::Vector2d>& endpoints,
          const std::vector<std::pair<size_t, size_t>>& lines)
      : GeometryBase(GeometryType::LINES_2D),
        endpoints_(endpoints),
        lines_(lines) {}

  // random initialization with designated size
  Lines2d(size_t num_lines);

  size_t Size() const override { return lines_.size(); }
  std::unique_ptr<GeometryBase> Clone() const override;
  std::unique_ptr<visualization::DrawableBase> ToDrawable(
      ColorRGB color = ColorRGB()) const override;

  void UpdatePoints(const std::vector<Eigen::Vector2d>& endpoints);
  bool UpdateLineAsIndices(const std::vector<std::pair<size_t, size_t>>& lines);

  std::vector<std::pair<Eigen::Vector2d, Eigen::Vector2d>> Lines() const;

 private:
  std::vector<Eigen::Vector2d> endpoints_;
  std::vector<std::pair<size_t, size_t>> lines_;
};

}  // namespace cgzr

#endif  // SRC_COMMON_GEOMETRY_LINES2D_HPP_
