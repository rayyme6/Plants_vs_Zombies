#include "Wallnut.h"

void Wallnut::setImage()
{
	//set sprite
}

//void Wallnut::drawPlant(sf::RenderWindow& window)
//{
//	//window.draw(peashooterSprite);
//}

void Wallnut::peaShootpoint()
{
	//does not shoot
}

void Wallnut::setDx(double d)
{
	//does not shoot
}

void Wallnut::updatePea(sf::RenderWindow& window, double time)
{
	//does not shoot
}

void Wallnut::setHealth(int h = 250)
{
	health = h;
}

void Wallnut::setDamage(int d = 0)
{
	damage = d;
}

int Wallnut::getHealth()
{
	return health;
}

int Wallnut::getDamage()
{
	return damage;
}

bool Wallnut::needToAttack(bool a)
{
	//does not attack;
	attack_zombie = a;
	return attack_zombie;
}

int Wallnut::getCost()
{
	return cost;
}

void Wallnut::setCost(int c = 50)
{
	cost = c;
}