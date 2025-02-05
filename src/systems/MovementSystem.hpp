#pragma once
#include "../Entity.hpp"
#include "../components/PositionComponent.hpp"
#include <iostream>

class MovementSystem {
public:
    static void move(Entity& entity, int dx, int dy) {
        auto position = entity.getComponent<PositionComponent>();
        if (position) {
            position->x += dx;
            position->y += dy;
            std::cout << "Entidad movida a (" << position->x << ", " << position->y << ")\n";
        }
    }
};