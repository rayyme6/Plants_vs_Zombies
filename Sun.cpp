#include "Sun.h"

Sun::Sun() : speed(100.0f) {
    if (!sunTexture.loadFromFile("../Images/sun.jpg")) {
        std::cerr << "Failed to load sun image" << std::endl;
    }
    sunSprite.setTexture(sunTexture);
    sunSprite.setScale(0.1f, 0.1f);
}

void Sun::initialize(float startX, float startY) {
    sunSprite.setPosition(startX, startY);
}

void Sun::update(float deltaTime) {
    sunSprite.move(0, speed * deltaTime);
}

void Sun::draw(sf::RenderWindow& window) {
    window.draw(sunSprite);
}

sf::FloatRect Sun::getGlobalBounds() const {
    return sunSprite.getGlobalBounds();
}