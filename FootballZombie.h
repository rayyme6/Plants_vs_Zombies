#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>

class FootballZombie : public Zombie {
private:
    int hitPoints;
    float speed;
    float directionX;
    float directionY;
    float posX;
    float posY;

public:
    // Constructor
    FootballZombie();

    // Set the football zombie image
    void setImage(const std::string& file);

    // Move the football zombie
    void move() override;

    // Draw the football zombie on the window
    void drawZombie(sf::RenderWindow& window);

    // Update the football zombie's state every frame
    void update(sf::RenderWindow& window, double time) override;

    // Attack method (placeholder)
    void attack() override;

    // Check if the football zombie is hit
    bool isHitByPea();

    // Destroy the football zombie
    void destroy();

    // Initialize the football zombie at a random position
    void initializeRandomPosition(/*int windowWidth, int windowHeight*/);
};