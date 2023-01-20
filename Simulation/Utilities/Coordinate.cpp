#include "Coordinate.h"
#include "Shapes.h"


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


Coordinate_System::Coordinate_System(int WINDOW_WIDTH, int WINDOW_HEIGHT,float raref) {
    this->coordinate.push_back(new Line(100, 0, -100, 0));
    this->coordinate.push_back(new Line(0, -100, 0, 100));
    float x = 90;

    while(x>=-90.0){
        float y = 90;
        while(y>=-90.0){
            this->pixels.push_back(new Pixel(x,y));
            this->first_position.push_back(sf::Vector2f(x,y));
            this->drawables.push_back(pixels.back());
            y-=raref;
        }
        x-=raref;
    }


}

void Drawable::draw(sf::RenderWindow &window) {

}


