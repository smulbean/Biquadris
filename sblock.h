#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "coor.h"
#include "block.h" // h only no .cc

class SBlock : public Block
{
    Coor *coordinates[4]; // dynamic
    bool isHeavy;

private:
    int phase;
    bool end;

public:
    SBlock(Board* base);  // constructor
    ~SBlock(); // destructor
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
