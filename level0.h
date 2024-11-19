#ifndef __LEVEL0_H__
#define __LEVEL0_H__
// this is the abstract class for level
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "level.h"

struct Player;


class Level0 : public Level{
	public:
		BlockDecorator *createBlock() override; // create blocks for level 0
};



#endif



