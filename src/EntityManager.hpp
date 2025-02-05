#pragma once
#include <vector>
#include <memory>
#include "Entity.hpp"

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;

public:
    std::shared_ptr<Entity> createEntity() {
        auto entity = std::make_shared<Entity>();
        entities.push_back(entity);
        return entity;
    }

    void update();
};