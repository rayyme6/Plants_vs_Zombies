#include "Sunflower.h"

Sunflower::Sunflower()
{
	cooldown = Time();
}

void Sunflower::generateSun()
{
	//Can't figure this out right now
}

void Sunflower::setImage()
{
	//Will set later
}

//void Sunflower::drawPlant(sf::RenderWindow& window)
//{
//	//window.draw(peashooterSprite);
//}

void Sunflower::peaShootpoint()
{
	//It shoots nothing
}

void Sunflower::setDx(double d)
{
	//no bullet
}

void Sunflower::updatePea(sf::RenderWindow& window, double time)
{
	//no bullet
}

void Sunflower::setHealth(int h = 100)
{
	health = h;
}

void Sunflower::setDamage(int d = 0)
{
	damage = d;
}

int Sunflower::getHealth()
{
	return health;
}

int Sunflower::getDamage()
{
	return damage;
}

bool Sunflower::needToAttack(bool a)
{
	//it does not attack
	attack_zombie = a;
	return attack_zombie;
}

int Sunflower::getCost()
{
	return cost;
}

void Sunflower::setCost(int c = 100)
{
	cost = c;
}