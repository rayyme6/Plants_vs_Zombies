#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>

class SimpleZombie : public Zombie {
private:
    int hitPoints;
    float speed;
    float directionX;
    float directionY;
    float posX;
    float posY;

public:
    // Constructor
    SimpleZombie();

    // Set the zombie image
    void setImage(const std::string& file);

    // Move the zombie forward
    void move() override;

    // Draw the zombie on the window
    void drawZombie(sf::RenderWindow& window);

    // Update the zombie's state every frame
    void update(sf::RenderWindow& window, double time) override;

    // Attack method (placeholder)
    void attack() override;

    // Helper function to check if the zombie is hit
    bool isHitByPea();

    // Destroy the zombie
    void destroy();
    void initializeRandomPosition(/*int windowWidth, int windowHeight*/);

};