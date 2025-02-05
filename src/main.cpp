#include <iostream>
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "components/HealthComponent.hpp"
#include "components/PositionComponent.hpp"
#include "systems/MovementSystem.hpp"
#include "core/Game.hpp"

int main(int, char**){
    Game game;
    game.init();
    game.gameLoop();

    return 0;
}
