#include <iostream>
#include "studio.h"
#include "board.h"

void Studio::reset()
{
    p1->restart();
    p2->restart();
}

char Studio::getStatep1(int row, int col) const
{
    return p1->getboard()->charAt(row, col);
}

char Studio::getStatep2(int row, int col) const
{
    return p2->getboard()->charAt(row, col);
}

std::shared_ptr<Player> Studio::getp1() 
{
    return p1;
}

std::shared_ptr<Player> Studio::getp2() 
{
    return p2;
}

