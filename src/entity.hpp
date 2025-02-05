#pragma once
#include <unordered_map>
#include <memory>
#include "Component.hpp"

class Entity {
private:
    int id;  // Identificador único

public:
    std::unordered_map<std::size_t, std::shared_ptr<Component>> components;

    Entity(int id) : id(id) {}

    int getID() const {  // ⬅️ Agregamos esta función
        return id;
    }

    template <typename T>
    void addComponent(std::shared_ptr<T> component) {
        components[typeid(T).hash_code()] = component;
    }

    template <typename T>
    std::shared_ptr<T> getComponent() {
        auto it = components.find(typeid(T).hash_code());
        return (it != components.end()) ? std::static_pointer_cast<T>(it->second) : nullptr;
    }

    template <typename T>
    std::shared_ptr<T> editComponent() {
        return getComponent<T>();
    }
};