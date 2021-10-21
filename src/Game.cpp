#include "../include/Game.hpp"
#include "../include/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;
// Constants 

const int WINDOW_WIDTH = 320;
const int WINDOW_HEIGHT = 480;


Game::Game(){
}

void Game::start(){
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "The game!");
    
    Tile tile = Tile();
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed){
                window.close();
            }
        }
        window.clear(Color::White);
        window.draw(tile.getSprite());
        window.display();
    }
}