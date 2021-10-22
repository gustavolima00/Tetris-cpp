#include "../include/Game.hpp"
#include "../include/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;
// Constants

const int WINDOW_WIDTH = 320;
const int WINDOW_HEIGHT = 480;
const string WINWOW_LABEL = "Tetris";

Game::Game()
{
    window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINWOW_LABEL);
}

Game::~Game()
{
    delete window;
}

void Game::start()
{
    Tile tile = Tile();
    while (window->isOpen())
    {
        Event e;
        while (window->pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window->close();
            }
        }
        window->clear(Color::White);
        tile.draw(window, Tile::Color::Purple, Tile::Type::J);
        window->display();
    }
}