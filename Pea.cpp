//#include "Pea.h"
//#include "SFML/Graphics.hpp"
//#include <iostream>
//
//Pea::Pea()
//{
//    if (!texture.loadFromFile("Images/pea.png")) {
//        std::cerr << "Error loading pea texture." << std::endl;
//        // Handle error...
//    }
//    sprite.setTexture(texture);
//}
//
//void Pea::setPosition(float x, float y)
//{
//    sprite.setPosition(x, y);
//}
//
//void Pea::setDx(double d)
//{
//    this->dx = d;
//}
//
//void Pea::update(double dt)
//{
//    float moveAmount = static_cast<float>(dx * dt);
//    sprite.move(moveAmount, 0);
//}
//
//void Pea::draw(sf::RenderTarget& target, sf::RenderStates states)
//{
//    target.draw(sprite, states);
//}