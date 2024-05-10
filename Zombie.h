#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Zombie {
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    int xPosition;
    int yPosition;
    int speed;
    int health;
    int damage;
    bool isMoving;

public:
    // Constructor
    Zombie();

    // Virtual destructor
    virtual ~Zombie();

    // Getters
    int getXPosition() const;
    int getYPosition() const;
    int getHealth() const;
    int getDamage() const;
    bool getIsMoving() const;

    // Setters
    void setXPosition(int x);
    void setYPosition(int y);
    void setHealth(int h);
    void setDamage(int d);
    void setIsMoving(bool moving);

    // Set texture from a file path
    void setTexture(const std::string& file);

    // Set sprite position
    void setPosition(float x, float y);

    // Retrieve the current sprite
    const sf::Sprite& getSprite() const;

    // Pure virtual methods for behavior
    virtual void move() = 0;
    virtual void attack() = 0;
    virtual void update(sf::RenderWindow& window, double time) = 0;
};
