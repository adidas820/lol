#pragma once
#include "../Component.hpp"

class HealthComponent : public Component {
    public:
        int hp;

        HealthComponent(int health) : hp(health) {}
};
