#include <iostream>
#include "SFML/Graphics.hpp"
#include "Simulation/Utilities/Shapes.h"
#include "Simulation/Utilities/Coordinate.h"
#include "Simulation/transformation.h"
#include <cmath>
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
sf::Vector2f func_shrink(sf::Vector2f new_pos,sf::Vector2f start_pos,int frame){
    //std::cout<<new_pos.x<<std::endl;
    return new_pos*0.9999f;
}
sf::Vector2f func_rotate(sf::Vector2f new_pos,sf::Vector2f start_pos,int frame){
    float x_new = 0;
    float y_new = 0;
    float x = new_pos.x;
    float y = new_pos.y;
    x_new = x*cos(0.04)+y*sin(0.003);
    y_new = -x*sin(0.003)+y*cos(0.003);
    return sf::Vector2f(x_new,y_new);
}
int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "none");
    Drawable::Set_Size(WINDOW_WIDTH,WINDOW_HEIGHT);
    simulate(WINDOW_WIDTH,WINDOW_HEIGHT,window,func_rotate);
}
