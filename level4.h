#ifndef __LEVELFOUR_H__
#define __LEVELFOURH__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "level.h"
#include "block.h"

struct Player;


class LevelFour : public Level{
    bool isRandom;
    std::string randomFile;
    std::vector<std::string> playerSequence;
	size_t sequenceIdx;

	public:
		LevelFour(int id, bool random, std::string file); 
		~LevelFour() = default;
		char createBlock() override; 
};

#endif

