//
// Created by supernyan on 19.01.23.
//
#include <math.h>
#include "Pixel.h"
#include <iostream>
Line::Line(float x1, float y1, float x2, float y2) {
    float lngth = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    float pi = atan(1) * 4;
    this->rotation = (acos((y2 - y1) / lngth)) / (pi * 2) * 360;
    this->length = lngth;
    this->centre.first = x1;
    this->centre.second = y1;
    this->rectangle = sf::RectangleShape(sf::Vector2f(this->WIDTH, this->length));
    this->rectangle.setPosition(this->centre.first, this->centre.second);
    this->rectangle.setRotation(rotation);
    this->rectangle.setFillColor(sf::Color(255,255,255));
    std::cout<<this->length;

}

void Line::draw(sf::RenderWindow &window) {
    window.draw(this->rectangle);
}
