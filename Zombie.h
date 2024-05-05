#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Time.h"
#include <ctime>
using namespace std;

class Zombie {
protected:
    int x_position;
    int y_position;
    int speed;
    int health;
    int damage;
    bool isMoving;


public:
    Zombie(); // Constructor
    virtual ~Zombie() {} // Virtual destructor

    // Getters
    int getXPosition() const;
    int getYPosition() const;
    int getHealth() const;
    int getDamage() const;
    bool getIsMoving() const;

    // Setters
    void setXPosition(int x);
    void setYPosition(int y);

    // Virtual methods for behavior
    virtual void move() = 0;
    virtual void attack() = 0;
    virtual void update(sf::RenderWindow& window, double time) = 0;
    virtual void setHealth(int h) = 0;
    virtual void setDamage(int d) = 0;
    virtual void setIsMoving(bool moving) = 0;
};
