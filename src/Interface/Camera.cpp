#include "Interface/Camera.hpp"

Camera::Camera(sf::View v) {
    view = v;
    dragging = false;
}

void Camera::handleEvent(sf::Event e) {
    if(e.type ==  sf::Event::MouseButtonPressed) {
        dragging = true;
        sf::Vector2f v = view.getCenter();
        drag_position = sf::Vector2i(e.mouseButton.x + v.x, e.mouseButton.y + v.y);
    } else if(e.type == sf::Event::MouseButtonReleased) {
        dragging = false;
    } else if(e.type == sf::Event::MouseMoved) {
        if(dragging) {

            view.setCenter(drag_position.x - e.mouseMove.x, drag_position.y - e.mouseMove.y);
        }
    } else if(e.type == sf::Event::Resized) {
        view.setSize(e.size.width, e.size.height);
    } else if(e.type == sf::Event::MouseWheelScrolled) {
        if(e.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
        } else {
        }
    }
}

sf::View Camera::getView() {
    return view;
}