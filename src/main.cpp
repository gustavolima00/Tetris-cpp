#include "../include/Game.hpp"
#include <time.h>

int main()
{
    srand(time(NULL));
    Game game = Game();
    game.start();
}