#pragma once
#include "Zombie.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"
#include <ctime>

class ZombieFactory {
private:
    static int zombie_count;

public:
    // Creation methods for each type of zombie
    static Zombie* newSimpleZombie();
    static Zombie* newFootballZombie();
    static Zombie* newFlyingZombie();
    static Zombie* newDancingZombie();

    static int getZombieCount();

    // Method to randomly generate zombies at random intervals
    //static void generateRandomZombies(int maxZombies);
};

