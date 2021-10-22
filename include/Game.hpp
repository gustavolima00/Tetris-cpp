#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Game
{
    RenderWindow *window;
    Clock *clock;

public:
    Game();
    ~Game();
    void start();
};
#endif