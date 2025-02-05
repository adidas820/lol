#pragma once
#include "../Component.hpp"

class PositionComponent : public Component {
    public:
        int x, y;

        PositionComponent(int x, int y) : x(x), y(y) {}
};