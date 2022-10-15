#ifndef __COMMON_GEOMETRY_LINES_2D__HPP__
#define __COMMON_GEOMETRY_LINES_2D__HPP__

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
  std::unique_ptr<visualization::DrawableBase> ToDrawable() const override;

  void UpdatePoints(const std::vector<Eigen::Vector2d>& endpoints);
  bool UpdateLineSegments(const std::vector<std::pair<size_t, size_t>>& lines);

private:
  std::vector<Eigen::Vector2d> endpoints_;
  std::vector<std::pair<size_t, size_t>> lines_;
};

}  // namespace cgzr

#endif /* __COMMON_GEOMETRY_LINES_2D__HPP__ */
