#pragma once
#include "Zombie.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"


class ZombieFactory {
private:
    static int zombie_count;
public:
    ZombieFactory();
    static Zombie* newSimpleZombie();
    static Zombie* newFootballZombie();
    static Zombie* newFlyingZombie();
    static Zombie* newDancingZombie();
    static Zombie* newDolphinRiderZombie();
};

