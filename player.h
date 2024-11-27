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
    std::shared_ptr<Block> picture;
    std::shared_ptr<Board> canvas;
    int score;
    int highscore;
    int levelnum;
    std::shared_ptr<Level> level; 
    int player;
    // Studio *canva;
    vector<std::shared_ptr<Block>> blocks; // wendy
    string file;
    bool rand;

public:
    Player(std::shared_ptr<Board> canvas, int score = 0, int highscore = 0, int levelnum = 0, int player = 0, std::shared_ptr<Level> level = nullptr, string file = "", bool rand = true);
    // need a copy constructor
    ~Player() = default;
    int getScore();
    void updateScore(int inc);
    void updateHigh(int high);
    int getHighScore();
    int getLevel();
    void Levelup();
    void Leveldown();
    void force();
    void MoreScore(int row);
    // Block *curBlock(); // Level->func() => block
    void setcur(char c);
    std::shared_ptr<Block> getpic();
    std::shared_ptr<Board> getboard();
    void restart();
    // void store(Block *cur);
    char next();
    void settrue();
    void setfalse();

    //Wendy your function
    void setCor(int row);
};

#endif
