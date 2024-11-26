#include "player.h"
#include "block.h"
#include "level0.h"
#include "blank.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "tblock.h"
#include "zblock.h"
#include "oblock.h"
#include "sblock.h"
#include "level1.h"
#include "level2.h"

Player::Player(Board* canvas, int score, int high, int levelnum, int player,  Level* level) : 
canvas{canvas}, score{score}, highscore{high}, levelnum{levelnum}, player{player}, level{level} {
    // canvas = new BlankBlock(canvas); // fix this later
    // canvas = picture;
}

Player::~Player()
{
}
 
int Player::getScore(){
    return score;
}

void Player::updateScore(int inc){
    score = score + inc;
}

int Player::getHighScore(){
    return highscore;
}

void Player::updateHigh(int high){
    highscore = high;
}

int Player::getLevel(){
    return levelnum;
}
void Player::Levelup(){
    // level up
    delete level;

    if (levelnum == 0){
        level = new LevelOne(player);
        levelnum = 1; // and its level one parameters
    } else if (levelnum == 1){
        level = new LevelTwo(player);
        levelnum = 2;
    } // and its level one parameters
    // } else if (levelnum == 2){
    //     level = new levelthree(); // and its level one parameters
    // } else if (levelnum == 3){
    //     level = new levelfour(); // and its level one parameters
    // }

}
void Player::Leveldown(){
    // level down
    if (levelnum == 2){
        level = new LevelOne(player); // and its level one parameters
        levelnum = 1;
    } else if (levelnum == 3){
        level = new LevelTwo(player); // and its level one parameters
        levelnum = 2;
    // } else if (levelnum == 4){
    //     level = new levelthree(); // and its level one parameters
    } else if (levelnum == 1){
        level = new LevelZero(player); // and its level one parameters
        levelnum = 0;
    }
}
void Player::force(){
    // force
}

// Block* Player::curBlock(){
//     return blocks[blocks.size() - 1];
// }

void Player::setcur(char c){
    if (c == 'I'){
        picture = new IBlock(canvas); // fix this later
        Block *cur = picture;
        blocks.emplace_back(cur);
        canvas = picture;
    }
    else if (c == 'J'){
        picture = new JBlock(canvas); // fix this later
        Block *cur = picture;
        blocks.emplace_back(cur);
        canvas = picture;
    }
    else if (c == 'L'){
        picture = new LBlock(canvas); // fix this later
        Block *cur = picture;
        blocks.emplace_back(cur);
        canvas = picture;
    }
    else if (c == 'O'){
        picture = new OBlock(canvas); // fix this later
        Block *cur = picture;
        blocks.emplace_back(cur);
        canvas = picture;
    }
    else if (c == 'S'){
        picture = new SBlock(canvas); // fix this later
        Block *cur = picture;
        blocks.emplace_back(cur);
        canvas = picture;
    }
    else if (c == 'Z'){
        picture = new ZBlock(canvas); // fix this later
        Block *cur = picture;
        blocks.emplace_back(cur);
        canvas = picture;
    }
    else{
        picture = new TBlock(canvas); // fix this later
        Block *cur = picture;
        blocks.emplace_back(cur);
        canvas = picture;
    }

}

Board *Player::getboard(){
    return canvas;
}

Block* Player::getpic(){
    return picture;
}

void Player::restart(){
    delete picture;
    picture = nullptr;
    score = 0;
    levelnum = 0;
    level = nullptr;
    canvas = new Blank();
}

void Player::store(Block *cur){
    
}

void Player::setCor(int row){
    for (auto it = blocks.begin(); it != blocks.end(); ++it){
        (*it)->clear(row);
        // it is the block that it will be going thru
        // you can call a function in block using it.function(int row)
    }
}



char Player::next(){
    return level->createBlock();
}
