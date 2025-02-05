#pragma once
#include "../EntityManager.hpp"
#include "../Entity.hpp"

class RenderSystem {
    public:
        static void render(EntityManager& entityManager) {
            auto player = entityManager.getEntity(0);
            auto position = player->getComponent<PositionComponent>();

            if (position) {
                std::cout << "Jugador en: (" << position->x << "," << position->y << ")\n";
            }
        }
};
