#include "FlyingZombie.h"
#pragma once
#include "Zombie.h"


FlyingZombie::FlyingZombie() {

}
void FlyingZombie::move() {
    setYPosition(getYPosition() - 1);
}
void FlyingZombie::attack() {

}
void FlyingZombie::update(sf::RenderWindow& window, double time) {

}

void FlyingZombie::setHealth(int h)
{
    health = h;
}

void FlyingZombie::setDamage(int d)
{
    damage = d;
}

void FlyingZombie::setIsMoving(bool moving)
{
    isMoving = moving;
}