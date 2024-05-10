#pragma once
#include "Plant.h"
#include "Pea.h"
#include "SFML/Graphics.hpp"

class Peashooter : public Plant
{
private:
	
public:
	Peashooter();
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
	//// New member function to check if the peashooter can shoot
	//bool canShootPea();

	//// New member function to shoot a pea
	//Pea shootPea();
};

