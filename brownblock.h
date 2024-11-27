#ifndef __BROWNBLOCK_H__
#define __BROWNBLOCK_H__
#include "coor.h"
#include "block.h" // h only no .cc
#include <memory>

class BROWNBlock : public Block
{
    std::array<std::shared_ptr<Coor>, 1> coordinates; // dynamic
    bool isHeavy;

private:
    int phase;
    bool end;
    bool lost;
    bool exceed;

public:
    BROWNBlock(std::shared_ptr<Board> base);  // constructor
    ~BROWNBlock() = default; // destructor
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
};

#endif
