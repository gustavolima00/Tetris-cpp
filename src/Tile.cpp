#include "../include/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

const string TILES_PATH = "assets/tetris/tiles.png";
const int TILE_SIZE = 18;
const int TICK_MILISECONDS = 1000;

const map<Tile::Color, int> COLLOR_X1 = {
    {Tile::Color::Blue, TILE_SIZE * 0},
    {Tile::Color::Purple, TILE_SIZE * 1},
    {Tile::Color::Red, TILE_SIZE * 2},
    {Tile::Color::Green, TILE_SIZE * 3},
    {Tile::Color::Yellow, TILE_SIZE * 4},
    {Tile::Color::LightBlue, TILE_SIZE * 5},
    {Tile::Color::Orange, TILE_SIZE * 6}};

void Tile::loadTexture()
{
    texture = new Texture();
    texture->loadFromFile(TILES_PATH);
}

Tile::Tile(int x, int y, Tile::Color color)
{
    clock = new Clock();
    loadTexture();
    sprite = new Sprite(*texture);
    sprite->setTextureRect(IntRect(COLLOR_X1.at(color), 0, TILE_SIZE, TILE_SIZE));
    xPos = x;
    yPos = y;
    gravityTick = 0;
}

Tile::~Tile()
{
    delete texture;
    delete sprite;
    delete clock;
}

void Tile::draw(RenderWindow *window)
{
    int time = clock->getElapsedTime().asMilliseconds();
    
    if(time>500){
        clock->restart();
        moveDown();
    }
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
    return xPos;
}

int Tile::getY(){
    return yPos;
}

Tile::Color Tile::getRandomColor(){
    return static_cast<Tile::Color>(rand()%7);
}