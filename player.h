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
    Block *picture;
    Board *canvas;
    int score;
    int highscore;
    int levelnum;
    Level *level; 
    // Studio *canva;
    // vector<Block *> blocks;

public:
    Player(Board *canvas, int score = 0, int highscore = 0, int levelnum = 0, Level *level = nullptr);
    // need a copy constructor
    ~Player();
    int getScore();
    int getHighScore();
    int getLevel();
    Level *Levelup();
    Level *Leveldown();
    void force();
    // Block *curBlock(); // Level->func() => block
    void setcur(char c);
    Block *getpic();
    void restart();
};

#endif
