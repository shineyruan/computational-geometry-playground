#ifndef SRC_VISUALIZATION_DRAWABLE_DRAWABLE_BASE_HPP_
#define SRC_VISUALIZATION_DRAWABLE_DRAWABLE_BASE_HPP_

/**
 * @file drawable_base.hpp
 * @author Zhihao Ruan (shineyruan@gmail.com)
 * @brief A Drawable is NOT a geometry. It is dedicated only for drawing and
 *        should only be constructed before Visualizer.
 */

#include <unordered_set>
#include <vector>

#include "drawable_type.hpp"
#include "utils/include_eigen.hpp"
#include "visualization/color/colors.hpp"

namespace cgzr {
namespace visualization {

class DrawableBase {
 public:
  DrawableBase(DrawableType type = DrawableType::UNSUPPORTED,
               ColorRGB color = ColorRGB())
      : type_(type),
        color_(color),
        min_coords_(-std::numeric_limits<double>::infinity(),
                    -std::numeric_limits<double>::infinity()),
        max_coords_(std::numeric_limits<double>::infinity(),
                    std::numeric_limits<double>::infinity()) {}
  virtual ~DrawableBase() {}

  DrawableType Type() const { return type_; }
  Eigen::Vector2d MinBound() const { return min_coords_; }
  Eigen::Vector2d MaxBound() const { return max_coords_; }
  ColorRGB Color() const { return color_; }

  bool HasMinBound() const {
    return (min_coords_.x() > -std::numeric_limits<double>::infinity()) &&
           (min_coords_.y() > -std::numeric_limits<double>::infinity());
  }
  bool HasMaxBound() const {
    return (max_coords_.x() < std::numeric_limits<double>::infinity()) &&
           (max_coords_.y() < std::numeric_limits<double>::infinity());
  }
  bool HasBothBounds() const { return HasMinBound() && HasMaxBound(); }

 protected:
  DrawableType type_;

  // color
  ColorRGB color_;

  // shape boundary
  Eigen::Vector2d min_coords_;
  Eigen::Vector2d max_coords_;
};

}  // namespace visualization
}  // namespace cgzr

#endif  // SRC_VISUALIZATION_DRAWABLE_DRAWABLE_BASE_HPP_
