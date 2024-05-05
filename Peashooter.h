#pragma once
#include "Plant.h"
#include "SFML/Graphics.hpp"

class Peashooter : public Plant
{
private:
	sf::Texture peashooterTexture;
	sf::Sprite peashooterSprite;
public:
	void setImage();
	void drawPeashooter(sf::RenderWindow& window);
	void spawnPeashooter(int x, int y);
	void peaShootpoint();
	void setDx(double d);
	void updatePea(sf::RenderWindow& window, double time);
	void setHealth(int h);
	void setDamage(int d);
	int getHealth();
	int getDamage();
	bool needToAttack(bool a);
	int getCost();
	void setCost(int c);
};

