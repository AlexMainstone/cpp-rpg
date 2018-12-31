#pragma once

#include <SFML/Graphics.hpp>

class Camera {
    public:
        Camera(sf::View v = sf::View());
        void handleEvent(sf::Event e);
        sf::View getView();
    private:
        sf::View view;

        // Drag handling variables
        bool dragging;
        sf::Vector2i drag_position;
};