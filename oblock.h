#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "coor.h"
#include "block.h" // h only no .cc
#include <memory>

class OBlock : public Block
{
    std::array<std::shared_ptr<Coor>, 4> coordinates; // dynamic
    bool isHeavy;

private:
    int phase;
    bool end;
    bool lost;
    bool exceed;
public:
    OBlock(std::shared_ptr<Board> base);  // constructor
    ~OBlock() = default; // destructor
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
    int blockdone(int row) override;
};

#endif
