#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <deque>

class Drawable {
public:
    static int WINDOW_WIDTH;
    static int WINDOW_HEIGHT;

    static void Set_Size(int WINDOW_WIDTH, int WINDOW_HIGHT);

    virtual void draw(sf::RenderWindow &window);
};

class Line : public Drawable {

    float length;
    float rotation;
    std::pair<float, float> centre;

public:

    float WIDTH = 1.5;
    sf::RectangleShape rectangle;

    Line(float x1, float y1, float x2, float y2);

    void draw(sf::RenderWindow &window);
};

class Pixel : public Drawable {
public:
    sf::Vector2f position;
    sf::Vector2f normal_position;
    sf::Color color;
    sf::CircleShape *shape;
    std::deque<Line *> trace;


    float radius = 1.5;
    size_t max_trace_length = 100;

    void draw(sf::RenderWindow &window);

    void set_position(float x, float y);

    void set_position(sf::Vector2f pos);

    void set_color(sf::Color color);

    Pixel(sf::Vector2f pos, sf::Color color = sf::Color(255, 255, 255));

    Pixel(float x, float y, sf::Color color = sf::Color(255, 255, 255));

    void check_trace();


};
