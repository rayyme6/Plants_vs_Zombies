#include "FootballZombie.h"
#include <iostream>
#include <cstdlib> // for rand()

// Constructor
FootballZombie::FootballZombie() : hitPoints(5), speed(1.0f), directionX(-1.0f), directionY(0.0f) {
    // Initialize a default random position
    initializeRandomPosition();
    if (!texture.loadFromFile("Images/fooball.png")) {
        std::cerr << "Error: Failed to load football zombie texture file. Terminating...\n";
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 150, 270)); // Adjust size as needed
    sprite.setScale(0.6f, 0.6f);
}

// Set the image for the football zombie
//void FootballZombie::setImage(const std::string& file) {
//    if (!texture.loadFromFile("../Images/fooball.png")) {
//        std::cerr << "Error: Failed to load football zombie texture file. Terminating...\n";
//        return;
//    }
//    sprite.setTexture(texture);
//    sprite.setTextureRect(sf::IntRect(0, 0, 150, 270)); // Adjust size as needed
//}

// Move the football zombie from right to left
void FootballZombie::move() {
    // Update position based on direction and speed
    posX += directionX * speed;
    this->setPosition(posX, posY);
}

// Draw the football zombie on the window
void FootballZombie::drawZombie(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Update the football zombie's state every frame
void FootballZombie::update(sf::RenderWindow& window, double time) {
    this->move(); // Move the zombie

    // Check if the zombie is off-screen on the left side and destroy it
    if (posX < -sprite.getGlobalBounds().width) {
        //  std::cerr << "Football zombie reached the left end and will be removed.\n";
        this->destroy(); // Remove the zombie from the game
    }

    // Draw the football zombie on the window
    this->drawZombie(window);
}

// Initialize the football zombie at a random position
void FootballZombie::initializeRandomPosition(/*int windowWidth, int windowHeight*/) {
    // Start just beyond the right edge of the window
    posX = static_cast<float>(1200 + rand() % 100);
    // Random y position within the window height
    posY = static_cast<float>(rand() % 700);

    this->setPosition(posX, posY);
}

// Attack method (placeholder)
void FootballZombie::attack() {
    // Football zombies do not have a specific attack; they just move forward
}

// Check if the football zombie is hit by a pea (dummy implementation)
bool FootballZombie::isHitByPea() {
    // Collision detection logic here
    return false; // Placeholder
}

// Destroy the football zombie
void FootballZombie::destroy() {
    // Logic to remove the zombie from the game
   // std::cerr << "Football zombie is destroyed." << std::endl;
}