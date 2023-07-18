/**
 * @file test_sfml.cpp
 *
 * @brief Code copied and modified from
 * https://www.sfml-dev.org/tutorials/2.6/graphics-draw.php
 */

#include <SFML/Graphics.hpp>

int main() {
  // ----------- Create Shapes -----------
  // create circle shape
  sf::CircleShape circle(50.f);
  circle.setRadius(100.f);
  circle.setPointCount(400);
  circle.setFillColor(sf::Color(150, 50, 250));
  circle.move(50.f, 50.f);
  // set a 10-pixel wide orange outline
  circle.setOutlineThickness(10.f);
  circle.setOutlineColor(sf::Color(250, 150, 100));

  // create a rectangle shape
  // define a 120x50 rectangle
  sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
  // change the size to 100x100
  rectangle.setSize(sf::Vector2f(200.f, 100.f));
  rectangle.setFillColor(sf::Color(0, 255, 0));
  rectangle.move(400.f, 400.f);

  // create a line
  sf::Vertex line[] = {sf::Vertex(sf::Vector2f(10.f, 10.f)),
                       sf::Vertex(sf::Vector2f(150.f, 150.f))};

  // ----------- Create Window -----------
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Visualization",
                          sf::Style::Close, settings);

  // ----------- Main Loop -----------
  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      bool button_close = event.type == sf::Event::Closed;
      bool key_q_or_esc = event.type == sf::Event::KeyPressed &&
                          (event.key.code == sf::Keyboard::Q ||
                           event.key.code == sf::Keyboard::Escape);
      if (button_close || key_q_or_esc) {
        window.close();
      }
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw everything here...
    window.draw(circle);
    window.draw(rectangle);
    window.draw(line, 2, sf::Lines);

    // end the current frame
    window.display();
  }

  return 0;
}
