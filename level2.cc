#include "level2.h"
#include <random>

LevelTwo::LevelTwo(int id) : Level(id) {}

LevelTwo::~LevelTwo() {}

char LevelTwo::createBlock() {
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(1,7);
    int blockID = distribution(generator);

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

int LevelTwo::getLevel() {
    return 1;
}
