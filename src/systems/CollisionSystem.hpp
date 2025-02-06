#pragma once
#include "../EntityManager.hpp"
#include "../components/ColliderComponent.hpp"
#include <iostream>
#include <vector>
#include <memory>

class CollisionSystem {
public:
    static void checkCollisions(EntityManager& entityManager) {
        auto& entities = entityManager.getAllEntities();
        std::vector<std::shared_ptr<ColliderComponent>> colliders; 

        for (auto& entity : entities) {
            auto collider = entity->getComponent<ColliderComponent>();
            if (collider) {
                colliders.push_back(collider);
            }
        }

        for (size_t i = 0; i < colliders.size(); ++i) {
            for (size_t j = i + 1; j < colliders.size(); ++j) {
                if (colliders[i]->isColliding(*colliders[j])) {
                    handleCollision(entities[i], entities[j]);
                }
            }
        }
    }

private:
    static void handleCollision(const std::shared_ptr<Entity>& entityA, const std::shared_ptr<Entity>& entityB) {
        std::cout << "¡Colisión detectada entre " << entityA->getID()
                  << " y " << entityB->getID() << "!\n";
    }
};
