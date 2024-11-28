#include "level1.h"
#include <random>

extern bool isSeed;
extern int seed;

LevelOne::LevelOne(int id) : Level{id} {}

char LevelOne::createBlock() {
    int blockID;
    if (isSeed) {
        srand(seed);
        blockID = (rand() % 12) + 1;
    } else {
        // for true, chaotic randomness
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1, 12);
        blockID = distribution(generator);
    }

    if (blockID == 1) {
        return 'S';
    } else if (blockID == 2) {
        return 'Z';
    } else if (blockID == 3 || blockID == 4) {
        return 'L';
    } else if (blockID == 5 || blockID == 6) {
        return 'T';
    } else if (blockID == 7 || blockID == 8) {
        return 'I';
    } else if (blockID == 9 || blockID == 10) {
        return 'J';
    } else {
        return 'O';
    }
}
