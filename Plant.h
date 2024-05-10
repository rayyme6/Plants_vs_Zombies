#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Time.h"
#include "Pea.h"
#include <ctime>
using namespace std;
class Plant
{
protected:
	int x_position; //x position of Plant on grid
	int y_position; //y position of Plant on grid
	double dx; //Speed at which bullet will fly
	bool reprinting; //Check if being redrawn
	int health; //Health of the Plant
	int damage; //Damage inflicted by the Plant
	bool attack_zombie; //If there is a zombie in the same lane then attack it
	bool isAvailable; //Check if plant is available
	int peaX_position; //Track the position of the Pea
	int cost; //Cost of each of Plant
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock shootingtimer;
	//Clock cooldown; //Cooldown time of Plant
public:
	Plant();
	
	//getters
	int getx_position();
	int gety_position();
	bool getreprinting();
	bool getattack_zombie();
	bool getisAvailable();
	int getpeaX_position();

	//setters
	void setx_position(int x);
	void sety_position(int y);
	void setreprinting(bool r);
	void setattack_zombie(bool az);
	void setisAvailable(bool iA);
	void setpeaX_position(int pX);
	sf::Sprite& getImage() ;
	virtual void setImage() = 0;
	virtual void peaShootpoint() = 0;
	virtual void setDx(double d) = 0;
	virtual void updatePea(sf::RenderWindow& window, double time) = 0;

	virtual void setHealth(int h) = 0;
	virtual void setDamage(int d) = 0;
	virtual int getHealth() = 0;
	virtual int getDamage() = 0;
	virtual bool needToAttack(bool a) = 0;
	virtual int getCost() = 0;
	virtual void setCost(int c) = 0;
	//virtual bool canShootPea() = 0;

	//// New member function to shoot a pea
	//virtual  Pea shootPea() = 0;
	//virtual void drawPlant(sf::RenderWindow& window) = 0;
	
	void deadPlant();
	bool isOnGrid();
	void spawn(int x, int y);


};

