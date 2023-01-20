#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Shapes.h"


class Coordinate_System{

public:
    std::vector<sf::Vector2f> first_position;
    std::vector<Pixel*> pixels;
    std::vector<Drawable*> drawables;
    std::vector<Drawable*> coordinate;
    void draw_all(sf::RenderWindow& window);
    void add_drawable(Drawable& object);
    Coordinate_System(int WINDOW_WIDTH,int WINDOW_HEIGHT, float raref = 10.0f);
};


