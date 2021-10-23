#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class Tile
{
    Texture *texture;
    Sprite *sprite;
    Clock* clock;
    bool gravity;
    int gravityTickInMiliseconds;
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
    static Tile::Color getRandomColor();

    Tile(int x=0, int y=0, Color color = Color::Blue);
    ~Tile();
    void draw(RenderWindow *window);
    void moveDown();
    
    void moveLeft();
    void moveRight();
    int getX();
    int getY();
    void setGravity(bool gravity);
    void setGravityTick(int gravityTickInMiliseconds);
};
#endif