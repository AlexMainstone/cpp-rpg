#pragma once

#include "../Entity.hpp"

class Character : public Entity {
    public:
        void recalculate() {
            toughness = 10 + fortitude + will;
            guard = 10 + agility + might + armor;
            resolve = 10 + presence + will;
            hit_points = 2 * (fortitude + presence + will) + 10;
        }

    protected:
        // Physical
        int agility;
        int fortitude;
        int might;
        
        // Mental
        int learning;
        int logic;
        int perception;
        int will;
        
        // Social
        int deception;
        int persuasion;
        int presence;

        // Extraordinary
        int alteration;
        int creation;
        int entropy;
        int influence;
        int movement;
        int prescience;
        int protection;

        // Health & Damage
        int toughness;
        int guard;
        int resolve;
        int hit_points;
        int armor;

        int move_range;
};