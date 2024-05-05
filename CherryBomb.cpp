#include "CherryBomb.h"

void CherryBomb::setImage()
{
	//will set sprite later
}

//void CherryBomb::drawPlant(sf::RenderWindow& window)
//{
//	//window.draw(peashooterSprite);
//}

void CherryBomb::peaShootpoint()
{
	//does not shoot anything
}

void CherryBomb::setDx(double d)
{
	//does not shoot
}

void CherryBomb::updatePea(sf::RenderWindow& window, double time)
{
	//does not shoot
}

void CherryBomb::setHealth(int h = 200)
{
	health = h;
}

void CherryBomb::setDamage(int d = 0)
{
	damage = d;
}

int CherryBomb::getHealth()
{
	return health;
}

int CherryBomb::getDamage()
{
	return damage;
}

bool CherryBomb::needToAttack(bool a)
{
	/*if (something)
	{
		attack_zombie = true;
	}
	return attack_zombie;*/
	attack_zombie = a;
	return attack_zombie;
}

int CherryBomb::getCost()
{
	return cost;
}

void CherryBomb::setCost(int c = 50)
{
	cost = c;
}