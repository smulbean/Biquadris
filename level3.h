#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__
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
		LevelThree(int id, bool random, std::string file); // constructor
		~LevelThree();
		char createBlock() override; // create blocks for level 3
		int getLevel() override;
};

#endif
