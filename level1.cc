#include "level1.h"
#include <random>

LevelOne::LevelOne(int id) : Level{id} {}

LevelOne::~LevelOne() {}

char LevelOne::createBlock() {
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(1,12);
    int blockID = distribution(generator);

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

int LevelOne::getLevel() {
    return 0;
}
