//
// Created by supernyan on 20.01.23.
//
#include "unistd.h"
#include "transformation.h"
#include "Utilities/Coordinate.h"
#include "Utilities/Shapes.h"

void simulate(int WINDOW_WIDTH, int WINDOW_HEIGHT, sf::RenderWindow &window,
              std::function<sf::Vector2f(sf::Vector2f, sf::Vector2f, int)> &iter) {
    sf::Event event;
    Coordinate_System coordinateSystem(WINDOW_WIDTH, WINDOW_HEIGHT);
    int frame = 0;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
            for (int i = 0; i < coordinateSystem.pixels.size(); ++i) {
                sf::Vector2f new_pos = iter(coordinateSystem.pixels[i]->position, coordinateSystem.first_position[i],
                                            frame);
                coordinateSystem.pixels[i]->set_position(new_pos);
            }
        }
        ++frame;
        window.clear();
        coordinateSystem.draw_all(window);
        window.display();
        usleep(1000);
    }
}
