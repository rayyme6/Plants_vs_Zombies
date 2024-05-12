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
#include "Game.h"

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
void handleGameplay(RenderWindow& window, Plant_Factory& plantFactory, ZombieFactory& zombieFactory, Peashooter& pee, Plant* plants[5][9], bool FIELD_GAME_STATUS[5][9], Zombie* zombies[], int& zombiesGenerated, const int MAX_ZOMBIES, float& time, float zombieGenerationInterval, sf::Clock& zombieClock, Coordinates peashooterPositions[], int& numPeashooters, const int MAX_PEASHOOTERS, int& lives, string& currentGameState, Game& game, Sprite& pauseSprite, Sprite& highScoresButtonSprite);
void handlePause(RenderWindow& window, Font& font, string& currentGameState, Sprite& pauseSprite, Sprite& pauseBackgroundSprite);
void handleHighScores(RenderWindow& window, Sprite& high, string& currentGameState);
void handleEnd(RenderWindow& window, Font& font, Sprite& overSprite);

Font font;

int main() {
    Plant_Factory plantFactory;
    ZombieFactory zombieFactory;
    Peashooter pee;
    Game game;

    std::srand(static_cast<unsigned int>(std::time(0)));

    pee.setImage();
    RenderWindow window(VideoMode(1200, 700), "Plants vs Zombies");

    // Load font
    if (!font.loadFromFile("../Images/arial.ttf")) {
        cerr << "Failed to load font" << endl;
        return -1;
    }
    if (!font.loadFromFile("../Images/BLOOD.ttf")) {
        cerr << "Failed to load BLOOD font" << endl;
        return -1;
    }

    // Load menu image
    Texture menuTexture;
    if (!menuTexture.loadFromFile("../Images/lol.jpeg")) {
        cerr << "Failed to load menu image" << endl;
        return -1;
    }
    Sprite menuSprite(menuTexture);
    menuSprite.setScale(1.69f, 1.69f);

    // Load instructions image
    Texture instTexture;
    if (!instTexture.loadFromFile("../Images/inst.jpg")) {
        cerr << "Failed to load instructions image" << endl;
        return -1;
    }
    Sprite instSprite(instTexture);

    // Load game over image
    Texture overTexture;
    if (!overTexture.loadFromFile("../Images/gameoverfinal.jpeg")) {
        cerr << "Failed to load game over image" << endl;
        return -1;
    }
    Sprite overSprite(overTexture);

    // Load pause button image
    Texture pauseTexture;
    if (!pauseTexture.loadFromFile("../Images/pausesprite.jpg")) {
        cerr << "Failed to load pause button image" << endl;
        return -1;
    }
    Sprite pauseSprite(pauseTexture);
    pauseSprite.setPosition(1100, 20);
    pauseSprite.setScale(0.3f, 0.3f);

    // Load pause background image
    Texture pauseBackgroundTexture;
    if (!pauseBackgroundTexture.loadFromFile("../Images/pause.jpg")) {
        cerr << "Failed to load pause background image" << endl;
        return -1;
    }
    Sprite pauseBackgroundSprite(pauseBackgroundTexture);
    pauseBackgroundSprite.setPosition(0, 0);
    pauseBackgroundSprite.setScale(2.6f, 2.2f);

    // Load high scores button image
    Texture highScoresButtonTexture;
    if (!highScoresButtonTexture.loadFromFile("../Images/high.jpg")) {
        cerr << "Failed to load high scores button image" << endl;
        return -1;
    }
    Sprite highScoresButtonSprite(highScoresButtonTexture);
    highScoresButtonSprite.setPosition(1100, 100);
    highScoresButtonSprite.setScale(0.6f, 0.6f);

    // Load high scores background image
    Texture highTexture;
    if (!highTexture.loadFromFile("../Images/score.jpg")) {
        cerr << "Failed to load high scores background image" << endl;
        return -1;
    }
    Sprite high(highTexture);
    high.setPosition(1100, 100);
    high.setScale(0.6f, 0.6f);

    // Game icon
    Image icon;
    if (icon.loadFromFile("../Images/extra.png")) {
        window.setIcon(32, 32, icon.getPixelsPtr());
    }
    else {
        cerr << "Failed to load icon" << endl;
    }
    window.setFramerateLimit(60);

    const int MAX_ZOMBIES = 10;
    int zombiesGenerated = 0;
    sf::Clock zombieClock;
    float zombieGenerationInterval = 2.0f;

    const int ROWS = 5;
    const int COLS = 9;
    bool FIELD_GAME_STATUS[ROWS][COLS];
    Plant* plants[ROWS][COLS];
    Zombie* zombies[MAX_ZOMBIES] = { nullptr };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            FIELD_GAME_STATUS[i][j] = true;
        }
    }

    Clock clock;
    Coordinates peashooterPositions[10];
    int numPeashooters = 0;
    int lives = 3;

    string currentGameState = "MENU";

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::MouseButtonPressed) {
                float mouseX = static_cast<float>(Mouse::getPosition(window).x);
                float mouseY = static_cast<float>(Mouse::getPosition(window).y);

                // Handle pause button click
                if (pauseSprite.getGlobalBounds().contains(mouseX, mouseY) && currentGameState == "GAMEPLAY") {
                    currentGameState = "PAUSE";
                }

                // Handle high scores button click
                if (highScoresButtonSprite.getGlobalBounds().contains(mouseX, mouseY) && currentGameState == "GAMEPLAY") {
                    currentGameState = "HIGH_SCORES";
                }

                // Handle sun collection
                game.handleSunCollection(mouseX, mouseY);
            }
            if (event.type == Event::Closed) {
                window.close();
            }


        }

        if (currentGameState == "MENU") {
            handleMenu(window, menuSprite, font, currentGameState);
        }
        else if (currentGameState == "INSTRUCTIONS") {
            handleInstructions(window, instSprite, font, currentGameState);
        }
        else if (currentGameState == "GAMEPLAY") {
            handleGameplay(window, plantFactory, zombieFactory, pee, plants, FIELD_GAME_STATUS, zombies, zombiesGenerated, MAX_ZOMBIES, time, zombieGenerationInterval, zombieClock, peashooterPositions, numPeashooters, 10, lives, currentGameState, game, pauseSprite, highScoresButtonSprite);
        }
        else if (currentGameState == "PAUSE") {
            handlePause(window, font, currentGameState, pauseSprite, pauseBackgroundSprite);
        }
        else if (currentGameState == "HIGH_SCORES") {
            handleHighScores(window, high, currentGameState);
        }
        else if (currentGameState == "END") {
            handleEnd(window, font, overSprite);
        }
    }

    for (int i = 0; i < MAX_ZOMBIES; ++i) {
        delete zombies[i];
    }

    return 0;
}

void handleMenu(RenderWindow& window, Sprite& menuSprite, Font& font, string& currentGameState) {
    window.clear(Color::Red);
    window.draw(menuSprite);
    Text title("Game Menu", font, 80);
    title.setFillColor(Color::Black);
    title.setPosition(420, 240);
    window.draw(title);

    // Add buttons for navigation
    Text startGame("Start Game", font, 60);
    startGame.setPosition(470, 350);
    startGame.setFillColor(Color::Red);
    window.draw(startGame);

    Text instructions("Instructions", font, 50);
    instructions.setPosition(490, 430);
    instructions.setFillColor(Color::Red);
    window.draw(instructions);

    window.display();

    // Event handling for button clicks
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
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
    Text instructions("Instructions", font, 50);
    instructions.setPosition(800, 230);
    instructions.setFillColor(Color::White);
    window.draw(instructions);

    Text back("Back", font, 70);
    back.setPosition(950, 280);
    back.setFillColor(Color::Red);
    window.draw(back);

    window.display();

    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            float mouseX = static_cast<float>(Mouse::getPosition(window).x);
            float mouseY = static_cast<float>(Mouse::getPosition(window).y);

            if (back.getGlobalBounds().contains(mouseX, mouseY)) {
                currentGameState = "MENU";
            }
        }
    }
}

void handleGameplay(RenderWindow& window, Plant_Factory& plantFactory, ZombieFactory& zombieFactory, Peashooter& pee, Plant* plants[5][9], bool FIELD_GAME_STATUS[5][9], Zombie* zombies[], int& zombiesGenerated, const int MAX_ZOMBIES, float& time, float zombieGenerationInterval, sf::Clock& zombieClock, Coordinates peashooterPositions[], int& numPeashooters, const int MAX_PEASHOOTERS, int& lives, string& currentGameState, Game& game, Sprite& pauseSprite, Sprite& highScoresButtonSprite) {


    createBack(window);
    createMap(window);
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
    for (int i = 0; i < numPeashooters; ++i) {
        pee.spawnPeashooter(peashooterPositions[i].x, peashooterPositions[i].y);
        pee.drawPeashooter(window);
    }

    if (zombiesGenerated < MAX_ZOMBIES && zombieClock.getElapsedTime().asSeconds() >= zombieGenerationInterval) {
        for (int i = 0; i < MAX_ZOMBIES; ++i) {
            if (!zombies[i]) {
                int randomZombieType = std::rand() % 4;
                int randomRow = std::rand() % 5;
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
                zombies[i]->setPosition(1200, randomRow * 100 + 80);
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
            if (zombies[i]->getXPosition() <= 0) {
                delete zombies[i];
                zombies[i] = nullptr;
                lives--;
                if (lives <= 0) {
                    currentGameState = "END";
                }
            }
        }
    }

    game.updateSuns(time, window);
    game.drawSuns(window);

    window.draw(pauseSprite);
    window.draw(highScoresButtonSprite);
    window.display();
}

void handleHighScores(RenderWindow& window, Sprite& high, string& currentGameState) {
    window.clear(Color::Black);
    Text highScores("High Scores", font, 50);
    highScores.setPosition(100, 100);
    window.draw(highScores);
    window.draw(high);
    high.setPosition(0, 0);
    high.setScale(2.58f, 2.59f);
    Text resume("Resume", font, 60);
    resume.setPosition(100, 150);
    resume.setFillColor(Color::Red);
    window.draw(resume);
    window.display();

    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            float mouseX = static_cast<float>(Mouse::getPosition(window).x);
            float mouseY = static_cast<float>(Mouse::getPosition(window).y);

            if (resume.getGlobalBounds().contains(mouseX, mouseY)) {
                currentGameState = "GAMEPLAY";
            }
        }
    }
}

void handlePause(RenderWindow& window, Font& font, string& currentGameState, Sprite& pauseSprite, Sprite& pauseBackgroundSprite) {
    window.clear(Color::Black);
    Text pause("Pause", font, 50);
    pause.setPosition(-100, -100);
    pause.setFillColor(Color::White);
    window.draw(pauseSprite);
    window.draw(pauseBackgroundSprite);
    window.draw(pause);

    Text resume("Resume Game", font, 36);
    resume.setPosition(511, 540);
    resume.setFillColor(Color::Green);
    window.draw(resume);

    window.display();

    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            float mouseX = static_cast<float>(Mouse::getPosition(window).x);
            float mouseY = static_cast<float>(Mouse::getPosition(window).y);

            if (resume.getGlobalBounds().contains(mouseX, mouseY)) {
                currentGameState = "GAMEPLAY";
            }
        }
    }
}

void handleEnd(RenderWindow& window, Font& font, Sprite& overSprite) {
    Text end("Game Over", font, 100);
    end.setPosition(100, 100);
    end.setFillColor(Color::White);
    window.draw(overSprite);
    window.display();
}

void createBack(RenderWindow& window) {
    Image mapImage;
    if (mapImage.loadFromFile("../Images/finalgrid.JPEG")) {
        Texture map;
        map.loadFromImage(mapImage);
        Sprite sMap;
        sMap.setTexture(map);
        sMap.setPosition(0, 0);
        window.draw(sMap);
    }
    else {
        cerr << "Failed to load background image" << endl;
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