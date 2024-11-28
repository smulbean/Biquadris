#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "coor.h"
#include "block.h" 
#include <memory>

class IBlock : public Block
{
    std::array<std::shared_ptr<Coor>, 4> coordinates; 
    bool isHeavy;
    int phase;
    bool end;
    bool lost;
    bool exceed;

public:
    IBlock(std::shared_ptr<Board> base); 
    ~IBlock() = default; 
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

