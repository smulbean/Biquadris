#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "coor.h"
#include "block.h" // h only no .cc

class IBlock : public Block{
    std::vector<Coor> Coor;
    bool isHeavy;

private:
    int phase;

public:
    IBlock(); //constructor
    ~IBlock(); //destructor
    void rotateCC() override;
    void rotateC() override;
    void down() override;
    void left() override;
    void right() override;
    char charAt(int row, int col) override;
    void drop() override;
}


#endif


