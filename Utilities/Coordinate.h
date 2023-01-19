#include "SFML/Graphics.hpp"
#include <vector>
#ifndef UPDATE_H
#define UPDATE_H
class MyDrawable{
public:
    void draw(sf::RenderWindow& window);
};

struct Coordinate_System{
private:
    std::vector<MyDrawable*> drawables;
    std::vector<MyDrawable*> coordinate;
public:
    void draw_all(sf::RenderWindow window);
    void add_drawable(MyDrawable& object);
    Coordinate_System(int WINDOW_WIDTH,int WINDOW_HEIGHT);
};
#endif
