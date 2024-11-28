#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "coor.h"
#include <memory>
#include "block.h" 

class SBlock : public Block
{
    std::array<std::shared_ptr<Coor>, 4> coordinates; 
    bool isHeavy;

private:
    int phase;
    bool end;
    bool lost;
    bool exceed;
public:
    SBlock(std::shared_ptr<Board> base);  
    ~SBlock() = default; 
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

