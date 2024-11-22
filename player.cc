#include "player.h"
#include "block.h"
#include "level0.h"

Player::Player(Board* canvas, int score, int high, int levelnum, Level* Level) : 
canvas{canvas}, score{score}, highscore{high}, level{level}, levelnum{}
{
    Studio s{canvas};
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
    if (levelnum == 0){
        level = new levelone(); // and its level one parameters
    } else if (levelnum == 1){
        level = new leveltwo(); // and its level one parameters
    } else if (levelnum == 2){
        level = new levelthree(); // and its level one parameters
    } else if (levelnum == 3){
        level = new levelfour(); // and its level one parameters
    } else {
        return level;
    }

}
Level *Player::Leveldown(){
    // level down
    if (levelnum == 2){
        level = new levelone(); // and its level one parameters
    } else if (levelnum == 3){
        level = new leveltwo(); // and its level one parameters
    } else if (levelnum == 4){
        level = new levelthree(); // and its level one parameters
    } else if (levelnum == 1){
        level = new Levelzero(); // and its level one parameters
    } else {
        return level;
    }
}
void Player::force(){
    // force
}

Block* Player::curBlock(){
    return blocks[blocks.size() - 1];
}

void Player::setcur(char c){
    Block *cur;
    if (c == 'I'){
        cur = new IBlock(); // fix this later
    }
    else if (c == 'J'){
        cur = new JBlock(); // fix this later
    }
    else if (c == 'L'){
        cur = new LBlock(); // fix this later
    }
    else if (c == 'O'){
        cur = new OBlock(); // fix this later
    }
    else if (c == 'S'){
        cur = new SBlock(); // fix this later
    }
    else if (c == 'Z'){
        cur = new ZBlock(); // fix this later
    }
    else{
        cur = new TBlock(); // fix this later
    }
    blocks.emplace_back(cur);
}


Studio* Player::getcanvas(){
    return canva;
}

void Player::reset(){
    for (auto it = blocks.begin(); it != blocks.end(); ++it) {
        observers.erase(it);
    }
    int score = 0;
    int levelnum = 0;
    level = new Levelzero();
}

