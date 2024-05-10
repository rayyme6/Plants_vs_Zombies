#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>

class DancingZombie : public Zombie {
private:
    int hitPoints;
    float speed;
    float directionX;
    float directionY;
    float posX;
    float posY;

public:
    // Constructor
    DancingZombie();

    // Set the dancing zombie image
    void setImage(const std::string& file);

    // Move the dancing zombie diagonally
    void move() override;

    // Draw the dancing zombie on the window
    void drawZombie(sf::RenderWindow& window);

    // Update the dancing zombie's state every frame
    void update(sf::RenderWindow& window, double time) override;

    // Attack method (placeholder)
    void attack() override;

    // Check if the dancing zombie is hit
    bool isHitByPea();

    // Destroy the dancing zombie
    void destroy();

    // Initialize the dancing zombie at a random position
    void initializeRandomPosition(/*int windowWidth, int windowHeight*/);
};