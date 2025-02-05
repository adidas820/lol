#pragma once
#include "../Entity.hpp"
#include "../components/PositionComponent.hpp"
#include <iostream>

class MovementSystem {
public:
    static void move(Entity& entity, int dx, int dy) {
        auto position = entity.editComponent<PositionComponent>();
        if (position) {
            position->x += dx;
            position->y += dy;
        }
    }
};