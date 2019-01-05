#include "Interface/Camera.hpp"

Camera::Camera(sf::View v) {
    view = v;
    dragging = false;
    zoom = 0.2;
    view.zoom(zoom);
}

void Camera::handleEventWithWindow(sf::Event e, sf::RenderWindow &window) {
    if(e.type ==  sf::Event::MouseButtonPressed) {
        dragging = true;
        sf::Vector2f v = view.getCenter();
        drag_position = window.mapPixelToCoords(sf::Vector2i(e.mouseButton.x, e.mouseButton.y), view);
    } else if(e.type == sf::Event::MouseButtonReleased) {
        dragging = false;
    } else if(e.type == sf::Event::MouseMoved) {
        if(dragging) {
            sf::Vector2f final_mouse = window.mapPixelToCoords(sf::Vector2i(e.mouseMove.x, e.mouseMove.y), view);
            view.setCenter(view.getCenter() + (drag_position - final_mouse));
        }
    } else if(e.type == sf::Event::Resized) {
        view.setSize(e.size.width, e.size.height);
        view.zoom(zoom);
    } else if(e.type == sf::Event::MouseWheelScrolled) {
        if(dragging) return;
        if(e.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
            if(e.mouseWheelScroll.delta <= -1 && zoom <= 2) {
                view.zoom(0.75);
            }else if(e.mouseWheelScroll.delta >= 1 && zoom >= 0.1) {
                view.zoom(1.5);
            }
        }
    }
}

sf::View Camera::getView() {
    return view;
}