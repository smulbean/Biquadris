#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "board.h"
#include "level.h"
#include "subject.h"
#include "studio.h"
#include "block.h"
using namespace std;

class Player
{
private:
    Board *canvas;
    int score;
    int highscore;
    int levelnum;
    Level *level; 
    // Studio *canva;
    vector<Block *> blocks;

public:
    Player(Board *canvas, int score = 0, int highscore = 0, int levelnum = 0, Level *level);
    // need a copy constructor
    ~Player();
    int getScore();
    int getHighScore();
    int getLevel();
    Level *Levelup();
    Level *Leveldown();
    void force();
    Block *curBlock(); // Level->func() => block
    void setcur(char c);
    Board *getcanvas();
    void restart();
};

#endif
