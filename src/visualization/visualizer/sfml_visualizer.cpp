#include "sfml_visualizer.hpp"

#include <spdlog/spdlog.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <cstdint>
#include <optional>

#include "visualization/drawable/line_string.hpp"
#include "visualization/drawable/point_set.hpp"

namespace cgzr {
namespace visualization {

namespace {
inline sf::Color ToSfmlColor(const ColorRGB& color) {
  uint8_t r = static_cast<uint8_t>(color.r);
  uint8_t g = static_cast<uint8_t>(color.g);
  uint8_t b = static_cast<uint8_t>(color.b);
  return sf::Color(r, g, b);
}
}  // namespace

SfmlVisualizer::SfmlVisualizer() : VisualizerBase() {
  // antialiasing
  sf::ContextSettings window_settings;
  window_settings.antiAliasingLevel = 5;

  window_.create(
      sf::VideoMode(sf::Vector2u{kCanvasWidth + 2 * kCanvasWidthBuffer,
                                 kCanvasHeight + 2 * kCanvasHeightBuffer}),
      "Visualization", sf::State::Windowed, window_settings);
}

void SfmlVisualizer::Visualize() {
  // Compute offset and scaling
  auto [offset, scaling] = ComputeOffsetAndScaling();

  // Main loop
  while (window_.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (const std::optional<sf::Event> event = window_.pollEvent()) {
      // "close requested" event: we close the window
      bool button_close = event->is<sf::Event::Closed>();
      bool key_q_or_esc = event->is<sf::Event::KeyPressed>() &&
                          (event->getIf<sf::Event::KeyPressed>()->code ==
                               sf::Keyboard::Key::Q ||
                           event->getIf<sf::Event::KeyPressed>()->code ==
                               sf::Keyboard::Key::Escape);
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
    dot.move(sf::Vector2f{kCanvasWidthBuffer + vert_x,
                          kCanvasHeightBuffer + vert_y});
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
    const auto start_pos = sf::Vector2f(
        kCanvasWidthBuffer +
            static_cast<float>((start_v.x() - offset.x()) * scaling.x()),
        kCanvasHeightBuffer +
            static_cast<float>((start_v.y() - offset.y()) * scaling.y()));
    ordered_vertices.push_back({start_pos, color});

    const auto& end_v = line_string->Vertices().at(end);
    const auto end_pos = sf::Vector2f(
        kCanvasWidthBuffer +
            static_cast<float>((end_v.x() - offset.x()) * scaling.x()),
        kCanvasHeightBuffer +
            static_cast<float>((end_v.y() - offset.y()) * scaling.y()));
    ordered_vertices.push_back({end_pos, color});
  }

  window.draw(ordered_vertices.data(), ordered_vertices.size(),
              sf::PrimitiveType::Lines);
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
