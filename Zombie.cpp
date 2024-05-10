#include "Zombie.h"
#include <iostream>

// Constructor
Zombie::Zombie() : xPosition(0), yPosition(0), speed(0), health(100), damage(10), isMoving(false) {}

// Virtual destructor
Zombie::~Zombie() {}

// Getters
int Zombie::getXPosition() const {
    return xPosition;
}

int Zombie::getYPosition() const {
    return yPosition;
}

int Zombie::getHealth() const {
    return health;
}

int Zombie::getDamage() const {
    return damage;
}

bool Zombie::getIsMoving() const {
    return isMoving;
}

// Setters
void Zombie::setXPosition(int x) {
    xPosition = x;
}

void Zombie::setYPosition(int y) {
    yPosition = y;
}

void Zombie::setHealth(int h) {
    health = h;
}

void Zombie::setDamage(int d) {
    damage = d;
}

void Zombie::setIsMoving(bool moving) {
    isMoving = moving;
}

// Set texture from a file path
void Zombie::setTexture(const std::string& file) {
    if (!texture.loadFromFile("simple.jpg")) {
        std::cerr << "Failed to load texture file: " << file << std::endl;
    }
    else {
        sprite.setTexture(texture);
    }
}

// Set sprite position
void Zombie::setPosition(float x, float y) {
    sprite.setPosition(x, y);
    xPosition = static_cast<int>(x);
    yPosition = static_cast<int>(y);
}

// Retrieve the current sprite
const sf::Sprite& Zombie::getSprite() const {
    return sprite;
}