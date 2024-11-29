#ifndef __BROWNBLOCK_H__
#define __BROWNBLOCK_H__
#include "coor.h"
#include "block.h" 
#include <memory>

class BROWNBlock : public Block
{
    std::array<std::shared_ptr<Coor>, 1> coordinates; 
    bool isHeavy;
    int phase;
    bool end;
    bool lost;
    int arrX;
    int arrY;
    bool exceed;
    void storeold();

public:
    BROWNBlock(std::shared_ptr<Board> base);  
    ~BROWNBlock() = default; 
    int getX(int num) override;
    int getY(int num) override;
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
    bool exceeded() override;
    int blockdone() override;
};

#endif

