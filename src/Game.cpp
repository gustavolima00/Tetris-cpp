#include "../include/Game.hpp"
#include "../include/Tile.hpp"
#include "../include/Figure.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>
using namespace sf;
using namespace std;

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
    Figure figure;
    float timer = 0;
    
    while (window->isOpen())
    {
        const bool downIsPressed = Keyboard::isKeyPressed(Keyboard::Down);
        const float DELAY = downIsPressed ? 0.05 : 0.3;

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
                    figure.moveLeft();
                if (e.key.code == Keyboard::Right)
                    figure.moveRight();
            }
        }
        

        window->clear(Color::White);
        figure.draw(window);
        if (timer > DELAY)
        {
            figure.moveDown();
            timer = 0;
        }
        window->display();
    }
}