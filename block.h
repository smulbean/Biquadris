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
};

#endif