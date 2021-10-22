#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Tile
{
    Texture *texture;
    Sprite *sprite;
    int xPos;
    int yPos;
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
    
    Tile(int x=0, int y=0, Color color = Color::Blue);
    ~Tile();
    void draw(RenderWindow *window);
    void moveDown();
    void moveLeft();
    void moveRight();
    int getWidth();
    int getHeight();
    int getX();
    int getY();
};
#endif