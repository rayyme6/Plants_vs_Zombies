#include "SnowPea.h"

void SnowPea::setImage()
{
	//set sprite
}

//void SnowPea::drawPlant(sf::RenderWindow& window)
//{
//	//window.draw(peashooterSprite);
//}

void SnowPea::peaShootpoint()
{
	//whereever the object will be placed
}

void SnowPea::setDx(double d)
{
	dx = d;
}

void SnowPea::updatePea(sf::RenderWindow& window, double time)
{
	peaX_position += dx * time;

	//render the sprite of bullet...
}

void SnowPea::setHealth(int h = 150)
{
	health = h;
}

void SnowPea::setDamage(int d = 40)
{
	damage = d;
}

int SnowPea::getHealth()
{
	return health;
}

int SnowPea::getDamage()
{
	return damage;
}

bool SnowPea::needToAttack(bool a)
{
	/*if (something)
	{
		attack_zombie = true;
	}
	return attack_zombie;*/
	attack_zombie = a;
	return attack_zombie;
}

int SnowPea::getCost()
{
	return cost;
}

void SnowPea::setCost(int c = 175)
{
	cost = c;
}