#ifndef SRC_VISUALIZATION_VISUALIZER_SCIPLOT_VISUALIZER_HPP_
#define SRC_VISUALIZATION_VISUALIZER_SCIPLOT_VISUALIZER_HPP_

#include <sciplot/sciplot.hpp>

#include "visualization/visualizer/visualizer_base.hpp"

namespace cgzr {
namespace visualization {

class SciplotVisualizer : public VisualizerBase {
 public:
  void Visualize() const override;

 private:
  static constexpr unsigned int CANVAS_WIDTH = 500;
  static constexpr unsigned int CANVAS_HEIGHT = 500;
  static constexpr double PLOT_X_EXTEND_RATIO = 0.2;
  static constexpr double PLOT_Y_EXTEND_RATIO = 0.2;

  void DrawPointSet(sciplot::Plot2D& plot, const DrawableBase* drawable) const;
  void DrawLineString(sciplot::Plot2D& plot,
                      const DrawableBase* drawable) const;
};

}  // namespace visualization
}  // namespace cgzr

#endif  // SRC_VISUALIZATION_VISUALIZER_SCIPLOT_VISUALIZER_HPP_
