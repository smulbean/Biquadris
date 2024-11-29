#include "observer.h"
#include "subject.h"
#include "studio.h"
#include "graphic.h"
#include <iostream>
#include "window.h"
#include <memory>

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

Graphic::Graphic(std::shared_ptr<Studio> subject) : subject{subject}
{
    w = new Xwindow(col * 40, row * 40);
}

void Graphic::notify()
{
    int scale = 20;
    if (subject->getp1()->getclear()){
        w->fillRectangle(0,0, col*20, row*40, Xwindow::White);
        subject->getp1()->changeclear(false);
    }
    if (subject->getp2()->getclear()){
        w->fillRectangle(col*20,0, col*20, row*40, Xwindow::White);
        subject->getp2()->changeclear(false);
    }
    for (int i = 0; i < 4; i++)
    {
        int x1 = 0;
        int y1 = 0;
        int x = subject->getp1()->getcur()->getX(i);
        int y = subject->getp1()->getcur()->getY(i);
        if (subject->getp2()->getcur() != nullptr)
        {
            x1 = subject->getp2()->getcur()->getX(i);
            y1 = subject->getp2()->getcur()->getY(i);
        }

        w->fillRectangle((x - l) * scale, (y - t) * scale, scale, scale, Xwindow::White);
        w->fillRectangle((x1 - l) * scale + 20 * scale, (y1 - t) * scale, scale, scale, Xwindow::White);
    }
    for (int row = t; row <= b; ++row)
    {
        for (int col = l; col <= r; ++col)
        {
            char ch = subject->getStatep1(col, row);
            char och = subject->getOldp1(col, row);
            if (ch != och)
            {
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
                    w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Pink);
                }
                else if (ch == 'T')
                {
                    w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Purple);
                }
                else if (ch == 'O')
                {
                    w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Yellow);
                }
                else if (ch == ' ')
                {
                    w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::White);
                }
                else if (ch == 'L')
                {
                    w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Orange);
                }
                else if (ch == '*')
                {
                    w->fillRectangle((col - l) * scale, (row - t) * scale, scale, scale, Xwindow::Brown);
                }
            }
        }

        for (int col = l; col <= r; ++col)
        {
            char ch = subject->getStatep2(col, row);
            char och = subject->getOldp2(col, row);
            if (ch != och || (ch != ' ' && och != ' '))
            {
                if (ch == 'J')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Red);
                }
                else if (ch == 'Z')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Green);
                }
                else if (ch == 'I')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Blue);
                }
                if (ch == 'S')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Pink);
                }
                else if (ch == 'T')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Purple);
                }
                else if (ch == 'O')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Yellow);
                }
                else if (ch == ' ')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::White);
                }
                else if (ch == 'L')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Orange);
                }
                else if (ch == '*')
                {
                    w->fillRectangle((col - l) * scale + 20 * scale, (row - t) * scale, scale, scale, Xwindow::Brown);
                }
            }
        }
    }
    w->fillRectangle(0, row * spacing * spacing * 1.35, 800, 800, Xwindow::White);

    // player one level
    w->drawString(row * spacing + spacing, row * spacing * spacing * 1.4, "Level:   ");
    std::string p1level = std::to_string(subject->getp1()->getLevel());
    w->drawString(row * spacing * 3, row * spacing * spacing * 1.4, p1level);
    // player two level
    w->drawString(row * spacing * 8, row * spacing * spacing * 1.4, "Level:   ");
    std::string p2level = std::to_string(subject->getp2()->getLevel());
    w->drawString(row * spacing * 10, row * spacing * spacing * 1.4, p2level);

    // player one score
    w->drawString(row * spacing + spacing, row * spacing * spacing * 1.45, "Score:   ");
    std::string p1score = std::to_string(subject->getp1()->getScore());
    w->drawString(row * spacing * 3, row * spacing * spacing * 1.45, p1score);
    // player two score
    w->drawString(row * spacing * 8, row * spacing * spacing * 1.45, "Score:   ");
    std::string p2score = std::to_string(subject->getp2()->getScore());
    w->drawString(row * spacing * 10, row * spacing * spacing * 1.45, p2score);

    // player one high score
    w->drawString(row * spacing + spacing, row * spacing * spacing * 1.5, "HighScore:   ");
    std::string p1high = std::to_string(subject->getp1()->getHighScore());
    w->drawString(row * spacing * 3, row * spacing * spacing * 1.5, p1high);
    // player two high score
    w->drawString(row * spacing * 8, row * spacing * spacing * 1.5, "HighScore:   ");
    std::string p2high = std::to_string(subject->getp2()->getHighScore());
    w->drawString(row * spacing * 10, row * spacing * spacing * 1.5, p2high);
}


