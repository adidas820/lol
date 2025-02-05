#include <iostream>
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "components/HealthComponent.hpp"
#include "components/PositionComponent.hpp"
#include "systems/MovementSystem.hpp"

int main(int, char**){
    EntityManager entityManager;

    auto player = entityManager.createEntity();
    player->addComponent(std::make_shared<PositionComponent>(0, 0));
    player->addComponent(std::make_shared<HealthComponent>(100));

    int dx, dy;

    auto position = player->editComponent<PositionComponent>();
    auto health = player->getComponent<HealthComponent>();

    std::cin >> dx >> dy;

    MovementSystem::move(*player, dx, dy);

    if (health) {
        std::cout << "Jugador HP: " << health->hp << "\n";
    }
    
    if (position) {
        std::cout << position->x << "," << position->y;
    }

    return 0;
}
