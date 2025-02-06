#include "MovementSystem.hpp"

void MovementSystem::move(Entity& entity, int dx, int dy)  {

    auto position = entity.editComponent<PositionComponent>();
    if (position) {
        position->x += dx;
        position->y += dy;
    }
}