#include "level0.h"

std::string file1Sequence = "sequence1.txt";
std::string file2Sequence = "sequence2.txt";

LevelZero::LevelZero(int id) : Level{id}, sequenceIdx{0} {

}

LevelZero::~LevelZero() {}

char LevelZero::createBlock() {
    return ' ';
}
