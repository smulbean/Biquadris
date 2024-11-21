#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "Board.h"
#include "Level.h"
#include "Subject.h"
#include "studio"



class Player
{
private:
    Board* canvas;
    int score;
    int highscore;
    Level* level;
    Studio* canvas;
public:
    Player(Board* canvas, int score = 0, int highscore = 0, Level* level = new Level0());
    ~Player();
    int getScore();
    int getHighScore();
    Level* getLevel();
    Level* Levelup();
    Level* Leveldown();
    void force();
};



#endif

