#ifndef __LEVELTHREE_H__
#define __LEVELTHREE_H__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "level.h"
#include "block.h"

struct Player;


class LevelThree : public Level{
    bool isRandom;
    std::string randomFile;
    std::vector<std::string> playerSequence;
	size_t sequenceIdx;

	public:
		LevelThree(int id, bool random, std::string file); 
		~LevelThree() = default;
		char createBlock() override; 
};

#endif


