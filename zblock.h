#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "coor.h"
#include "block.h" // h only no .cc

class ZBlock : public Block
{
    Coor *coordinates[4]; // dynamic
    bool isHeavy;

private:
    int phase;
    bool end;

public:
    ZBlock(Board* base);  // constructor
    ~ZBlock(); // destructor
    void rotateCC() override;
    void rotateC() override;
    void down() override;
    void left() override;
    void right() override;
    char charAt(int row, int col) override;
    void drop() override;
    bool done() override;
};

#endif
