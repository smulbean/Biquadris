#ifndef __LEVEL_H__
#define __LEVEL_H__
// this is the abstract class for level
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "block.h"

struct Player;


class Level{
	public:
		Level(); // constructor
		virtual BlockDecorator *createBlock() = 0; // factory method
};



#endif



