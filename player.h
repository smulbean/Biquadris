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
    vector<std::shared_ptr<Block>> blocks; 
    string file;
    bool rand;

public:
    Player(std::shared_ptr<Board> canvas, int score = 0, int highscore = 0, int levelnum = 0, int player = 0, std::shared_ptr<Level> level = nullptr, string file = "", bool rand = true);
    ~Player() = default;
    int getScore();
    void updateScore(int inc);
    void updateHigh(int high);
    int getHighScore();
    int getLevel();
    void Levelup();
    void Leveldown();
    void MoreScore();
    int blocknum();
    void setcur(char c);
    std::shared_ptr<Block> getpic();
    std::shared_ptr<Board> getboard();
    void restart();
    char next();
    void settrue();
    void setfalse();
    void setCor(int row);
};

#endif

