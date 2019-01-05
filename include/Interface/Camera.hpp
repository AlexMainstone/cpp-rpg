#pragma once

#include <SFML/Graphics.hpp>

class Camera {
    public:
        Camera(sf::View v = sf::View());
        void handleEventWithWindow(sf::Event e, sf::RenderWindow &window);
        sf::View getView();
    private:
        sf::View view;

        float zoom;
        // Drag handling variables
        bool dragging;
        sf::Vector2f drag_position;
};