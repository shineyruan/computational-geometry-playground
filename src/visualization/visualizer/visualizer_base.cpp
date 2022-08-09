#include "visualization/visualizer/visualizer_base.hpp"

namespace cgzr {
namespace visualization {

void VisualizerBase::Add(std::unique_ptr<DrawableBase> drawable) {
  // update storage & lookup tables
  drawables_.emplace_back(std::move(drawable));
  DrawableBase* drawable_ptr = drawables_.back().get();
  drawable_by_type_[static_cast<int>(drawable_ptr->Type())].emplace_back(
      drawable_ptr);

  // update world boundaries for scaling in visualization
  world_min_.x() = (world_min_.x() == -std::numeric_limits<double>::infinity())
                       ? drawable_ptr->MinBound().x()
                       : std::min(drawable_ptr->MinBound().x(), world_min_.x());
  world_min_.y() = (world_min_.y() == -std::numeric_limits<double>::infinity())
                       ? drawable_ptr->MinBound().y()
                       : std::min(drawable_ptr->MinBound().y(), world_min_.y());
  world_max_.x() = (world_max_.x() == std::numeric_limits<double>::infinity())
                       ? drawable_ptr->MaxBound().x()
                       : std::max(drawable_ptr->MaxBound().x(), world_max_.x());
  world_max_.y() = (world_max_.y() == std::numeric_limits<double>::infinity())
                       ? drawable_ptr->MaxBound().y()
                       : std::max(drawable_ptr->MaxBound().y(), world_max_.y());
}
}  // namespace visualization
}  // namespace cgzr
