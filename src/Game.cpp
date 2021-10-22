#include "../include/Game.hpp"
#include "../include/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>
using namespace sf;
using namespace std;
// Constants

const int WINDOW_WIDTH = 320;
const int WINDOW_HEIGHT = 480;
const string WINWOW_LABEL = "Tetris";

Game::Game()
{
    window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINWOW_LABEL);
    clock = new Clock();
}

Game::~Game()
{
    delete window;
    delete clock;
}

void Game::start()
{
    Tile tile = Tile();
    float timer = 0;
    const float DELAY = 0.3;
    while (window->isOpen())
    {
        float time = clock->getElapsedTime().asSeconds();
        clock->restart();
        timer += time;

        Event e;
        while (window->pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window->close();
            }
            if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Left)
                    tile.moveLeft(0);
                if (e.key.code == Keyboard::Right)
                    tile.moveRight(WINDOW_WIDTH - tile.getWidth());
            }
        }
        
        window->clear(Color::White);
        tile.draw(window, Tile::Color::Purple, Tile::Type::J);
        if (timer > DELAY)
        {
            tile.moveDown();
            timer = 0;
        }
        window->display();
    }
}