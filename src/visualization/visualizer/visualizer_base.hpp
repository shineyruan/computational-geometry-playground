#ifndef __VISUALIZATION_VISUALIZER_VISUALIZER_BASE__HPP__
#define __VISUALIZATION_VISUALIZER_VISUALIZER_BASE__HPP__

/**
 * @file visualizer_base.hpp
 * @author Zhihao Ruan (shineyruan@gmail.com)
 * @brief A Visualizer should be able to visualize every Drawable object on a
 *        reasonable scale.
 */

#include <memory>
#include <unordered_map>
#include <vector>

#include "visualization/drawable/drawable_base.hpp"

namespace cgzr {
namespace visualization {

class VisualizerBase {
public:
  VisualizerBase()
      : world_min_(-std::numeric_limits<double>::infinity(),
                   -std::numeric_limits<double>::infinity()),
        world_max_(std::numeric_limits<double>::infinity(),
                   std::numeric_limits<double>::infinity()) {}
  virtual ~VisualizerBase() {}
  virtual void Visualize() const = 0;

  /**
   * @brief Adds the drawable into Visualizer and destroys it
   */
  void Add(std::unique_ptr<DrawableBase> drawable);

protected:
  std::vector<std::unique_ptr<DrawableBase>> drawables_;
  std::unordered_map<int, std::vector<const DrawableBase*>> drawable_by_type_;

  // world boundaries
  //  visualizer should be capable of scaling the shapes to appropriate visual
  //  size
  Eigen::Vector2d world_min_;
  Eigen::Vector2d world_max_;
};

}  // namespace visualization
}  // namespace cgzr

#endif /* __VISUALIZATION_VISUALIZER_VISUALIZER_BASE__HPP__ */
