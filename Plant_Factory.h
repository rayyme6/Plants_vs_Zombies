#pragma once
#include "Plant.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Repeater.h"
#include "Wallnut.h"
#include "SnowPea.h"
#include "CherryBomb.h"

class Plant_Factory
{
private:
	static int plant_count; //Counter of how many plants have been created
public:
	Plant_Factory();
	Plant* newPeashooter(); //Make a new Peashooter
	Plant* newSunflower(); //Make a new Sunflower
	Plant* newRepeater(); //Make a new Repeater
	Plant* newWallnut(); //Make a new Wallnut
	Plant* newSnowPea(); //Make a new SnowPea
	Plant* newCherryBomb(); //Make a new CherryBomb
};

