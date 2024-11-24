#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "board.h"
// abstract class for block

class Block : public Board
{
protected:
    Board *base;

public:
    Block(Board *base);
    virtual ~Block();
    virtual void rotateC() = 0;
    virtual void rotateCC() = 0;
    virtual void down() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void drop() = 0;
    virtual bool done() = 0;
};

#endif