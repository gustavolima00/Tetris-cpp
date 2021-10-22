#include "../include/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>
using namespace sf;
using namespace std;

const string TILES_PATH = "assets/tetris/tiles.png";
const int TILE_SIZE = 18;
const map<Tile::Color, int> COLLOR_X1 = {
    {Tile::Color::Blue, TILE_SIZE * 0},
    {Tile::Color::Purple, TILE_SIZE * 1},
    {Tile::Color::Red, TILE_SIZE * 2},
    {Tile::Color::Green, TILE_SIZE * 3},
    {Tile::Color::LightBlue, TILE_SIZE * 4},
    {Tile::Color::Orange, TILE_SIZE * 5}};

/**
 *  The numbers on FIGURES_SHAPES are referents of this shape
 * 
 * [0][1]
 * [2][3]
 * [4][5]
 * [6][7]
 * 
 **/

const map<Tile::Type, vector<int>> FIGURES_SHAPES = {
    {Tile::Type::I, {1, 3, 5, 7}},
    {Tile::Type::Z, {2, 4, 5, 7}},
    {Tile::Type::S, {3, 5, 4, 6}},
    {Tile::Type::T, {3, 5, 4, 7}},
    {Tile::Type::L, {2, 3, 5, 7}},
    {Tile::Type::J, {3, 5, 6, 7}},
    {Tile::Type::O, {2, 3, 4, 5}}
};

void Tile::loadTexture()
{
    this->texture = new Texture();
    this->texture->loadFromFile(TILES_PATH);
}

Tile::Tile()
{
    this->loadTexture();
    this->sprite = new Sprite(*this->texture);
}

Tile::~Tile()
{
    delete this->texture;
    delete this->sprite;
}

void Tile::draw(RenderWindow *window, Color color, Type type)
{
    sprite->setTextureRect(IntRect(COLLOR_X1.at(color), 0, TILE_SIZE, TILE_SIZE));
    for (int position : FIGURES_SHAPES.at(type))
    {
        int x = position % 2;
        int y = position / 2;
        sprite->setPosition(x * TILE_SIZE, y * TILE_SIZE);
        window->draw(*sprite);
    }
}
