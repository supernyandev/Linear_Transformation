#include "Coordinate.h"
#include "Shapes.h"

void Drawable::Set_Size(int WINDOW_WIDTH, int WINDOW_HEIGHT) {
    Drawable::WINDOW_WIDTH = WINDOW_WIDTH;
    Drawable::WINDOW_HEIGHT = WINDOW_HEIGHT;

}
void Coordinate_System::draw_all(sf::RenderWindow &window) {
    for (auto i: this->drawables) {
        i->draw(window);
    }
    for (auto i: this->coordinate) {
        i->draw(window);
    }
}

void Coordinate_System::add_drawable(Drawable &object) {
    drawables.push_back(&object);

}


Coordinate_System::Coordinate_System(int WINDOW_WIDTH, int WINDOW_HEIGHT) {
    this->coordinate.push_back(new Line(100, 0, -100, 0));
    this->coordinate.push_back(new Line(0, -100, 0, 100));


}

void Drawable::draw(sf::RenderWindow &window) {

}


