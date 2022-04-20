#include "size.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <cstdio>


void scaleToMaxSize(sf::Sprite &object){
    float xmax = 1920;
    float ymax = 1080;
    auto rec = object.getGlobalBounds();

    object.setScale(sf::Vector2f(xmax/rec.width, ymax/rec.height));
}

void scaleToMinSize(sf::Sprite &object){
    float xmin = 50;
    float ymin = 50;
    auto rec = object.getGlobalBounds();

    object.setScale(sf::Vector2f(xmin/rec.width, ymin/rec.height));
}