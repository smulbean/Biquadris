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
    return p1->getcanvas()->charAt(row, col);
}

char Studio::getStatep2(int row, int col) const
{
    return p2->getcanvas()->charAt(row, col);
}

Studio::~Studio()
{
    delete p1;
    delete p2;
}

Player* Studio::getp1(){
    return p1;
}

Player* Studio::getp2(){
    return p2;
}

