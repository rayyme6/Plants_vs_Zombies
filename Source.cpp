#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <string>
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"
#include "FlyingZombie.h"
#include "Peashooter.h"
#include "Plant_Factory.h"
#include "ZombieFactory.h"

using namespace sf;
using namespace std;

struct Coordinates {
    int x;
    int y;
};

void createBack(RenderWindow& window);
void handleMenu(RenderWindow& window);
void handleInstructions(RenderWindow& window);
void handleGameplay(RenderWindow& window, Plant_Factory& plantFactory, ZombieFactory& zombieFactory, Peashooter& pee, Plant* plants[5][9], bool FIELD_GAME_STATUS[5][9], Zombie* zombies[], int& zombiesGenerated, const int MAX_ZOMBIES, float& time, float zombieGenerationInterval, sf::Clock& zombieClock, Coordinates peashooterPositions[], int& numPeashooters, const int MAX_PEASHOOTERS);
void handlePause(RenderWindow& window);
void handleHighScores(RenderWindow& window);
void handleEnd(RenderWindow& window);

Font font;

int main() {
    Plant_Factory plantFactory;
    ZombieFactory zombieFactory;
    Peashooter pee;

    std::srand(static_cast<unsigned int>(std::time(0)));

    pee.setImage();
    RenderWindow window(VideoMode(1200, 700), "Plants vs Zombies");

    // Load font
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Failed to load font" << endl;
        return -1;
    }

    // Game icon
    Image icon;
    if (icon.loadFromFile("Images/icon.png")) {
        window.setIcon(32, 32, icon.getPixelsPtr());
    }
    else {
        std::cerr << "Failed to load icon" << std::endl;
    }
    window.setFramerateLimit(60);

    const int MAX_ZOMBIES = 10; // Maximum zombies
    int zombiesGenerated = 0;
    sf::Clock zombieClock; // Clock for managing zombie generation
    float zombieGenerationInterval = 2.0f; // Interval between zombie generations

    const int ROWS = 5;
    const int COLS = 9;
    bool FIELD_GAME_STATUS[ROWS][COLS];
    Plant* plants[ROWS][COLS]; // Array for plants
    Zombie* zombies[MAX_ZOMBIES] = { nullptr }; // Fixed-size array for zombies

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            FIELD_GAME_STATUS[i][j] = true;
        }
    }

    Clock clock;

    sf::FloatRect clickArea(0, 0, 1200, 700);
    Coordinates peashooterPositions[10];
    int numPeashooters = 0;

    string currentGameState = "MENU";

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    if (currentGameState == "GAMEPLAY") {
                        currentGameState = "PAUSE";
                    }
                    else if (currentGameState == "PAUSE") {
                        currentGameState = "GAMEPLAY";
                    }
                }
            }

            if (currentGameState == "MENU") {
                if (event.type == sf::Event::MouseButtonPressed) {
                    currentGameState = "GAMEPLAY"; // Example: start game
                }
            }

            if (currentGameState == "PAUSE") {
                if (event.type == sf::Event::MouseButtonPressed) {
                    currentGameState = "GAMEPLAY"; // Example: resume game
                }
            }
        }

        if (currentGameState == "MENU") {
            handleMenu(window);
        }
        else if (currentGameState == "INSTRUCTIONS") {
            handleInstructions(window);
        }
        else if (currentGameState == "GAMEPLAY") {
            handleGameplay(window, plantFactory, zombieFactory, pee, plants, FIELD_GAME_STATUS, zombies, zombiesGenerated, MAX_ZOMBIES, time, zombieGenerationInterval, zombieClock, peashooterPositions, numPeashooters, 10);
        }
        else if (currentGameState == "PAUSE") {
            handlePause(window);
        }
        else if (currentGameState == "HIGH_SCORES") {
            handleHighScores(window);
        }
        else if (currentGameState == "END") {
            handleEnd(window);
        }
    }

    for (int i = 0; i < MAX_ZOMBIES; ++i) {
        delete zombies[i];
    }

    return 0;
}

void handleMenu(RenderWindow& window) {
    window.clear(Color::Black);
    Text title("Game Menu", font, 50);
    title.setPosition(100, 100);
    window.draw(title);
    window.display();
}

void handleInstructions(RenderWindow& window) {
    window.clear(Color::Black);
    Text instructions("Instructions", font, 50);
    instructions.setPosition(100, 100);
    window.draw(instructions);
    window.display();
}

void handleGameplay(RenderWindow& window, Plant_Factory& plantFactory, ZombieFactory& zombieFactory, Peashooter& pee, Plant* plants[5][9], bool FIELD_GAME_STATUS[5][9], Zombie* zombies[], int& zombiesGenerated, const int MAX_ZOMBIES, float& time, float zombieGenerationInterval, sf::Clock& zombieClock, Coordinates peashooterPositions[], int& numPeashooters, const int MAX_PEASHOOTERS) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            int row = (event.mouseButton.y - 80) / 108;
            int col = (event.mouseButton.x - 200) / 108;

            if (row >= 0 && row < 5 && col >= 0 && col < 9 && FIELD_GAME_STATUS[row][col]) {
                plants[row][col] = plantFactory.newPeashooter();
                plants[row][col]->spawn(col * 80 + 250, row * 100 + 80);

                peashooterPositions[numPeashooters].x = event.mouseButton.x;
                peashooterPositions[numPeashooters].y = event.mouseButton.y;
                numPeashooters++;

                if (numPeashooters >= MAX_PEASHOOTERS) {
                    return;
                }

                FIELD_GAME_STATUS[row][col] = false;
            }
        }
    }

    createBack(window);

    for (int i = 0; i < numPeashooters; ++i) {
        pee.spawnPeashooter(peashooterPositions[i].x, peashooterPositions[i].y);
        pee.drawPeashooter(window);
    }

    if (zombiesGenerated < MAX_ZOMBIES && zombieClock.getElapsedTime().asSeconds() >= zombieGenerationInterval) {
        for (int i = 0; i < MAX_ZOMBIES; ++i) {
            if (!zombies[i]) {
                int randomZombieType = std::rand() % 4;
                switch (randomZombieType) {
                case 0:
                    zombies[i] = zombieFactory.newSimpleZombie();
                    break;
                case 1:
                    zombies[i] = zombieFactory.newFootballZombie();
                    break;
                case 2:
                    zombies[i] = zombieFactory.newFlyingZombie();
                    break;
                case 3:
                    zombies[i] = zombieFactory.newDancingZombie();
                    break;
                }
                zombiesGenerated++;
                break;
            }
        }
        zombieClock.restart();
    }

    for (int i = 0; i < MAX_ZOMBIES; ++i) {
        if (zombies[i]) {
            zombies[i]->move();
            zombies[i]->update(window, time);
        }
    }

    window.display();
}

void handlePause(RenderWindow& window) {
    window.clear(Color::Black);
    Text pause("Pause", font, 50);
    pause.setPosition(100, 100);
    window.draw(pause);
    window.display();
}

void handleHighScores(RenderWindow& window) {
    window.clear(Color::Black);
    Text highScores("High Scores", font, 50);
    highScores.setPosition(100, 100);
    window.draw(highScores);
    window.display();
}

void handleEnd(RenderWindow& window) {
    window.clear(Color::Black);
    Text end("Game Over", font, 50);
    end.setPosition(100, 100);
    window.draw(end);
    window.display();
}

void createBack(RenderWindow& window) {
    Image map_image;
    if (map_image.loadFromFile("Images/backwindow.jpg")) {
        Texture map;
        map.loadFromImage(map_image);
        Sprite s_map;
        s_map.setTexture(map);
        s_map.setPosition(0, 0);
        window.draw(s_map);
    }
    else {
        std::cerr << "Failed to load background image" << std::endl;
    }
}

