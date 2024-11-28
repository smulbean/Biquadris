#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "coor.h"
#include "block.h"
#include <memory>

class LBlock : public Block
{
    std::array<std::shared_ptr<Coor>, 4> coordinates; 
    bool isHeavy;

private:
    int phase;
    bool end;
    bool lost;
    bool exceed;

public:
    LBlock(std::shared_ptr<Board> base);  
    ~LBlock() = default; 
    void rotateCC() override;
    void rotateC() override;
    void down() override;
    void left() override;
    void right() override;
    char charAt(int row, int col) override;
    void drop() override;
    bool done() override;
    bool lose() override;
    void clear(int row) override;
    bool exceeded() override;
    int blockdone() override;
};

#endif

