#include "../include/Game.hpp"
#include "../include/Tile.hpp"
#include "../include/Figure.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>
#include <iostream>
using namespace sf;
using namespace std;

const int WINDOW_WIDTH = 320;
const int WINDOW_HEIGHT = 480;
const int MAX_Y = 25;
const int MIN_X = 0;
const int MAX_X = 17;

const string WINWOW_LABEL = "Tetris";

Game::Game()
{
    window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINWOW_LABEL);
    clock = new Clock();
    figure = new Figure();
    Tile *tile = new Tile(0, 20, Tile::Color::Orange);
    tiles.push_back(tile);
}

Game::~Game()
{
    delete window;
    delete clock;
    for (auto &tile : tiles)
        delete tile;
    delete figure;
}

void Game::buildNewFigure()
{
    while (!figure->tiles.empty())
    {
        Tile *tile = figure->tiles.back();
        figure->tiles.pop_back();
        tiles.push_back(tile);
    }
    delete figure;
    figure = new Figure();
}

bool Game::figureWillColideDown()
{
    for (auto &tile : tiles)
    {
        if (figure->willColideDown(tile))
            return true;
        if (figure->maxY() >= MAX_Y)
            return true;
    }

    return false;
}

bool Game::figureWillColideLeft()
{
    for (auto &tile : tiles)
    {
        if (figure->willColideLeft(tile))
            return true;
        if (figure->maxX() <= MIN_X)
            return true;
    }

    return false;
}

bool Game::figureWillColideRight()
{
    for (auto &tile : tiles)
    {
        if (figure->willColideRight(tile))
            return true;
        if (figure->maxX() >= MAX_X)
            return true;
    }

    return false;
}

void Game::start()
{
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
                {
                    if (!figureWillColideLeft())
                        figure->moveLeft();
                }

                if (e.key.code == Keyboard::Right)
                {
                    if (!figureWillColideRight())
                        figure->moveRight();
                }
            }
        }

        window->clear(Color::White);
        figure->draw(window);
        if (timer > DELAY)
        {
            if (figureWillColideDown())
            {
                buildNewFigure();
            }
            else
            {
                figure->moveDown();
            }
            timer = 0;
        }
        for (auto &tile : tiles)
        {
            tile->draw(window);
        }
        window->display();
    }
}