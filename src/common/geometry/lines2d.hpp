#ifndef SRC_COMMON_GEOMETRY_LINES2D_HPP_
#define SRC_COMMON_GEOMETRY_LINES2D_HPP_

#include "geometry_base.hpp"

namespace cgzr {

class Lines2D : public GeometryBase {
 public:
  Lines2D() : GeometryBase(GeometryType::LINES_2D) {}
  Lines2D(const std::vector<Eigen::Vector2d>& endpoints,
          const std::vector<std::pair<size_t, size_t>>& lines)
      : GeometryBase(GeometryType::LINES_2D),
        endpoints_(endpoints),
        lines_(lines) {}

  size_t Size() const override { return lines_.size(); }
  std::unique_ptr<GeometryBase> Clone() const override;
  std::unique_ptr<visualization::DrawableBase> ToDrawable(
      ColorRGB color = ColorRGB()) const override;

  void UpdatePoints(const std::vector<Eigen::Vector2d>& endpoints);
  bool UpdateLineAsIndices(const std::vector<std::pair<size_t, size_t>>& lines);

 private:
  std::vector<Eigen::Vector2d> endpoints_;
  std::vector<std::pair<size_t, size_t>> lines_;
};

}  // namespace cgzr

#endif  // SRC_COMMON_GEOMETRY_LINES2D_HPP_
