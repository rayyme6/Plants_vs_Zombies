#pragma once
#include "Plant.h"

class Repeater : public Plant
{
	void setImage();
	//void drawPlant(sf::RenderWindow& window);
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

