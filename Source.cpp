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
void createMap(RenderWindow& window);
void handleMenu(RenderWindow& window, Sprite& menuSprite, Font& font, string& currentGameState);
void handleInstructions(RenderWindow& window, Sprite& instSprite, Font& font, string& currentGameState);
void handleGameplay(RenderWindow& window, Plant_Factory& plantFactory, ZombieFactory& zombieFactory, Peashooter& pee, Plant* plants[5][9], bool FIELD_GAME_STATUS[5][9], Zombie* zombies[], int& zombiesGenerated, const int MAX_ZOMBIES, float& time, float zombieGenerationInterval, sf::Clock& zombieClock, Coordinates peashooterPositions[], int& numPeashooters, const int MAX_PEASHOOTERS);
void handlePause(RenderWindow& window, Font& font, string& currentGameState);
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

    // Load menu image
    Texture menuTexture;
    if (!menuTexture.loadFromFile("Images/lol.JPEG")) { // Replace with your image path
        cerr << "Failed to load menu image" << endl;
        return -1;
    }
    Sprite menuSprite(menuTexture);
    menuSprite.setScale(1.67f, 1.67f);

    // Load instructions image
    Texture instTexture;
    if (!instTexture.loadFromFile("Images/inst.jpg")) { // Replace with your image path
        cerr << "Failed to load instructions image" << endl;
        return -1;
    }
    Sprite instSprite(instTexture);

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
        }

        if (currentGameState == "MENU") {
            handleMenu(window, menuSprite, font, currentGameState);
        }
        else if (currentGameState == "INSTRUCTIONS") {
            handleInstructions(window, instSprite, font, currentGameState);
        }
        else if (currentGameState == "GAMEPLAY") {
            handleGameplay(window, plantFactory, zombieFactory, pee, plants, FIELD_GAME_STATUS, zombies, zombiesGenerated, MAX_ZOMBIES, time, zombieGenerationInterval, zombieClock, peashooterPositions, numPeashooters, 10);
        }
        else if (currentGameState == "PAUSE") {
            handlePause(window, font, currentGameState);
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

void handleMenu(RenderWindow& window, Sprite& menuSprite, Font& font, string& currentGameState) {
    window.clear(Color::Black);
    window.draw(menuSprite);
    Text title("Game Menu", font, 50);
    title.setPosition(10, 100);
    window.draw(title);

    // Add buttons for navigation
    Text startGame("Start Game", font, 40);
    startGame.setPosition(100, 200);
    window.draw(startGame);

    Text instructions("Instructions", font, 40);
    instructions.setPosition(100, 250);
    window.draw(instructions);

    window.display();

    // Event handling for button clicks
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            // Get the mouse position directly
            float mouseX = static_cast<float>(Mouse::getPosition(window).x);
            float mouseY = static_cast<float>(Mouse::getPosition(window).y);

            if (startGame.getGlobalBounds().contains(mouseX, mouseY)) {
                currentGameState = "GAMEPLAY";
            }
            else if (instructions.getGlobalBounds().contains(mouseX, mouseY)) {
                currentGameState = "INSTRUCTIONS";
            }
        }
    }
}

void handleInstructions(RenderWindow& window, Sprite& instSprite, Font& font, string& currentGameState) {
    window.clear(Color::Black);
    window.draw(instSprite);
    Text instructions("Instructions", font, 60);
    instructions.setPosition(10, 10);
    instructions.setFillColor(Color::Black);
    window.draw(instructions);

    // Add a back button
    Text back("Back", font, 40);
    back.setPosition(100, 100);
    back.setFillColor(Color::Black);
    window.draw(back);

    window.display();

    // Event handling for button clicks
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            // Get the mouse position directly
            float mouseX = static_cast<float>(Mouse::getPosition(window).x);
            float mouseY = static_cast<float>(Mouse::getPosition(window).y);

            if (back.getGlobalBounds().contains(mouseX, mouseY)) {
                currentGameState = "MENU";
            }
        }
    }
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
    createMap(window);

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

void handlePause(RenderWindow& window, Font& font, string& currentGameState) {
    window.clear(Color::Black);
    Text pause("Pause", font, 50);
    pause.setPosition(100, 100);
    window.draw(pause);

    // Add resume button
    Text resume("Resume", font, 30);
    resume.setPosition(100, 200);
    window.draw(resume);

    window.display();

    // Event handling for button clicks
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            // Get the mouse position directly
            float mouseX = static_cast<float>(Mouse::getPosition(window).x);
            float mouseY = static_cast<float>(Mouse::getPosition(window).y);

            if (resume.getGlobalBounds().contains(mouseX, mouseY)) {
                currentGameState = "GAMEPLAY";
            }
        }
    }
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

void createMap(RenderWindow& window) {
    // Uncomment and adjust if you want to add the map image
    // Image map_image;
    // if (map_image.loadFromFile("../Images/grid.png")) {
    //     Texture map;
    //     map.loadFromImage(map_image);
    //     Sprite s_map;
    //     s_map.setTexture(map);
    //     s_map.setPosition(300, 160);
    //     window.draw(s_map);
    // } else {
    //     std::cerr << "Failed to load map image" << std::endl;
    // }
}