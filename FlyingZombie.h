#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>

class FlyingZombie : public Zombie {
private:
    int hitPoints;
    float speed;
    float directionX;
    float posX;
    float posY;

public:
    // Constructor
    FlyingZombie();

    // Set the flying zombie image
    void setImage(const std::string& file);

    // Move the flying zombie
    void move() override;

    // Draw the flying zombie on the window
    void drawZombie(sf::RenderWindow& window);

    // Update the flying zombie's state every frame
    void update(sf::RenderWindow& window, double time) override;

    // Attack method (placeholder)
    void attack() override;

    // Check if the flying zombie is hit
    bool isHitByPea();

    // Destroy the flying zombie
    void destroy();

    // Initialize the flying zombie at a random position
    void initializeRandomPosition(/*int windowWidth, int windowHeight*/);
};