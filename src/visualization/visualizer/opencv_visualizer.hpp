#ifndef __VISUALIZATION_VISUALIZER_OPENCV_VISUALIZER__HPP__
#define __VISUALIZATION_VISUALIZER_OPENCV_VISUALIZER__HPP__

#include "visualization/visualizer/visualizer_base.hpp"

namespace cgzr {
namespace visualization {

class OpenCVVisualizer : public VisualizerBase {
public:
  void Visualize() const override {}
};

}  // namespace visualization
}  // namespace cgzr

#endif /* __VISUALIZATION_VISUALIZER_OPENCV_VISUALIZER__HPP__ */
