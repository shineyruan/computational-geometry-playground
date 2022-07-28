#ifndef __VISUALIZATION_VISUALIZER_VISUALIZER_BASE__HPP__
#define __VISUALIZATION_VISUALIZER_VISUALIZER_BASE__HPP__

#include <memory>
#include <unordered_map>
#include <vector>

#include "visualization/drawable/drawable_base.hpp"

namespace cgzr {
namespace visualization {

class VisualizerBase {
public:
  void Add(const DrawableBase* drawable);

  virtual void Visualize() const = 0;

protected:
  std::vector<std::unique_ptr<DrawableBase>> drawables_;
  std::unordered_map<int, std::vector<const DrawableBase*>> drawable_by_type_;
};

}  // namespace visualization
}  // namespace cgzr

#endif /* __VISUALIZATION_VISUALIZER_VISUALIZER_BASE__HPP__ */
