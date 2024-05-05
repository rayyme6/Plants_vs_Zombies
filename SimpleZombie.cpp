#include "SimpleZombie.h"
#pragma once 
#include "Zombie.h"

SimpleZombie::SimpleZombie() {

}
void SimpleZombie::move() {
    if (getIsMoving()) {
        setXPosition(getXPosition() - speed);
    }
}
void SimpleZombie::attack() {

}
void SimpleZombie::update(sf::RenderWindow& window, double time) {

}

void SimpleZombie::setHealth(int h)
{
    health = h;
}

void SimpleZombie::setDamage(int d)
{
    damage = d;
}

void SimpleZombie::setIsMoving(bool moving)
{
    isMoving = moving;
}