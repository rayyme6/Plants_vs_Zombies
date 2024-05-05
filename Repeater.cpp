#include "Repeater.h"

void Repeater::setImage()
{
	//set sprite
}

//void Repeater::drawPlant(sf::RenderWindow& window)
//{
//	//window.draw(peashooterSprite);
//}

void Repeater::peaShootpoint()
{
	//whereever the object will be placed
}

void Repeater::setDx(double d)
{
	dx = d;
}

void Repeater::updatePea(sf::RenderWindow& window, double time)
{
	peaX_position += dx * time;

	//render the sprite of bullet...
}

void Repeater::setHealth(int h = 150)
{
	health = h;
}

void Repeater::setDamage(int d = 20)
{
	damage = d;
}

int Repeater::getHealth()
{
	return health;
}

int Repeater::getDamage()
{
	return damage;
}

bool Repeater::needToAttack(bool a)
{
	/*if (something)
	{
		attack_zombie = true;
	}
	return attack_zombie;*/
	attack_zombie = a;
	return attack_zombie;
}

int Repeater::getCost()
{
	return cost;
}

void Repeater::setCost(int c = 200)
{
	cost = c;
}