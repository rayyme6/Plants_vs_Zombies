#include "Sunflower.h"

Sunflower::Sunflower() : sunSpawnInterval(5.0f) 
{
	if (!texture.loadFromFile("Images/sunflower_sprite.png"))
	{
		std::cerr << "Error in loading peashooter file. Terminating...\n";
		// You might want to add additional error handling here, like returning or throwing an exception.
		// For now, let's just return without setting the texture.
		return;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 572, 439));
}

void Sunflower::generateSun()
{
	//Can't figure this out right now
}

//void Sunflower::setImage()
//{
//	//Will set later
//}

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

//void Sunflower::update(float deltaTime) {
//	// Check if it's time to spawn a new sun
//	if (clock.getElapsedTime().asSeconds() >= sunSpawnInterval) {
//		spawnSun();
//		clock.restart();
//	}
//
//	// Update existing suns
//	for (auto& sun : suns) {
//		sun.update(deltaTime);
//	}
//}
//
//void Sunflower::draw(sf::RenderWindow& window) {
//	// Draw all active suns
//	for (auto& sun : suns) {
//		sun.draw(window);
//	}
//}
//
//void Sunflower::spawnSun() {
//	// Find an inactive sun and spawn it at a random location at the top of the screen
//	for (auto& sun : suns) {
//		if (!sun.isActive()) {
//			sun.spawn(rand() % 800, 0); // Adjust 800 to your window width
//			return;
//		}
//	}
//}