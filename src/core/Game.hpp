#pragma once
#include "../EntityManager.hpp"
#include "../systems/MovementSystem.hpp"
#include "../systems/RenderSystem.hpp"
#include "../components/HealthComponent.hpp"
#include <iostream>

class Game {
    public:
        bool running;
        EntityManager entityManager;

        Game() : running(true) {}

        void init() {
            auto player = entityManager.createEntity();
            player->addComponent(std::make_shared<PositionComponent>(5,5));
            player->addComponent(std::make_shared<HealthComponent>(100));

            std::cout << "Jugador Iniciado\n";
        
    }

    void handleInput() {
        char input;
        std::cin >> input;

        auto player = entityManager.getEntity(0);
        if (!player) return;

        auto position = player->editComponent<PositionComponent>();

        if (position) {
            if (input == 'w') MovementSystem::move(*player, 0, 1);
            if (input == 's') MovementSystem::move(*player, 0, -1);
            if (input == 'a') MovementSystem::move(*player, -1, 0);
            if (input == 'd') MovementSystem::move(*player, 1, 0);
            if (input == 'q') running = false;
        }
    }

    void update() {

    }

    void render() {
        RenderSystem::render(entityManager);
    }

    void gameLoop() {
        while(running) {
            handleInput();
            update();
            render();
        }
    }
};