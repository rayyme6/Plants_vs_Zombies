#include "SnowPea.h"

SnowPea::SnowPea()
{
	if (!texture.loadFromFile("Images/snowpea_sprite.png"))
	{
		std::cerr << "Error in loading peashooter file. Terminating...\n";
		// You might want to add additional error handling here, like returning or throwing an exception.
		// For now, let's just return without setting the texture.
		return;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 572, 439));
}
//
//void SnowPea::setImage()
//{
//	//set sprite
//}

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