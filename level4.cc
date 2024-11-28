#include "level4.h"
#include <random>

extern bool isSeed;
extern int seed;

LevelFour::LevelFour(int id, bool random, std::string file) : Level{id}, isRandom{random}, randomFile{file}, sequenceIdx{0} {
    if (random) {
        std::ifstream readFile{file};
        std::string fileContent;
        while (readFile >> fileContent) {
            std::string command = fileContent;
            playerSequence.emplace_back(command);
        }
    } else {
        playerSequence.clear();
    }
}

char LevelFour::createBlock() {
    if (isRandom) {
        char blockID = playerSequence[sequenceIdx][0];
        if (sequenceIdx == playerSequence.size() - 1) {
        sequenceIdx = 0;
        } else {
        sequenceIdx++;
        }
        return blockID;
    } else {
        int blockID;
        if (isSeed) {
            srand(seed);
            blockID = (rand() % 9) + 1;
        } else {
            std::random_device rd;
            std::mt19937 generator(rd());
            std::uniform_int_distribution<int> distribution(1, 9);
            blockID = distribution(generator);
        }

        if (blockID == 1 || blockID == 2) {
            return 'S';
        } else if (blockID == 3 || blockID == 4) {
            return 'Z';
        } else if (blockID == 5) {
            return 'I';
        } else if (blockID == 6) {
            return 'J';
        } else if (blockID == 7) {
            return 'L';
        } else if (blockID == 8) {
            return 'O';
        } else {
            return 'T';
        }
    }
}



