#include <iostream>
#include "entity.hpp"
#include "healthComponent.hpp"

int main(int, char**){
    Entity player;
    player.addComponent(std::make_shared<healthComponent>(100));

    auto health = player.getComponent<healthComponent>();
    if (health) {
        std::cout << "HP: " << health->hp << "\n";
    }
    
    return 0;
}
