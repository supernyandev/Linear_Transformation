#include "Coordinate.h"


class Line : MyDrawable {

    float length;
    float rotation;
    std::pair<float, float> centre;

public:
    float WIDTH = 1.5;
    sf::RectangleShape rectangle;
    Line(float x1, float y1, float x2, float y2);

    void draw(sf::RenderWindow& window);
};