#pragma once
#include <vector>
#include <memory>

class Component;

class Entity {
    public:
        std::vector<std::shared_ptr<Component>> components;

        template <typename T>
        void addComponent (std::shared_ptr<T> component) {
            components.push_back(component);
        } 

        template <typename T>
        T* getComponent() {
            for (auto& comp : components) {
                if (T* casted = dynamic_cast<T*>(comp.get())) {
                    return casted;
                }
            }
            return nullptr;
        }

        template <typename T>
        T* editComponent() {
            for (auto& comp : components) {
            T* casted = dynamic_cast<T*>(comp.get());
                if (casted) {
                    return casted;
                }
        }
        return nullptr;
    }
        void removeAllComponents();
};