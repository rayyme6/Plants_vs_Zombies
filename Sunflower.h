#pragma once
#include "Plant.h"

class Sunflower : public Plant
{
private:
	Time cooldown;
public:
	Sunflower();
	void generateSun();
	//void drawPlant(sf::RenderWindow& window);
	void setImage();
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

