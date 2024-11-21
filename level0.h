#ifndef __LEVELZERO_H__
#define __LEVELZERO_H__
// this is the abstract class for level
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "level.h"

struct Player;


class Levelzero : public Level{
	public:
		Levelzero(); // constructor
		BlockDecorator *createBlock() override; // create blocks for level 0
};



#endif



