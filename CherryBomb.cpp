#include "CherryBomb.h"

CherryBomb::CherryBomb()
{
	if (!texture.loadFromFile("Images/cherrybomb_sprite.png"))
	{
		std::cerr << "Error in loading peashooter file. Terminating...\n";
		// You might want to add additional error handling here, like returning or throwing an exception.
		// For now, let's just return without setting the texture.
		return;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 572, 439));
}

void CherryBomb::setImage()
{
}

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