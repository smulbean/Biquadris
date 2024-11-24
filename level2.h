#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__
// this is the abstract class for level
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "level.h"
#include "block.h"

struct Player;


class LevelTwo : public Level{
	public:
		LevelTwo(int id); // constructor
		~LevelTwo();
		char createBlock() override; // create blocks for level 2
};

#endif
