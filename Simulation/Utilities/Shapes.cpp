//
// Created by supernyan on 19.01.23.
//
#include <math.h>
#include "Shapes.h"
#include <iostream>

void Drawable::Set_Size(int WINDOW_WIDTH, int WINDOW_HEIGHT) {
    Drawable::WINDOW_WIDTH = WINDOW_WIDTH;
    Drawable::WINDOW_HEIGHT = WINDOW_HEIGHT;

}

int Drawable::WINDOW_WIDTH;
int Drawable::WINDOW_HEIGHT;

Line::Line(float x1, float y1, float x2, float y2) {


    float absolute_x1 = (100.0 - x1) / 200.0 * WINDOW_WIDTH;
    float absolute_x2 = (100.0 - x2) / 200.0 * WINDOW_WIDTH;
    float absolute_y1 = (100.0 + y1) / 200.0 * WINDOW_HEIGHT;
    float absolute_y2 = (100.0 + y2) / 200.0 * WINDOW_HEIGHT;

    float lngth = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    float pi = atan(1) * 4;
    this->rotation = (acos((y2 - y1) / lngth)) / (pi * 2) * 360;
    this->length = lngth / 200.0 * WINDOW_HEIGHT;
    if (this->rotation >= 90.0) {
        this->rotation = 180.0f - this->rotation;
    }
    if (rotation == 90.0f) {
        this->centre.first = absolute_x2;
        this->centre.second = absolute_y2;
    } else {
        this->centre.first = absolute_x1;
        this->centre.second = absolute_y1;
    }

    this->rectangle = sf::RectangleShape(sf::Vector2f(this->WIDTH, this->length));
    this->rectangle.setPosition(this->centre.first, this->centre.second);
    this->rectangle.setRotation(rotation);
    this->rectangle.setFillColor(sf::Color(255, 255, 255));
    //std::cout << this->length << ' ' << this->rectangle.getPosition().y << std::endl;

}

void Line::draw(sf::RenderWindow &window) {
    window.draw(this->rectangle);
}

void Pixel::draw(sf::RenderWindow &window) {

    this->shape->setFillColor(this->color);
    this->shape->setRadius(this->radius);
    this->shape->setPosition(this->position);
    window.draw(*shape);
    for(auto it:trace){
        it->draw(window);
        if((it->rectangle.getSize()-sf::Vector2f(0,0.01)).y>0){
        it->rectangle.setSize(it->rectangle.getSize()-sf::Vector2f(0,0.01));}

    }
}

void Pixel::set_position(float x, float y) {

    auto new_t = new Line(normal_position.x,normal_position.y,x,y);
    sf::Vector2f vc = new_t->rectangle.getSize();
    vc.y = 3;
    new_t->rectangle.setSize(vc);
    float lngth = sqrt(x*x+y*y);
    new_t->rectangle.setFillColor(sf::Color(127+127*sin(0.03*lngth),127-127*cos(0.03*lngth),127-sin(0.11*lngth)));
    trace.push_back(new_t);
    this->position = sf::Vector2f((100.0f - x) / 200.0 * WINDOW_WIDTH, (100.0f + y) / 200.0 * WINDOW_HEIGHT);
    normal_position = sf::Vector2f(x, y);
check_trace();
}

void Pixel::set_position(sf::Vector2f pos) {

    this->set_position(pos.x, pos.y);
    check_trace();

}

void Pixel::set_color(sf::Color color) {
    this->color = color;
    check_trace();
}

Pixel::Pixel(sf::Vector2f pos, sf::Color color) {
    this->position = sf::Vector2f((100.0f - pos.x) / 200.0 * WINDOW_WIDTH, (100.0f + pos.y) / 200.0 * WINDOW_HEIGHT);
    normal_position = sf::Vector2f(pos.x, pos.y);
    this->color = color;
    this->shape = new sf::CircleShape(radius);
}

Pixel::Pixel(float x, float y, sf::Color color) {
    this->position = sf::Vector2f((100.0f - x) / 200.0 * WINDOW_WIDTH, (100.0f + y) / 200.0 * WINDOW_HEIGHT);
    normal_position = sf::Vector2f(x, y);
    this->color = color;

    this->shape = new sf::CircleShape(radius);
}

void Pixel::check_trace() {
    while (trace.size() > max_trace_length) {
        delete *trace.begin();
        trace.pop_front();
    }
}


