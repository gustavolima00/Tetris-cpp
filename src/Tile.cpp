#include "../include/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

using namespace sf;
using namespace std;

const string TILES_PATH = "assets/tetris/tiles.png";
const int TILE_SIZE = 18;

void Tile::loadTexture()
{
    this->texture = new Texture();
    this->texture->loadFromFile(TILES_PATH);
}

Tile::Tile(TileCollor color)
{
    this->loadTexture();
    this->sprite = new Sprite(*this->texture);
    map<TileCollor, int> colorX1Map = {
        {Blue, TILE_SIZE * 0},
        {Purple, TILE_SIZE * 1},
        {Red, TILE_SIZE * 2},
        {Green, TILE_SIZE * 3},
        {LightBlue, TILE_SIZE * 4},
        {Orange, TILE_SIZE * 5}};
    this->sprite->setTextureRect(IntRect(colorX1Map[color], 0, TILE_SIZE, TILE_SIZE));
}

Tile::~Tile()
{
    delete this->texture;
    delete this->sprite;
}

Sprite Tile::getSprite()
{
    return *this->sprite;
}
