#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "coor.h"
#include "block.h" // h only no .cc

class TBlock : public Block
{
    Coor *coordinates[4]; // dynamic
    bool isHeavy;

private:
    int phase;
    bool end;
    bool lost;

public:
    TBlock(Board* base);  // constructor
    ~TBlock(); // destructor
    void rotateCC() override;
    void rotateC() override;
    void down() override;
    void left() override;
    void right() override;
    char charAt(int row, int col) override;
    void drop() override;
    bool done() override;
    void clear(int row) override;
    bool lose() override;
};

#endif
