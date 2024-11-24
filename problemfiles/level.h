#ifndef __LEVEL_H__
#define __LEVEL_H__
// this is the abstract class for level
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "block.h"

class Player;


class Level{
	int playerNumber;
	public:
		Level(int id); // constructor
		virtual ~Level();
		virtual char createBlock() = 0; // factory method
};



#endif



