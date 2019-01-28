#pragma once

#include "Entities/Characters/Character.hpp"

#include "Components/AnimatedSprite.hpp"

#include "World/TileMap.hpp"
class PlayerCharacter : public Character {
    public:
        PlayerCharacter(TileMap *map);
        void update(float dt);
        void handleEvent(sf::Event e);
        void draw(sf::RenderTarget &target);
        void move(int x, int y);
    private:
        // Components
        AnimatedSprite *animated_sprite;

        sf::Vector2f position;
        void drawMovement(sf::RenderTarget &target);

        std::vector<std::vector<Node>> dijkstra_map;
        enum States {
            MOVING,
            IDLE
        };

        TileMap *map;
        States state;
        sf::Vector2f target;
};