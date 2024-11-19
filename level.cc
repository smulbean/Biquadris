#include "Level.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


Level::~Level() {}


//Return the int number for which level the player is
int Level:: GetLevel() const {
    return levnum;
}

