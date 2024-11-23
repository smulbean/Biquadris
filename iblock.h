#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "coor.h"
#include "block.h" // h only no .cc

class IBlock : public Block
{
    std::vector<Coor *> coordinates;
    bool isHeavy;

private:
    int phase;

public:
    IBlock(Board* base);  // constructor
    ~IBlock(); // destructor
    void rotateCC() override;
    void rotateC() override;
    void down() override;
    void left() override;
    void right() override;
    char charAt(int row, int col) override;
    void drop() override;
};

#endif
