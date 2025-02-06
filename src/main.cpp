#include "core/Game.hpp"

int main(int, char**){
    Game game;
    game.init();
    game.gameLoop();

    return 0;
}
