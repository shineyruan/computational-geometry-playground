/**
 * @file test_sfml.cpp
 *
 * @brief Code copied and modified from
 * https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php
 */

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <optional>

int main() {
  // ----------- Create Shapes -----------
  // create circle shape
  sf::CircleShape circle(50.f);
  circle.setRadius(100.f);
  circle.setPointCount(400);
  circle.setFillColor(sf::Color(150, 50, 250));
  circle.move(sf::Vector2f{50.f, 50.f});
  // set a 10-pixel wide orange outline
  circle.setOutlineThickness(10.f);
  circle.setOutlineColor(sf::Color(250, 150, 100));

  // create a rectangle shape
  // define a 120x50 rectangle
  sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
  // change the size to 100x100
  rectangle.setSize(sf::Vector2f(200.f, 100.f));
  rectangle.setFillColor(sf::Color(0, 255, 0));
  rectangle.move(sf::Vector2f{400.f, 400.f});

  // create a line
  sf::Vertex line[] = {sf::Vertex{sf::Vector2f{10.f, 10.f}},
                       sf::Vertex{sf::Vector2f{150.f, 150.f}}};

  // ----------- Create Window -----------
  sf::ContextSettings settings;
  settings.antiAliasingLevel = 8;
  // create the window
  sf::RenderWindow window(sf::VideoMode(sf::Vector2u{800, 600}),
                          "Visualization", sf::State::Windowed, settings);

  // ----------- Main Loop -----------
  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (const std::optional<sf::Event> event = window.pollEvent()) {
      // "close requested" event: we close the window
      bool button_close = event->is<sf::Event::Closed>();
      bool key_q_or_esc = event->is<sf::Event::KeyPressed>() &&
                          (event->getIf<sf::Event::KeyPressed>()->code ==
                               sf::Keyboard::Key::Q ||
                           event->getIf<sf::Event::KeyPressed>()->code ==
                               sf::Keyboard::Key::Escape);
      if (button_close || key_q_or_esc) {
        window.close();
      }
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw everything here...
    window.draw(circle);
    window.draw(rectangle);
    window.draw(line, 2, sf::PrimitiveType::Lines);

    // end the current frame
    window.display();
  }

  return 0;
}
