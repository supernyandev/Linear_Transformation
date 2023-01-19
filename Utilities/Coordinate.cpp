#include "Coordinate.h"

void MyDrawable::draw(sf::RenderWindow &window) {

}

void Coordinate_System::draw_all(sf::RenderWindow window) {
    for(auto i :this->drawables){
        i->draw(window);
    }
    for(auto i:this->coordinate){
        i->draw(window);
    }
}

void Coordinate_System::add_drawable(MyDrawable &object) {
    drawables.push_back(&object);
}


Coordinate_System::Coordinate_System(int WINDOW_WIDTH, int WINDOW_HEIGHT) {

}
