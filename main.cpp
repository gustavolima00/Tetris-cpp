#include <SFML/Graphics.hpp>

using namespace sf;

int main(){
    RenderWindow window(VideoMode(320, 480), "The game!");

    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed){
                window.close();
            }
        }
    }
    return 0;
}