#include "Plant_Factory.h"
#include "Plant.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Repeater.h"
#include "Wallnut.h"
#include "SnowPea.h"
#include "CherryBomb.h"

//Set the plants created to zero
int Plant_Factory::plant_count = 0;

Plant_Factory::Plant_Factory()
{
}

//Make a new Peashooter and increase the plant count
Plant* Plant_Factory::newPeashooter()
{
	plant_count++;
	return new Peashooter();
	
}

//Make a new Sunflower and increase the plant count
Plant* Plant_Factory::newSunflower()
{
	plant_count++;
	return new Sunflower();
	
}

//Make a new Repeater and increase the plant count
Plant* Plant_Factory::newRepeater()
{
	plant_count++;
	return new Repeater();
	
}

//Make a new Wallnut and increase the plant count
Plant* Plant_Factory::newWallnut()
{
	plant_count++;
	return new Wallnut();
	
}

//Make a new SnowPea and increase the plant count
Plant* Plant_Factory::newSnowPea()
{
	plant_count++;
	return new SnowPea();
	
}

//Make a new CherryBomb and increase the plant count
Plant* Plant_Factory::newCherryBomb()
{
	plant_count++;
	return new CherryBomb();
	
}