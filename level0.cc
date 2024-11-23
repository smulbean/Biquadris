#include "level0.h"

std::string file1Sequence = "sequence1.txt";
std::string file2Sequence = "sequence2.txt";

LevelZero::LevelZero(int id) : Level{id}, sequenceIdx{0} {
    std::ifstream readSeq{id == 1 ? file1Sequence : file2Sequence};

    std::string sequenceContent;

    while (readSeq >> sequenceContent) {
        std::string command = sequenceContent; // make it separately to construct
        playerSequence.emplace_back(command); // constructs, places at back
    }
}

LevelZero::~LevelZero() {}

char LevelZero::createBlock() {
    char blockID = playerSequence[sequenceIdx][0];
    if (sequenceIdx == playerSequence.size() - 1) {
        sequenceIdx = 0;
    } else {
        sequenceIdx++;
    }
    return blockID;
}
