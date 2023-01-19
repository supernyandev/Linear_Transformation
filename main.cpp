#include <iostream>
#include "SFML/Graphics.hpp"
#include "Utilities/Pixel.h"
#include "Utilities/Coordinate.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "none");
    Line ln(WINDOW_WIDTH/2,WINDOW_HEIGHT,WINDOW_WIDTH/2,0);
    sf::RectangleShape rd(sf::Vector2f(120.5,120.5));
    while (true){
        window.clear();
    ln.draw(window);
    //window.draw(ln.rectangle);
    //window.draw(rd);
    window.display();}
    return 0;
}
