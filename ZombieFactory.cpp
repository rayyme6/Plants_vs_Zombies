#include "ZombieFactory.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Initialize the static zombie_count variable
int ZombieFactory::zombie_count = 0;

// Factory methods implementation
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

// Retrieve the total count of created zombies
int ZombieFactory::getZombieCount() {
    return zombie_count;
}

// Busy-wait sleep function
//void sleepMs(int milliseconds) {
//    sf::Clock clock;
//    while (clock.getElapsedTime().asMilliseconds() < milliseconds) {
//        // Busy-wait loop using SFML's clock
//    }
//}

// Generate zombies with a fixed interval between creations
//void ZombieFactory::generateRandomZombies(int maxZombies) {
//   // std::srand(static_cast<unsigned>(std::time(0)));
//
//    for (int i = 0; i < maxZombies; ++i) {
//        // Randomly select a type of zombie to create (1 to 5 inclusive)
//        int zombieType = 1 + (rand() % 5);
//        Zombie* newZombie = nullptr;
//
//        switch (zombieType) {
//        case 1:
//            newZombie = newSimpleZombie();
//            std::cout << "Created a SimpleZombie.\n";
//            break;
//        case 2:
//            newZombie = newFootballZombie();
//            std::cout << "Created a FootballZombie.\n";
//            break;
//        case 3:
//            newZombie = newFlyingZombie();
//            std::cout << "Created a FlyingZombie.\n";
//            break;
//        case 4:
//            newZombie = newDancingZombie();
//            std::cout << "Created a DancingZombie.\n";
//            break;
//        case 5:
//            newZombie = newDolphinRiderZombie();
//            std::cout << "Created a DolphinRiderZombie.\n";
//            break;
//        default:
//            std::cerr << "Unknown zombie type.\n";
//        }
//
//        // Sleep for the fixed interval using busy-wait
//      //  sleepMs(intervalMs);
//    }
//}