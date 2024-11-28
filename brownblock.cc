#include "coor.h"
#include "block.h"
#include "brownblock.h"
#include "board.h"
#include <iostream>
#include <memory>

BROWNBlock::BROWNBlock(std::shared_ptr<Board> base) : Block{base}
{
    if (base->charAt(5, 2) == ' ')
    {
        phase = 1;
        end = false;
        coordinates[0] = std::make_shared<Coor>(5, 2);
        return;
    }
    else
    {
        lost = true;
        coordinates[0] = std::make_shared<Coor>(-1, -1);
    }
}

void BROWNBlock::rotateCC()
{
    return;
}

void BROWNBlock::rotateC()
{
    return;
}

void BROWNBlock::down()
{
    if (end)
    {
        return;
    }

    if (coordinates[0]->y == 17)
    {
        end = true;
        return;
    }

    if ((base->charAt(coordinates[0]->x, coordinates[0]->y + 1) == ' '))
    {
        coordinates[0]->y++;
        return;
    }
    end = true;
    return;
}

void BROWNBlock::left()
{
    return;
}

void BROWNBlock::right()
{
    return;
}

char BROWNBlock::charAt(int col, int row)
{
    if ((row == coordinates[0]->y) && (col == coordinates[0]->x))
    {
        return '*';
    }

    return base->charAt(col, row);
}

void BROWNBlock::drop()
{
    while (!end)
    {
        down();
    }
    end = true;
    return;
}

bool BROWNBlock::done()
{
    return end;
}

void BROWNBlock::clear(int row)
{
    if (this->coordinates[0]->y == row)
    {
        this->coordinates[0]->x = -1;
        this->coordinates[0]->y = -1;
    }
    else if (this->coordinates[0]->y < row)
    {
        this->coordinates[0]->y++;
    }
    return;
}

bool BROWNBlock::lose()
{
    return lost;
}

bool BROWNBlock::exceeded()
{
    if (this->coordinates[0]->y < 2 && this->coordinates[0]->y > -1)
    {
        return true;
    }
    return false;
}

int BROWNBlock::blockdone()
{
    if (this->coordinates[0]->y != -1 || this->coordinates[0]->x != -1)
    {
        return 0;
    }
    return 1;
}

