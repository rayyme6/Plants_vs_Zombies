#include "Peashooter.h"

Peashooter::Peashooter()
{
	if (!texture.loadFromFile("Images/peashooter_sprite.png"))
	{
		std::cerr << "Error in loading peashooter file. Terminating...\n";
		// You might want to add additional error handling here, like returning or throwing an exception.
		// For now, let's just return without setting the texture.
		return;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
}

void Peashooter::setImage()
{
}

//void Peashooter::setImage()
//{
//	if (!texture.loadFromFile("Images/peashooter_sprite.png"))
//	{
//		std::cerr << "Error in loading peashooter file. Terminating...\n";
//		// You might want to add additional error handling here, like returning or throwing an exception.
//		// For now, let's just return without setting the texture.
//		return;
//	}
//	sprite.setTexture(texture);
//	sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
//}

void Peashooter::drawPeashooter(sf::RenderWindow& window)
{
		window.draw(sprite);
}

void Peashooter::spawnPeashooter(int x, int y)
{
	// Calculate the position of the sprite so that its center is at (x, y)
	sprite.setPosition(x - sprite.getGlobalBounds().width / 2,
		y - sprite.getGlobalBounds().height / 2);
}

void Peashooter::peaShootpoint()
{
	//whereever the object will be placed
}

void Peashooter::setDx(double d)
{
	dx = d;
}

void Peashooter::updatePea(sf::RenderWindow& window, double time)
{
	peaX_position += dx * time;

	//render the sprite of bullet...
}

void Peashooter::setHealth(int h = 150)
{
	health = h;
}

void Peashooter::setDamage(int d = 20)
{
	damage = d;
}

int Peashooter::getHealth()
{
	return health;
}

int Peashooter::getDamage()
{
	return damage;
}

bool Peashooter::needToAttack(bool a)
{
	/*if (something)
	{
		attack_zombie = true;
	}
	return attack_zombie;*/
	attack_zombie = a;
	return attack_zombie;
}

int Peashooter::getCost()
{
	return cost;
}

void Peashooter::setCost(int c = 100)
{
	cost = c;
}