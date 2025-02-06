#include "Game.hpp"

void Game::init() {
    auto player = entityManager.createEntity();
    player->addComponent(std::make_shared<PositionComponent>(1,1));
    player->addComponent(std::make_shared<HealthComponent>(100));
    player->addComponent(std::make_shared<ColliderComponent>(1,1,1,1));

    std::cout << "Jugador Iniciado\n";

    auto wall = entityManager.createEntity();
    wall->addComponent(std::make_shared<PositionComponent>(3,3));
    wall->addComponent(std::make_shared<ColliderComponent>(3,3,1,3));
}

void Game::handleInput() {
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

void Game::update() {
    CollisionSystem::checkCollisions(entityManager);
}

void Game::render() {
    RenderSystem::render(entityManager);
}

void Game::gameLoop() {
    while(running) {
        handleInput();
        update();
        render();
    }
}