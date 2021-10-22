#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/Tile.hpp"
#include "../include/Figure.hpp"
using namespace sf;

class Game
{
    RenderWindow *window;
    Clock *clock;
    vector<Tile*> tiles;
    Figure* figure;
public:
    Game();
    ~Game();
    void start();
};
#endif