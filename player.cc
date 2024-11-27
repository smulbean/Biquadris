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
#include "level3.h"
#include "level4.h"

Player::Player(std::shared_ptr<Board> canvas, int score, int high, int levelnum, int player, std::shared_ptr<Level> level, std::string file, bool rand) : 
    canvas{canvas}, score{score}, highscore{high}, levelnum{levelnum}, player{player}, level{level}, file{file}, rand{rand} {
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
void Player::Levelup() {
    if (levelnum == 0) {
        level = std::make_shared<LevelOne>(player);
        levelnum = 1;
    } else if (levelnum == 1) {
        level = std::make_shared<LevelTwo>(player);
        levelnum = 2;
    } else if (levelnum == 2) {
        level = std::make_shared<LevelThree>(player, rand, file);
        levelnum = 3;
    } else if (levelnum == 3) {
        level = std::make_shared<LevelFour>(player, rand, file);
        levelnum = 4;
    }
}
void Player::Leveldown() {
    if (levelnum == 2) {
        level = std::make_shared<LevelOne>(player);
        levelnum = 1;
    } else if (levelnum == 3) {
        level = std::make_shared<LevelTwo>(player);
        levelnum = 2;
    } else if (levelnum == 4) {
        level = std::make_shared<LevelThree>(player, rand, file);
        levelnum = 3;
    } else if (levelnum == 1) {
        level = std::make_shared<LevelZero>(player);
        levelnum = 0;
    }
}
void Player::force(){
    // force
}

// Block* Player::curBlock(){
//     return blocks[blocks.size() - 1];
// }
void Player::setcur(char c) {
    if (c == 'I') {
        picture = std::make_shared<IBlock>(canvas);  // Automatically managed
        blocks.push_back(picture);
        canvas = picture;
    }
    else if (c == 'J') {
        picture = std::make_shared<JBlock>(canvas);  // Automatically managed
        blocks.push_back(picture);
        canvas = picture;
    }
    else if (c == 'L') {
        picture = std::make_shared<LBlock>(canvas);  // Automatically managed
        blocks.push_back(picture);
        canvas = picture;
    }
    else if (c == 'O') {
        picture = std::make_shared<OBlock>(canvas);  // Automatically managed
        blocks.push_back(picture);
        canvas = picture;
    }
    else if (c == 'S') {
        picture = std::make_shared<SBlock>(canvas);  // Automatically managed
        blocks.push_back(picture);
        canvas = picture;
    }
    else if (c == 'Z') {
        picture = std::make_shared<ZBlock>(canvas);  // Automatically managed
        blocks.push_back(picture);
        canvas = picture;
    }
    else {
        picture = std::make_shared<TBlock>(canvas);  // Automatically managed
        blocks.push_back(picture);
        canvas = picture;
    }
}


std::shared_ptr<Board> Player::getboard() {
    return canvas;
}

std::shared_ptr<Block> Player::getpic() {
    return picture;
}


void Player::restart() {
    picture = nullptr; // No need to manually delete since we use shared_ptr
    score = 0;
    levelnum = 0;
    level = nullptr;
    canvas = std::make_shared<Blank>(); // Create new Blank as shared_ptr
}

// void Player::store(Block *cur){
    
// }

void Player::setCor(int row) {
    for (auto& block : blocks) {
        block->clear(row);
    }
}



char Player::next(){
    return level->createBlock();
}

void Player::settrue(){
    rand = true;
}

void Player::setfalse(){
    rand = false;
}

