#include "ZombieFactory.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Initialize the static zombie_count variable
int ZombieFactory::zombie_count = 0;

// Creation methods
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

// Get the total count of created zombies
int ZombieFactory::getZombieCount() {
    return zombie_count;
}

// Busy-wait sleep function
void sleepMs(int milliseconds) {
    clock_t start = clock();
    while (static_cast<int>((clock() - start) * 1000 / CLOCKS_PER_SEC) < milliseconds) {
        // Busy-wait loop
    }
}

// Generate zombies randomly using rand()
void ZombieFactory::generateRandomZombies(int maxZombies, int minIntervalMs, int maxIntervalMs) {
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int i = 0; i < maxZombies; ++i) {
        // Generate a random delay interval in milliseconds between minIntervalMs and maxIntervalMs
        int interval = minIntervalMs + (std::rand() % (maxIntervalMs - minIntervalMs + 1));

        // Randomly select a type of zombie to create (1 to 5 inclusive)
        int zombieType = 1 + (std::rand() % 5);
        Zombie* newZombie = nullptr;

        switch (zombieType) {
        case 1:
            newZombie = newSimpleZombie();
            std::cout << "Created a SimpleZombie.\n";
            break;
        case 2:
            newZombie = newFootballZombie();
            std::cout << "Created a FootballZombie.\n";
            break;
        case 3:
            newZombie = newFlyingZombie();
            std::cout << "Created a FlyingZombie.\n";
            break;
        case 4:
            newZombie = newDancingZombie();
            std::cout << "Created a DancingZombie.\n";
            break;
        default:
            std::cerr << "Unknown zombie type.\n";
        }

        // Sleep for the random interval using busy-wait
        sleepMs(interval);
    }
}