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

void Tile::loadTexture()
{
    texture = new Texture();
    texture->loadFromFile(TILES_PATH);
}

Tile::Tile(int x, int y, Tile::Color color)
{
    loadTexture();
    sprite = new Sprite(*texture);
    sprite->setTextureRect(IntRect(COLLOR_X1.at(color), 0, TILE_SIZE, TILE_SIZE));
    xPos = x;
    yPos = y;
}

Tile::~Tile()
{
    delete texture;
    delete sprite;
}

void Tile::draw(RenderWindow *window)
{
    sprite->setPosition(xPos*TILE_SIZE, yPos*TILE_SIZE);
    window->draw(*sprite);   
}

void Tile::moveDown(){
    yPos += 1;
}

void Tile::moveLeft(){
    xPos -= 1;
}

void Tile::moveRight(){
    xPos += 1;
}

int Tile::getX(){
    return xPos * TILE_SIZE;
}

int Tile::getY(){
    return xPos * TILE_SIZE;
}

int Tile::getWidth(){
    return TILE_SIZE;
}

int Tile::getHeight(){
    return TILE_SIZE;
}