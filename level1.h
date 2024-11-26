#ifndef __LEVELONE_H__
#define __LEVELONE_H__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "level.h"
#include "block.h"

struct Player;


class LevelOne : public Level{
	public:
		LevelOne(int id); // constructor
		~LevelOne();
		char createBlock() override; // create blocks for level 1
		int getLevel() override;
};

#endif
