#include "Entities/Characters/PlayerCharacter.hpp"

PlayerCharacter::PlayerCharacter(TileMap *map) : map(map) {
    animated_sprite = new AnimatedSprite(0, 7, .1, new SpriteSheet("../res/characters/running.png", 8, 1));
    animated_sprite->setPaused(true);
    position.x = position.y = 10;
    move_range = 25;
    state = IDLE;
    dijkstra_map = map->navigate(sf::Vector2i(position.x, position.y), 19);
}

void PlayerCharacter::update(float dt) {
    if(state == MOVING) {
        position = sf::Vector2f(position.x + 0.005 * (target.x - position.x), position.y + 0.005 * (target.y - position.y));
        if((position.x > target.x - .05 && position.x < target.x + .05) && (position.y > target.y - .05 && position.y < target.y + .05)) {
            position = target;
            state = IDLE;
            animated_sprite->setPaused(true);
            dijkstra_map = map->navigate(sf::Vector2i(position.x, position.y), 19);
        }
    }
    animated_sprite->update(dt);
}

void PlayerCharacter::handleEvent(sf::Event e) {
    if(e.type == sf::Event::KeyPressed) {
        if(e.key.code == sf::Keyboard::Up) move(0, -1);
        else if(e.key.code == sf::Keyboard::Right) move(1, 0);
        else if(e.key.code == sf::Keyboard::Left) move(-1, 0);
        else if(e.key.code == sf::Keyboard::Down) move(0, 1);
    }
}

void PlayerCharacter::move(int x, int y) {
    if(state == MOVING) return;
    if(x < 0) animated_sprite->flip(true);
    else animated_sprite->flip(false);
    animated_sprite->setPaused(false);
    state = MOVING;
    target = position + sf::Vector2f(x, y);
}

#include<iostream>
void PlayerCharacter::drawMovement(sf::RenderTarget &target) {
    sf::CircleShape shape;
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2);
    shape.setPosition(position.x, position.y);
    target.draw(shape);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(16, 16));
    for(int i = 0; i < dijkstra_map.size(); i++) {
        for(int j = 0; j < dijkstra_map[i].size(); j++) {
            if(dijkstra_map[i][j].cost == 0) continue;
            rect.setPosition(sf::Vector2f((i * 16) + (position.x * 16 - ((int)(19/2)*16)), (j * 16) + (position.y * 16 - ((int)(19/2)*16))));
            rect.setFillColor(sf::Color(255 - (dijkstra_map[i][j].cost * 20), 255 - (dijkstra_map[i][j].cost * 20), 255 - (dijkstra_map[i][j].cost * 20)));
            target.draw(rect);
        }
    }
}

void PlayerCharacter::draw(sf::RenderTarget &target) {
    if(state == IDLE) {
        drawMovement(target);
    }

    animated_sprite->draw(sf::Vector2f((position.x-.5)*16, (position.y-1.5)*16), target);
}