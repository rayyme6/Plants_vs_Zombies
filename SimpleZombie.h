#pragma once
#include "Zombie.h"

class SimpleZombie : public Zombie {
public:
    SimpleZombie();
    void move();
    void attack();
    void update(sf::RenderWindow& window, double time);    
    void setHealth(int h);
    void setDamage(int d);
    void setIsMoving(bool moving);
};