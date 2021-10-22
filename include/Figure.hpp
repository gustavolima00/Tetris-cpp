#ifndef FIGURE_HPP
#define FIGURE_HPP
#include <SFML/Graphics.hpp>
#include "../include/Tile.hpp"
#include <vector>

using namespace sf;
using namespace std;

class Figure{
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
    Figure(Tile::Color color = Tile::Color::Blue, Type type = Type::I);
    ~Figure();
    void draw(RenderWindow *window);
    void moveDown();
    void moveLeft();
    void moveRight();
    int maxX();
    int maxY();
    bool isAboveATile(Tile* tile);
};
#endif