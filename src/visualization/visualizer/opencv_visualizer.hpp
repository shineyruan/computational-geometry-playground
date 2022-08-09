#ifndef __VISUALIZATION_VISUALIZER_OPENCV_VISUALIZER__HPP__
#define __VISUALIZATION_VISUALIZER_OPENCV_VISUALIZER__HPP__

#include <opencv2/core/core.hpp>

#include "visualization/visualizer/visualizer_base.hpp"

namespace cgzr {
namespace visualization {

class OpenCVVisualizer : public VisualizerBase {
public:
  void Visualize() const override;

private:
  static constexpr unsigned int IMAGE_WIDTH = 500;
  static constexpr unsigned int IMAGE_HEIGHT = 500;
  static constexpr unsigned int IMAGE_WIDTH_BUFFER = 10;
  static constexpr unsigned int IMAGE_HEIGHT_BUFFER = 10;
  static constexpr int LINE_THICKNESS = 1;
  static constexpr int POINT_RADIUS = 2;

  void DrawPointSet(cv::Mat& canvas, const DrawableBase* drawable,
                    const Eigen::Vector2d offset,
                    const Eigen::Vector2d scaling) const;
  void DrawLineString(cv::Mat& canvas, const DrawableBase* drawable,
                      const Eigen::Vector2d offset,
                      const Eigen::Vector2d scaling) const;

  /**
   * @brief Calculates the offset and scaling (pixel-wise) that fits all the
   * shapes into the fixed-sized canvas.
   *
   * pixel_coord = (original - offset) * scaling
   *
   * @return [offset, scaling]
   */
  std::pair<Eigen::Vector2d, Eigen::Vector2d> ComputeOffsetAndScaling() const;
};

}  // namespace visualization
}  // namespace cgzr

#endif /* __VISUALIZATION_VISUALIZER_OPENCV_VISUALIZER__HPP__ */
