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
    w = new Xwindow(col*40, row*40);
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
    int scale = 20;
    for (int row = t; row <= b; ++row)
    {
        for (int col = l; col <= r; ++col)
        {
            char ch = subject->getStatep1(col, row);
            // char ch = subject->getStatep1(col, row);
            if (ch == 'J')
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Red);
            }
            else if (ch == 'Z')
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Green);
            }
            else if (ch == 'I')
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Blue);
            }
            if (ch == 'S')
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Red);
            }
            else if (ch == 'T')
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Blue);
            }
            else if (ch == 'O')
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Green);
            }
            else if (ch == ' ')
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::White);
            }
            else
            {
                w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Black);
            }
        }

        for (int col = l; col <= r; ++col)
        {
            char ch = subject->getStatep2(col, row);
            if (ch == 'J')
            {
                w->fillRectangle((col - l) * scale + 5*scale, (row - t) * scale, scale, scale, Xwindow::Red);
            }
            else if (ch == 'Z')
            {
                w->fillRectangle((col - l) * scale + 20*scale, (row - t) * scale, scale, scale, Xwindow::Green);
            }
            else if (ch == 'I')
            {
                w->fillRectangle((col - l) * scale + 20*scale, (row - t) * scale, scale, scale, Xwindow::Blue);
            }
            if (ch == 'S')
            {
                w->fillRectangle((col - l) * scale + 20*scale, (row - t) * scale, scale, scale, Xwindow::Red);
            }
            else if (ch == 'T')
            {
                w->fillRectangle((col - l) * scale + 20*scale, (row - t) * scale, scale, scale, Xwindow::Blue);
            }
            else if (ch == 'O')
            {
                w->fillRectangle((col - l) * scale + 20*scale, (row - t) * scale, scale, scale, Xwindow::Green);
            }
            else if (ch == ' ')
            {
                w->fillRectangle((col - l) * scale + 20*scale, (row - t) * scale, scale, scale, Xwindow::White);
            }
            else
            {
                w->fillRectangle((col - l) * scale + 20*scale, (row - t) * scale, scale, scale, Xwindow::Black);
            }
        }
    }
    
    //player one level
    w->drawString(row*spacing + spacing, row*spacing*spacing*1.4, "Level:   ");
    std::string p1level = std::to_string(subject->getp1()->getLevel());
    w->drawString(row*spacing*3, row*spacing*spacing*1.4, p1level);
    //player two level
    w->drawString(row*spacing*8, row*spacing*spacing*1.4, "Level:   ");
    std::string p2level = std::to_string(subject->getp2()->getLevel());
    w->drawString(row*spacing*10, row*spacing*spacing*1.4, p2level);

     //player one score
    w->drawString(row*spacing + spacing, row*spacing*spacing*1.45, "Score:   ");
    std::string p1score = std::to_string(subject->getp1()->getScore());
    w->drawString(row*spacing*3, row*spacing*spacing*1.45, p1score);
    //player two score
    w->drawString(row*spacing*8, row*spacing*spacing*1.45, "Score:   ");
    std::string p2score = std::to_string(subject->getp2()->getScore());
    w->drawString(row*spacing*10, row*spacing*spacing*1.45, p2score);

    //player one high score
    w->drawString(row*spacing + spacing, row*spacing*spacing*1.5, "HighScore:   ");
    std::string p1high = std::to_string(subject->getp1()->getHighScore());
    w->drawString(row*spacing*3, row*spacing*spacing*1.5, p1high);
    //player two high score
    w->drawString(row*spacing*8, row*spacing*spacing*1.5, "HighScore:   ");
    std::string p2high = std::to_string(subject->getp2()->getHighScore());
    w->drawString(row*spacing*10, row*spacing*spacing*1.5, p2high);
}

Graphic::~Graphic()
{
    subject->detach(this);
}
