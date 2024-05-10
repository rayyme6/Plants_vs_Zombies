#include "Wallnut.h"

Wallnut::Wallnut()
{
	if (!texture.loadFromFile("Images/wallnut_sprite.png"))
	{
		std::cerr << "Error in loading peashooter file. Terminating...\n";
		// You might want to add additional error handling here, like returning or throwing an exception.
		// For now, let's just return without setting the texture.
		return;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 572, 439));
}

//void Wallnut::setImage()
//{
//	//set sprite
//}

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