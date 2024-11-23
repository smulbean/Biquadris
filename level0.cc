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

Block* LevelZero::createBlock() {
    std::string blockID = playerSequence[sequenceIdx]; // blockID gives the actual block
    Block *createdBlock = nullptr; // must initialize outside of else statement

    if (blockID == "I") {
        createdBlock = new IBlock();
    } else if (blockID == "J") {
        createdBlock = new JBlock();
    } else if (blockID == "L") {
        createdBlock = new LBlock();
    } else if (blockID == "O") {
        createdBlock = new OBlock();
    } else if (blockID == "S") {
        createdBlock = new SBlock();
    } else if (blockID == "Z") {
        createdBlock = new ZBlock();
    } else if (blockID == "T") {
        createdBlock = new TBlock();
    }

    if (sequenceIdx == playerSequence.size() - 1) { 
        sequenceIdx = 0; // if end of sequence, go back to front
    } else {
        sequenceIdx++;
    }

    return createdBlock;
}
