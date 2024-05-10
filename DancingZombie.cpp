#include "DancingZombie.h"
#include <iostream>
#include <cstdlib> // for rand()

// Constructor
DancingZombie::DancingZombie() : hitPoints(4), speed(0.7f), directionX(-1.0f), directionY(0.5f) {
    // Initialize a default random position
    initializeRandomPosition(/*1200, 700*/);
    sprite.setScale(0.6f, 0.6f);
}

// Set the image for the dancing zombie
void DancingZombie::setImage(const std::string& file) {
    if (!texture.loadFromFile("Images/dancing.png")) {
        std::cerr << "Error: Failed to load dancing zombie texture file. Terminating...\n";
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 150, 270)); // Adjust size as needed
}

// Move the dancing zombie diagonally
void DancingZombie::move() {
    // Update position based on direction and speed
    posX += directionX * speed;
    posY += directionY * speed;

    // Ensure it stays within the window's vertical bounds
    if (posY < 0 || posY > 700 - sprite.getGlobalBounds().height) {
        directionY = -directionY; // Bounce back vertically
    }

    this->setPosition(posX, posY);
}

// Draw the dancing zombie on the window
void DancingZombie::drawZombie(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Update the dancing zombie's state every frame
void DancingZombie::update(sf::RenderWindow& window, double time) {
    this->move(); // Move the zombie

    // Check if zombie is off-screen on the left side and destroy it
    if (posX < -sprite.getGlobalBounds().width) {
        std::cerr << "Dancing zombie reached the left end and will be removed.\n";
        this->destroy(); // Remove zombie from the game
    }

    // Draw the dancing zombie on the window
    this->drawZombie(window);
}

// Initialize the dancing zombie at a random position
void DancingZombie::initializeRandomPosition(/*int windowWidth, int windowHeight*/) {
    // Start just beyond the right edge of the window
    posX = static_cast<float>(1200 + rand() % 100);
    // Random y position within the window height
    posY = static_cast<float>(rand() % 700);

    this->setPosition(posX, posY);
}

// Attack method (placeholder)
void DancingZombie::attack() {
    // Dancing zombies do not have a specific attack; they just move diagonally
}

// Check if the dancing zombie is hit by a pea (dummy implementation)
bool DancingZombie::isHitByPea() {
    // Collision detection logic here
    return false; // Placeholder
}

// Destroy the dancing zombie
void DancingZombie::destroy() {
    // Logic to remove the zombie from the game
    std::cerr << "Dancing zombie is destroyed." << std::endl;
}