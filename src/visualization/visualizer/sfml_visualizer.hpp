#ifndef SRC_VISUALIZATION_VISUALIZER_SFML_VISUALIZER_HPP_
#define SRC_VISUALIZATION_VISUALIZER_SFML_VISUALIZER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "visualization/visualizer/visualizer_base.hpp"

namespace cgzr {
namespace visualization {

class SfmlVisualizer : public VisualizerBase {
 public:
  SfmlVisualizer();

  void Visualize() override;

 private:
  void DrawPointSet(sf::RenderWindow& window, const DrawableBase* drawable,
                    const Eigen::Vector2d offset,
                    const Eigen::Vector2d scaling) const;
  void DrawLineString(sf::RenderWindow& window, const DrawableBase* drawable,
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

 private:
  static constexpr unsigned int kCanvasWidth = 800;
  static constexpr unsigned int kCanvasHeight = 600;
  static constexpr unsigned int kCanvasWidthBuffer = 10;
  static constexpr unsigned int kCanvasHeightBuffer = 10;

 private:
  sf::RenderWindow window_;
};

}  // namespace visualization
}  // namespace cgzr

#endif  // SRC_VISUALIZATION_VISUALIZER_SFML_VISUALIZER_HPP_
