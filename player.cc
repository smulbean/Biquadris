#include "player.h"

Player::Player(Board* canvas, int score, int high, int levelnum, Level* Level) : 
canvas{canvas}, score{score}, highscore{high}, level{level}, levelnum{}
{
    Studio s{canva};
}

Player::~Player()
{
    delete this;
}

int Player::getScore(){
    return score;
}
int Player::getHighScore(){
    return highscore;
}
int Player::getLevel(){
    return levelnum;
}
Level *Player::Levelup(){
    // level up
}
Level *Player::Leveldown(){
    // level down
}
void Player::force(){
    // force
}

Block* Player::curBlock(){
    return blocks[blocks.size() - 1];
}

void Player::setcur(char c){
    if (c == 'I'){
        Block* cur = new IBlock(); // fix this later
    }
    if (c == 'J'){
        Block* cur = new JBlock(); // fix this later
    }
    if (c == 'L'){
        Block* cur = new LBlock(); // fix this later
    }
    if (c == 'O'){
        Block* cur = new OBlock(); // fix this later
    }
    if (c == 'S'){
        Block* cur = new SBlock(); // fix this later
    }
    if (c == 'Z'){
        Block* cur = new ZBlock(); // fix this later
    }
    if (c == 'T'){
        Block* cur = new TBlock(); // fix this later
    }
    blocks.emplace_back(cur);
}


Studio* Player::getcanvas(){
    return canvas;
}
