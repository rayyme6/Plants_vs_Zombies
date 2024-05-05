#include "Zombie.h"
// Implementations for some methods
Zombie::Zombie() : x_position(0), y_position(0), speed(1), health(100), damage(10), isMoving(true) {}

int Zombie::getXPosition() const
{
	return x_position;
}
int Zombie::getYPosition() const
{
	return y_position;
}
int Zombie::getHealth() const
{
	return health;
}
int Zombie::getDamage() const
{
	return damage;
}
bool Zombie::getIsMoving() const
{
	return isMoving;
}

void Zombie::setXPosition(int x)
{
	x_position = x;
}
void Zombie::setYPosition(int y)
{
	y_position = y;
}
