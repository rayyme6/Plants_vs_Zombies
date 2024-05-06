#include "Plant.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Time.h"
#include <ctime>
using namespace std;

Plant::Plant()
{
	x_position = 0;
	y_position = 0;
	dx = 0;
	reprinting = false;
	health = 0;
	damage = 0;
	attack_zombie = false;
	isAvailable = true;
	peaX_position = 0;
	cost = 0;
}

int Plant::getx_position()
{
	return x_position;
}

int Plant::gety_position()
{
	return y_position;
}

bool Plant::getreprinting()
{
	return reprinting;
}

bool Plant::getattack_zombie()
{
	return attack_zombie;
}

bool Plant::getisAvailable()
{
	return isAvailable;
}

int Plant::getpeaX_position()
{
	return peaX_position;
}

void Plant::setx_position(int x)
{
	x_position = x;
}

void Plant::sety_position(int y)
{
	y_position = y;
}

void Plant::setreprinting(bool r)
{
	reprinting = r;
}

void Plant::setattack_zombie(bool az)
{
	attack_zombie = az;
}

void Plant::setisAvailable(bool iA)
{
	isAvailable = iA;
}

void Plant::setpeaX_position(int pX)
{
	peaX_position = pX;
}

sf::Sprite& Plant::getImage()
{
	return sprite;
}

void Plant::deadPlant()
{
	isAvailable = false;
}

bool Plant::isOnGrid()
{
	return isAvailable;
}

void Plant::spawn(int x, int y)
{
	// Calculate the position of the sprite so that its center is at (x, y)
	sprite.setPosition(x - sprite.getGlobalBounds().width / 2,
		y - sprite.getGlobalBounds().height / 2);
}