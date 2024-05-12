#pragma once
#include "Sun.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void spawnSun();
    void handleSunCollection(float mouseX, float mouseY);
    void updateSuns(float deltaTime, sf::RenderWindow& window);
    void drawSuns(sf::RenderWindow& window);

private:
    static const int MAX_SUNS = 50;
    Sun suns[MAX_SUNS];
    int numSuns;
    int sunCount;
};