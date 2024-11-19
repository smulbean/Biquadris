#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "board.h"
//abstract class for block

class BlockDecorator : public Board {
protected:
    Board* base;
public:
    BlockDecorator(Board* base);
    virtual ~BlockDecorator();
};

#endif