#include "DancingZombie.h"
#pragma once
#include "Zombie.h"


DancingZombie::DancingZombie() {

}
void DancingZombie::move() {
    setXPosition(getXPosition() - speed); // Normal horizontal movement
}
void DancingZombie::attack() {

}
void DancingZombie::update(sf::RenderWindow& window, double time) {

}

void DancingZombie::setHealth(int h)
{
    health = h;
}

void DancingZombie::setDamage(int d)
{
    damage = d;
}

void DancingZombie::setIsMoving(bool moving)
{
    isMoving = moving;
}