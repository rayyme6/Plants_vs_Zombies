#include "Game.h"
#include <cstdlib>

Game::Game() : numSuns(0), sunCount(0) {}

void Game::spawnSun() {
    float sunStartX = static_cast<float>(std::rand() % 1100);
    if (numSuns < MAX_SUNS) {
        suns[numSuns].initialize(sunStartX, 0);
        ++numSuns;
    }
}

void Game::handleSunCollection(float mouseX, float mouseY) {
    for (int i = 0; i < numSuns; ++i) {
        if (suns[i].getGlobalBounds().contains(mouseX, mouseY)) {
            sunCount += 25;
            for (int j = i; j < numSuns - 1; ++j) {
                suns[j] = suns[j + 1];
            }
            --numSuns;
            --i;
        }
    }
}

void Game::updateSuns(float deltaTime, sf::RenderWindow& window) {
    for (int i = 0; i < numSuns; ++i) {
        suns[i].update(deltaTime);
    }
}

void Game::drawSuns(sf::RenderWindow& window) {
    for (int i = 0; i < numSuns; ++i) {
        suns[i].draw(window);
    }
}