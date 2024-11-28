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


class LevelTwo : public Level{
	public:
		LevelTwo(int id); 
		~LevelTwo() = default;
		char createBlock() override; 
};

#endif

