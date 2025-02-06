#pragma once
#include "../EntityManager.hpp"
#include "../systems/MovementSystem.hpp"
#include "../systems/RenderSystem.hpp"
#include "../systems/CollisionSystem.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/HealthComponent.hpp"
#include <iostream>

class Game {
public:
    bool running;
    EntityManager entityManager;

    Game() : running(true) {}

    void init();
    void handleInput();
    void update();
    void render();
    void gameLoop();
};