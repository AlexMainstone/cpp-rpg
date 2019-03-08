#pragma once

#include "Entities/Characters/PlayerCharacter.hpp"

class Party {
    public:
        Party();
        void addMember(PlayerCharacter *character);
        void draw(sf::RenderTarget &target);
        void handleEvent(sf::Event &e);
        void update(float dt);
        void orderTurns();
        void setCurrent(sf::Vector2i c);
    private:
        std::vector<PlayerCharacter*> members;

        int turn;
        std::vector<PlayerCharacter*> turn_order;
};