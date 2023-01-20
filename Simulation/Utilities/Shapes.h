#include "Coordinate.h"


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
    sf::Color color;
    sf::CircleShape shape;
    float radius = 1.5;

    void draw(sf::RenderWindow &window);

    void set_position(float x, float y);

    void set_position(sf::Vector2f pos);

    void set_color(sf::Color color);

    Pixel(sf::Vector2f pos, sf::Color color);

    Pixel(float x, float y, sf::Color color);

    Pixel(sf::Vector2f pos);

    Pixel(float x, float y);

};