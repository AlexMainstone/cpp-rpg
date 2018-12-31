#pragma once

#include "Entities/Entity.hpp"
#include <vector>

class World {
    public:
        World();
        Entity newEntity();
    private:
        int entity_count;
};