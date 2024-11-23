#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "board.h"
//abstract class for block

class Block : public Board {
protected:
    Board* base;
public:
    Block(Board* base);
    virtual ~Block();
    
    void rotateCC();
    void drop();
    void down();
    void left();
    void right();
    char charAt();
};

#endif