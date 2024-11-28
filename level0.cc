#include "level0.h"

extern std::string file1string;
extern std::string file2string;

LevelZero::LevelZero(int id) : Level{id}, sequenceIdx{0} {
    std::ifstream readSeq{id == 1 ? file1string : file2string};

    std::string sequenceContent;

    while (readSeq >> sequenceContent) {
        std::string command = sequenceContent; 
        playerSequence.emplace_back(command); 
    }
}


char LevelZero::createBlock() {
    char blockID = playerSequence[sequenceIdx][0];
    if (sequenceIdx == playerSequence.size() - 1) {
        sequenceIdx = 0;
    } else {
        sequenceIdx++;
    }
    return blockID;
}

