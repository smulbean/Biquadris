#include "level2.h"
#include <random>

extern bool isSeed;
extern int seed;

LevelTwo::LevelTwo(int id) : Level(id) {}

char LevelTwo::createBlock() {
    int blockID;
    if (isSeed) {
        srand(seed);
        blockID = (rand() % 7) + 1;
    } else {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1, 7);
        blockID = distribution(generator);
    }

    if (blockID == 1) {
        return 'I'; 
    } else if (blockID == 2) {
        return 'J';
    } else if (blockID == 3) {
        return 'L';
    } else if (blockID == 4) {
        return 'O';
    } else if (blockID == 5) {
        return 'S';
    } else if (blockID == 6) {
        return 'Z';
    } else {
        return 'T';
    }
}


