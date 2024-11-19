#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "Board.h"



class Player
{
private:
    Board* canvas;
public:
    Player(Board* canvas);
    ~Player();
};



#endif

