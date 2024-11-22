#include "studio.h"
#include "board.h"

void Studio::reset()
{
    p1->reset();
    p2->reset();
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
    delete thePicture;
}
