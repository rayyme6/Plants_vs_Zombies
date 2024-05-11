#include "SimpleZombie.h"
#include <iostream>
#include <cstdlib> // for rand()

// Constructor
SimpleZombie::SimpleZombie() : hitPoints(3), speed(1.7f), directionX(-1.0f), directionY(0.0f) {
    // Set a random starting position on the right side of the window
  ///  posX = static_cast<float>(800 + rand() % 100); // Start just beyond the right window edge
  //  posY = static_cast<float>(rand() % 600);
    initializeRandomPosition(/*1200, 700*/);
    sprite.setScale(0.6f, 0.6f);
    if (!texture.loadFromFile("Images/simple.png")) {
        std::cerr << "Error: Failed to load zombie texture file. Terminating...\n";
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 170, 270)); // Adjust size as needed
    this->setPosition(posX, posY); // Initial position

}
// Initialize the zombie at a random position
void SimpleZombie::initializeRandomPosition(/*int windowWidth, int windowHeight*/) {
    // Start just beyond the right edge of the window
    posX = static_cast<float>(1000 + rand() % 100);// 1200 is windowwidth
    // Random y position within the window height
    posY = static_cast<float>(rand() % 700);// 800 is window height

    this->setPosition(posX, posY);
    move();
}
// Set the image for the zombie
//void SimpleZombie::setImage(const std::string& file) {
//    if (!texture.loadFromFile("../Images/simple.png")) {
//        std::cerr << "Error: Failed to load zombie texture file. Terminating...\n";
//        return;
//    }
//    sprite.setTexture(texture);
//    sprite.setTextureRect(sf::IntRect(0, 0, 170, 270)); // Adjust size as needed
//}

// Move the zombie forward
void SimpleZombie::move() {
    // Update position based on direction and speed
    posX += directionX * speed;
    posY += directionY * speed;
    this->setPosition(posX, posY);
}

// Draw the zombie on the window
void SimpleZombie::drawZombie(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Update the zombie's state every frame
void SimpleZombie::update(sf::RenderWindow& window, double time) {
    this->move(); // Move the zombie

    //// Check for collisions or other game logic to reduce hit points
    //if (this->isHitByPea()) {
    //    hitPoints -= 1;
    //    if (hitPoints <= 0) {
    //        this->destroy(); // Remove zombie from the game
    //    }
    //}

    // Draw the zombie on the window
    this->drawZombie(window);
}

// Attack method (placeholder)
void SimpleZombie::attack() {
    // Simple zombies do not have an attack; they just move forward
}

// Helper function to check if the zombie is hit by a pea (dummy implementation)
bool SimpleZombie::isHitByPea() {
    // Collision detection logic here
    return false; // Placeholder
}

// Destroy the zombie
void SimpleZombie::destroy() {
    // Logic to remove the zombie from the game
}