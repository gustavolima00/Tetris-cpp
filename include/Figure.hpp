#ifndef FIGURE_HPP
#define FIGURE_HPP
#include <SFML/Graphics.hpp>
#include "../include/Tile.hpp"
#include <vector>

using namespace sf;
using namespace std;

class Figure{
    Clock* clock;
    public:
    vector<Tile*> tiles;
    enum Type
    {
        I,
        Z,
        S,
        T,
        L,
        J,
        O
    };
    static Type getRandomType();
    Figure(Tile::Color color = Tile::Color::Blue, Type type = Type::I);
    ~Figure();
    void draw(RenderWindow *window);
    void moveDown();
    void moveLeft();
    void moveRight();
    int maxX();
    int maxY();
    bool willColideDown(Tile* tile);
    bool willColideLeft(Tile* tile);
    bool willColideRight(Tile* tile);
    void moveFast();
    void moveNormal();
};
#endif