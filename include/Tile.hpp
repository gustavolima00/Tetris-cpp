#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Tile
{
    Texture *texture;
    Sprite *sprite;
    void loadTexture();

public:
    enum Color
    {
        Blue,
        Purple,
        Red,
        Green,
        Yellow,
        LightBlue,
        Orange
    };
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
    Tile();
    ~Tile();
    void draw(RenderWindow *window, Color color = Color::Blue, Type type = Type::I);
};
#endif