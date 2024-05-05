#pragma once
#include "Zombie.h"

class DancingZombie : public Zombie {
public:
    DancingZombie();
    void move();
    void attack();
    void update(sf::RenderWindow& window, double time);
    void setHealth(int h);
    void setDamage(int d);
    void setIsMoving(bool moving);
};
