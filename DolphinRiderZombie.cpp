#include "DolphinRiderZombie.h"
#pragma once
#include "Zombie.h"


DolphinRiderZombie::DolphinRiderZombie() {
    speed = 3; // Very fast
}
void DolphinRiderZombie::move() {
    setXPosition(getXPosition() - speed); // Fast horizontal movement
}
void DolphinRiderZombie::attack() {

}
void DolphinRiderZombie::update(sf::RenderWindow& window, double time) {

}

void DolphinRiderZombie::setHealth(int h)
{
    health = h;
}

void DolphinRiderZombie::setDamage(int d)
{
    damage = d;
}

void DolphinRiderZombie::setIsMoving(bool moving)
{
    isMoving = moving;
}