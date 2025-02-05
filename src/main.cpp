#include <iostream>
#include "entity.hpp"
#include "components/healthComponent.hpp"
#include "components/positionComponent.hpp"

int main(int, char**){
    Entity player;
    player.addComponent(std::make_shared<healthComponent>(100));
    player.addComponent(std::make_shared<positionComponent>(1,1));

    auto health = player.getComponent<healthComponent>();
    auto position = player.getComponent<positionComponent>();
    if (health) {
        std::cout << "HP: " << health->hp << "\n";
        std::cout << position->x << "\n";
    }
    
    return 0;
}
