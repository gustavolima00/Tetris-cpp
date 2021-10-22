#include "../include/Tile.hpp"
#include "../include/Figure.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;
/**
 *  The numbers on FIGURES_SHAPES are referents of this shape
 * 
 * [0][1]
 * [2][3]
 * [4][5]
 * [6][7]
 * 
 **/

const map<Figure::Type, vector<int>> FIGURES_SHAPES = {
    {Figure::Type::I, {1, 3, 5, 7}},
    {Figure::Type::Z, {2, 4, 5, 7}},
    {Figure::Type::S, {3, 5, 4, 6}},
    {Figure::Type::T, {3, 5, 4, 7}},
    {Figure::Type::L, {2, 3, 5, 7}},
    {Figure::Type::J, {3, 5, 6, 7}},
    {Figure::Type::O, {2, 3, 4, 5}}};

Figure::Figure(Tile::Color color, Type type)
{
    for (int position : FIGURES_SHAPES.at(type))
    {
        int x = position % 2;
        int y = position / 2;
        Tile *tile = new Tile(x, y, color);
        tiles.push_back(tile);
    }
}

Figure::~Figure()
{
    for (auto &tile : tiles)
    {
        delete tile;
    }
}

void Figure::draw(RenderWindow *window)
{
    for (auto &tile : tiles)
    {
        tile->draw(window);
    }
}
void Figure::moveDown()
{
    for (auto &tile : tiles)
    {
        tile->moveDown();
    }
}
void Figure::moveLeft()
{
    for (auto &tile : tiles)
    {
        tile->moveLeft();
    }
}
void Figure::moveRight()
{
    for (auto &tile : tiles)
    {
        tile->moveRight();
    }
}
bool Figure::willColideDown(Tile *otherTile)
{
    for (auto &tile : tiles)
    {
        if (tile->getY() + 1 == otherTile->getY() and tile->getX() == otherTile->getX())
            return true;
    }
    return false;
}

bool Figure::willColideLeft(Tile *otherTile)
{
    for (auto &tile : tiles)
    {
        if (tile->getY() == otherTile->getY() and tile->getX() == otherTile->getX() + 1)
            return true;
    }
    return false;
}

bool Figure::willColideRight(Tile *otherTile)
{
    for (auto &tile : tiles)
    {
        if (tile->getY() + 1 == otherTile->getY() and tile->getX() + 1 == otherTile->getX())
            return true;
    }
    return false;
}

int Figure::maxX()
{
    int ans = 0;
    for (auto &tile : tiles)
    {
        ans = max(ans, tile->getX());
    }
    return ans;
}
int Figure::maxY()
{
    int ans = 0;
    for (auto &tile : tiles)
    {
        ans = max(ans, tile->getY());
    }
    return ans;
}
Figure::Type Figure::getRandomType(){
    return static_cast<Figure::Type>(rand()%7);
}