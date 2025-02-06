#pragma once
#include "../Component.hpp"

class ColliderComponent : public Component {
public:
    int x, y, width, height;

    ColliderComponent(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

    bool isColliding(const ColliderComponent& other) {
        return (x < other.x + other.width &&
                x + width > other.x &&
                y < other.y + other.height &&
                y + height > other.y);
    }
};
