#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/Tile.hpp"
#include "../include/Figure.hpp"
#include <time.h> 
using namespace sf;

class Game
{
    RenderWindow *window;
    Clock *clock;
    vector<Tile*> tiles;
    Figure* figure;
    void buildNewFigure();
    bool figureWillColideDown();
    bool figureWillColideLeft();
    bool figureWillColideRight();
    void manageEvents();
    void updateScreen();
    
public:
    Game();
    ~Game();
    void start();
};
#endif