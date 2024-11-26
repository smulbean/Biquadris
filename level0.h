#ifndef __LEVELZERO_H__
#define __LEVELZERO_H__
// this is the abstract class for level
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "level.h"
#include "block.h"

struct Player;


class LevelZero : public Level{
	std::vector<std::string> playerSequence;
	size_t sequenceIdx;

	public:
		LevelZero(int id); // constructor
		~LevelZero();
		char createBlock() override; // create blocks for level 0make
};

#endif
