#pragma once
#include <vector>
#include <memory>
#include "Entity.hpp"
#include <algorithm>

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;
    int nextID = 0;

public:
    std::shared_ptr<Entity> createEntity() {
        auto entity = std::make_shared<Entity>(nextID++); 
        entities.push_back(entity);
        return entity;
    }

    std::shared_ptr<Entity> getEntity(int id) {
        for(auto& entity : entities) {
            if (entity->getID() == id) {
                return entity;
            }
        }
        return nullptr;
    }

    void removeEntity(int id) {
        entities.erase(
            std::remove_if(entities.begin(), entities.end(),
                [id](const std::shared_ptr<Entity>& entity) {
                    return entity->getID() == id;
                }),
            entities.end());
    }

    std::vector<std::shared_ptr<Entity>>& getAllEntities() {
        return entities;
    }
};