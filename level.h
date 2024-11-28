#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "block.h"

struct Player;


class Level{
	int playerNumber;
	public:
		Level(int id); 
		virtual ~Level();
		virtual char createBlock() = 0; 
};



#endif



