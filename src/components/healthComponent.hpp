#pragma once
#include "../Component.hpp"

class healthComponent : public Component {
    public:
        int hp;

        healthComponent(int health) : hp(health) {}
};