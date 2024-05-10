#include "Repeater.h"

Repeater::Repeater()
{
	if (!texture.loadFromFile("Images/repeater_sprite.png"))
	{
		std::cerr << "Error in loading peashooter file. Terminating...\n";
		// You might want to add additional error handling here, like returning or throwing an exception.
		// For now, let's just return without setting the texture.
		return;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 572, 439));
}

//void Repeater::setImage()
//{
//	//set sprite
//}

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