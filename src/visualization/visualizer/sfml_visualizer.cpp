#include "sfml_visualizer.hpp"

#include <SFML/Graphics.hpp>

#include "logging/logging.hpp"
#include "visualization/drawable/line_string.hpp"
#include "visualization/drawable/point_set.hpp"

namespace cgzr {
namespace visualization {

namespace {
inline sf::Color ToSfmlColor(const ColorRGB& color) {
  sf::Uint8 r = static_cast<sf::Uint8>(color.r);
  sf::Uint8 g = static_cast<sf::Uint8>(color.g);
  sf::Uint8 b = static_cast<sf::Uint8>(color.b);
  return sf::Color(r, g, b);
}
}  // namespace

SfmlVisualizer::SfmlVisualizer() : VisualizerBase() {
  // antialiasing
  sf::ContextSettings window_settings;
  window_settings.antialiasingLevel = 5;

  window_.create(sf::VideoMode(kCanvasWidth + 2 * kCanvasWidthBuffer,
                               kCanvasHeight + 2 * kCanvasHeightBuffer),
                 "Visualization", sf::Style::Close, window_settings);
}

void SfmlVisualizer::Visualize() {
  // Compute offset and scaling
  auto [offset, scaling] = ComputeOffsetAndScaling();

  // Main loop
  while (window_.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window_.pollEvent(event)) {
      // "close requested" event: we close the window
      bool button_close = event.type == sf::Event::Closed;
      bool key_q_or_esc = event.type == sf::Event::KeyPressed &&
                          (event.key.code == sf::Keyboard::Q ||
                           event.key.code == sf::Keyboard::Escape);
      if (button_close || key_q_or_esc) {
        window_.close();
      }
    }

    // clear the window with white color
    window_.clear(sf::Color::White);

    // draw everything here...
    for (const auto& drawable : drawables_) {
      switch (drawable->Type()) {
        case DrawableType::POINT_SET:
          DrawPointSet(window_, drawable.get(), offset, scaling);
          break;

        case DrawableType::LINE_STRING:
          DrawLineString(window_, drawable.get(), offset, scaling);

        default:
          break;
      }
    }

    // end the current frame
    window_.display();
  }
}

void SfmlVisualizer::DrawPointSet(sf::RenderWindow& window,
                                  const DrawableBase* drawable,
                                  const Eigen::Vector2d offset,
                                  const Eigen::Vector2d scaling) const {
  const auto& point_set = static_cast<const PointSet*>(drawable);
  if (point_set == nullptr) {
    SPDLOG_ERROR("invalid point set as a drawable");
  }
  constexpr float kCircleRadius = 3.f;
  for (const auto& vert : point_set->Vertices()) {
    sf::CircleShape dot(kCircleRadius);
    dot.setFillColor(ToSfmlColor(point_set->Color()));
    // SFML draws circle in a way that centers at (kCircleRadius, kCircleRadius)
    float vert_x = static_cast<float>((vert.x() - offset.x()) * scaling.x()) -
                   kCircleRadius;
    float vert_y = static_cast<float>((vert.y() - offset.y()) * scaling.y()) -
                   kCircleRadius;
    dot.move(kCanvasWidthBuffer + vert_x, kCanvasHeightBuffer + vert_y);
    window.draw(dot);
  }
}

void SfmlVisualizer::DrawLineString(sf::RenderWindow& window,
                                    const DrawableBase* drawable,
                                    const Eigen::Vector2d offset,
                                    const Eigen::Vector2d scaling) const {
  const auto& line_string = static_cast<const LineString*>(drawable);
  if (line_string == nullptr) {
    SPDLOG_ERROR("invalid line string as a drawable");
  }

  sf::Color color = ToSfmlColor(line_string->Color());

  // SFML draws lines in {v0,v1}, {v2,v3}, {v4,v5} ...
  std::vector<sf::Vertex> ordered_vertices;
  ordered_vertices.reserve(2 * line_string->Edges().size());

  for (const auto& [start, end] : line_string->Edges()) {
    const auto& start_v = line_string->Vertices().at(start);
    auto start_pos = sf::Vector2f(
        kCanvasWidthBuffer +
            static_cast<float>((start_v.x() - offset.x()) * scaling.x()),
        kCanvasHeightBuffer +
            static_cast<float>((start_v.y() - offset.y()) * scaling.y()));
    ordered_vertices.emplace_back(start_pos, color);

    const auto& end_v = line_string->Vertices().at(end);
    auto end_pos = sf::Vector2f(
        kCanvasWidthBuffer +
            static_cast<float>((end_v.x() - offset.x()) * scaling.x()),
        kCanvasHeightBuffer +
            static_cast<float>((end_v.y() - offset.y()) * scaling.y()));
    ordered_vertices.emplace_back(end_pos, color);
  }

  window.draw(ordered_vertices.data(), ordered_vertices.size(), sf::Lines);
}

std::pair<Eigen::Vector2d, Eigen::Vector2d>
SfmlVisualizer::ComputeOffsetAndScaling() const {
  Eigen::Vector2d offset = world_min_;
  double scaling = std::min(kCanvasWidth / (world_max_ - world_min_).x(),
                            kCanvasHeight / (world_max_ - world_min_).y());
  return std::make_pair(offset, Eigen::Vector2d(scaling, scaling));
}

}  // namespace visualization
}  // namespace cgzr
