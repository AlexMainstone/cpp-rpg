#pragma once

#include "Components/Component.hpp"
#include <vector>

class Entity {
    public:
        Entity(int id);
        void addComponent(Component *c);
        void removeComponent(Component *c);
    private:
        int id;
        std::vector<Component*> components;
}