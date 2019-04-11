#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera(sf::View v = sf::View());
    void handleEventWithWindow(sf::Event e, sf::RenderWindow &window);
    void update(float dt);
    sf::Vector2i getMousePosition() { return mouse_position; }
    sf::View getView();

private:
    sf::View view;

    sf::Vector2i moving;

    sf::Vector2i mouse_position;

    float zoom;
    // Drag handling variables
    bool dragging;
    sf::Vector2f drag_position;
};