#pragma once
#include "Zombie.h"
#include "FlyingZombie.h"
#include <iostream>
#include <cstdlib> // for rand()

// Constructor
FlyingZombie::FlyingZombie() : hitPoints(2), speed(1.2f), directionX(-1.0f) {
    // Initialize a default random position
    initializeRandomPosition(/*1200, 700*/);
    sprite.setScale(0.6f, 0.6f);
}

// Set the image for the flying zombie
void FlyingZombie::setImage(const std::string& file) {
    if (!texture.loadFromFile("Images/flying.png")) {
        std::cerr << "Error: Failed to load flying zombie texture file. Terminating...\n";
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 150, 270)); // Adjust size as needed
}

// Move the flying zombie horizontally
void FlyingZombie::move() {
    // Update position based on direction and speed
    posX += directionX * speed;
    this->setPosition(posX, posY);
}

// Draw the flying zombie on the window
void FlyingZombie::drawZombie(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Update the flying zombie's state every frame
void FlyingZombie::update(sf::RenderWindow& window, double time) {
    this->move(); // Move the zombie

    // Check if zombie is off-screen on the left side and destroy it
    if (posX < -sprite.getGlobalBounds().width) {
        //  std::cerr << "Flying zombie reached the left end and will be removed.\n";
        this->destroy(); // Remove zombie from the game
    }

    // Draw the flying zombie on the window
    this->drawZombie(window);
}

// Initialize the flying zombie at a random position
void FlyingZombie::initializeRandomPosition(/*int windowWidth, int windowHeight*/) {
    // Start just beyond the right edge of the window
    posX = static_cast<float>(1200 + rand() % 100);
    // Random y position within the window height
    posY = static_cast<float>(rand() % 700);

    this->setPosition(posX, posY);
}

// Attack method (placeholder)
void FlyingZombie::attack() {
    // Flying zombies do not have a specific attack; they just move horizontally
}

// Check if the flying zombie is hit by a pea (dummy implementation)
bool FlyingZombie::isHitByPea() {
    // Collision detection logic here
    return false; // Placeholder
}

// Destroy the flying zombie
void FlyingZombie::destroy() {
    // Logic to remove the zombie from the game
   // std::cerr << "Flying zombie is destroyed." << std::endl;
}