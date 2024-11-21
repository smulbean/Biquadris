#include "player.h"

Player::Player(Board *canvas, int score, int high, Level *Level) : canvas{canvas}, score{score}, highscore{high}, level{level}
{
    Studio s{canvas};
}

Player::~Player()
{
    delete Player;
}

int Player::getScore(){
    return score;
}
int Player::getHighScore(){
    return highscore;
}
Level *Player::getLevel(){
    return level;
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