#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Tile
{
    Texture* texture;
    Sprite* sprite;
    void loadTexture();
public:
    enum TileCollor
    {
        Blue,
        Purple,
        Red,
        Green,
        Yellow,
        LightBlue,
        Orange
    };
    Tile(TileCollor color = TileCollor::Blue);
    ~Tile();
    Sprite getSprite();
};
#endif