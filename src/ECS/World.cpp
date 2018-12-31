#include "World.hpp"


World::World() {
    entity_count = 0;
}

Entity World::newEntity() {
    Entity e(entity_count);

    entity_count++;
    return e;
}