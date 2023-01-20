#include <iostream>
#include "SFML/Graphics.hpp"
#include "Utilities/Shapes.h"
#include "Utilities/Coordinate.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "none");
    sf::RectangleShape rd(sf::Vector2f(-10.5, -90.5));
    Drawable::Set_Size(WINDOW_WIDTH,WINDOW_HEIGHT);
    sf::Event event;
    Coordinate_System coord(WINDOW_WIDTH,WINDOW_HEIGHT);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        window.clear();

        coord.draw_all(window);
        window.draw(rd);
        window.display();
    }
    return 0;
}
