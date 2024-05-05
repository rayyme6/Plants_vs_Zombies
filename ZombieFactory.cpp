#include "ZombieFactory.h"


int ZombieFactory::zombie_count = 0;

Zombie* ZombieFactory::newSimpleZombie() {
    zombie_count++;
    return new SimpleZombie();
}

Zombie* ZombieFactory::newFootballZombie() {
    zombie_count++;
    return new FootballZombie();
}

Zombie* ZombieFactory::newFlyingZombie() {
    zombie_count++;
    return new FlyingZombie();
}

Zombie* ZombieFactory::newDancingZombie() {
    zombie_count++;
    return new DancingZombie();
}

Zombie* ZombieFactory::newDolphinRiderZombie() {
    zombie_count++;
    return new DolphinRiderZombie();
}