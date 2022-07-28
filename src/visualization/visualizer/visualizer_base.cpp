#include "visualization/visualizer/visualizer_base.hpp"

namespace cgzr {
namespace visualization {

void VisualizerBase::Add(const DrawableBase* drawable) {
  drawables_.emplace_back(std::make_unique<DrawableBase>(*drawable));
  drawable_by_type_[static_cast<int>(drawable->Type())].emplace_back(
      drawables_.back().get());
}
}  // namespace visualization
}  // namespace cgzr
