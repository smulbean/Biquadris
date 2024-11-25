#include "observer.h"
#include "subject.h"
#include "studio.h"
#include "graphic.h"
#include <iostream>
#include "window.h"
using namespace std;

int Graphic::full1()
{
    for (int i = 0; i < rows; i++)
    {
        int count = 0;
        for (int j = 0; j < cols; j++)
        {
            if (subject->getStatep1(j, i) != ' ')
            {
                count++;
            }
        }
        if (count == cols)
        {
            return i;
        }
    }
    return -1;
}

int Graphic::full2()
{
    for (int i = 0; i < rows; i++)
    {
        int count = 0;
        for (int j = cols + spacing; j < 2 * cols + spacing; ++j)
        {
            if (subject->getStatep2(j - (cols + spacing), i) != ' ')
            {
                count++;
            }
        }
        if (count == cols)
        {
            return i;
        }
    }
    return -1;
}

Graphic::Graphic(int t, int b, int l, int r, Studio *subject) : t{t}, b{b}, l{l}, r{r}, subject{subject}
{
}

void Graphic::notify()
{
    if (full1() != -1)
    {
        subject->getp1()->setCor(full1());
    }
    if (full2() != -1)
    {
        subject->getp2()->setCor(full1());
    }
    int scaling = 50; // can't be zero
    int cols = scaling * (b - t + 1);
    int rows = scaling * (r - l + 1);
    Xwindow *w = new Xwindow(cols, rows);
    for (int i = 0; i < rows; i = i + scaling)
    {
        for (int j = 0; j < cols; j = j + scaling)
        {
            char ch = subject->getState(l + j / scaling, t + i / scaling);
            if (ch >= 'a' && ch <= 'z')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Red);
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Green);
            }
            else if (ch >= '0' && ch <= '9')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Blue);
            }
            else if (ch == ' ')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::White);
            }
            else
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Black);
            }
        }
    }
}

Graphic::~Graphic()
{
    subject->detach(this);
}
