#ifndef SRC_VISUALIZATION_VISUALIZER_SCIPLOT_VISUALIZER_HPP_
#define SRC_VISUALIZATION_VISUALIZER_SCIPLOT_VISUALIZER_HPP_

#include <sciplot/sciplot.hpp>

#include "visualization/visualizer/visualizer_base.hpp"

namespace cgzr {
namespace visualization {

class SciplotVisualizer : public VisualizerBase {
 public:
  void Visualize() override;

 private:
  static constexpr unsigned int kCanvasWidth = 500;
  static constexpr unsigned int kCanvasHeight = 500;
  static constexpr double kPlotExtendRatioX = 0.2;
  static constexpr double kPlotExtendRatioY = 0.2;

  void DrawPointSet(sciplot::Plot2D& plot, const DrawableBase* drawable) const;
  void DrawLineString(sciplot::Plot2D& plot,
                      const DrawableBase* drawable) const;
};

}  // namespace visualization
}  // namespace cgzr

#endif  // SRC_VISUALIZATION_VISUALIZER_SCIPLOT_VISUALIZER_HPP_
