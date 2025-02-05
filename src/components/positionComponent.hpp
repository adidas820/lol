#pragma once
#include "../Component.hpp"

class positionComponent : public Component {
    public:
        int x, y;

        positionComponent(int x, int y) : x(x), y(y) {}
};