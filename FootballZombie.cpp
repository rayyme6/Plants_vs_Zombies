#include "FootballZombie.h"
#pragma once
#include "Zombie.h"

FootballZombie::FootballZombie() {
    speed = 2; // Faster than a simple zombie
}
void FootballZombie::move() {
    setXPosition(getXPosition() - speed);
}
void FootballZombie::attack() {

}
void FootballZombie::update(sf::RenderWindow& window, double time) {

}

void FootballZombie::setHealth(int h)
{
    health = h;
}

void FootballZombie::setDamage(int d)
{
    damage = d;
}

void FootballZombie::setIsMoving(bool moving)
{
    isMoving = moving;
}