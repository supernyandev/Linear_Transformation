#include "SFML/Graphics.hpp"
#include <vector>
#ifndef UPDATE_H
#define UPDATE_H
class Drawable{
public:
    static int WINDOW_WIDTH;
    static int WINDOW_HEIGHT;
    static void Set_Size(int WINDOW_WIDTH,int WINDOW_HIGHT);
    virtual void draw(sf::RenderWindow& window);
};

struct Coordinate_System{

public:
    std::vector<Drawable*> drawables;
    std::vector<Drawable*> coordinate;
    void draw_all(sf::RenderWindow& window);
    void add_drawable(Drawable& object);
    Coordinate_System(int WINDOW_WIDTH,int WINDOW_HEIGHT);
};
#endif
