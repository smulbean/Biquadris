#include "observer.h"
#include "subject.h"
#include "studio.h"
#include "graphic.h"
#include <iostream>
#include "window.h"
using namespace std;

int Graphic::full1()
{
    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = 0; j < col; j++)
        {
            if (subject->getStatep1(j, i) != ' ')
            {
                count++;
            }
        }
        if (count == col)
        {
            return i;
        }
    }
    return -1;
}

int Graphic::full2()
{
    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = col + spacing; j < 2 * col + spacing; ++j)
        {
            if (subject->getStatep2(j - (col + spacing), i) != ' ')
            {
                count++;
            }
        }
        if (count == col)
        {
            return i;
        }
    }
    return -1;
}

Graphic::Graphic(Studio *subject) : subject{subject}
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
    int scaling = 20; // can't be zero
    int rows = scaling * (b - t + 1);
    int cols = scaling * (r - l + 1);
    Xwindow *w = new Xwindow(cols, rows);
    for (int i = 0; i < rows; i = i + scaling)
    {
        for (int j = 0; j < cols; j = j + scaling)
        {
            char ch = subject->getStatep1(t + i / scaling, l + j / scaling);
            if (ch == 'J')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Red);
            }
            else if (ch == 'T')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Green);
            }
            else if (ch == 'Z')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Blue);
            }
            else if (ch == 'O')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Red);
            }
            else if (ch == 'I')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Blue);
            }
            else if (ch == 'L')
            {
                w->fillRectangle(i, j, scaling, scaling, Xwindow::Green);
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
