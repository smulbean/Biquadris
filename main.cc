#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include "blank.h"
#include "block.h"
#include "level.h"
#include "level0.h"
#include "board.h"
#include "observer.h"
#include "text.h"
#include "observer.h"
#include "subject.h"
#include "player.h"
#include "studio.h"
#include "graphic.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

int main(int argc, char *argv[])
{
    // initialize a level
    Level *l1;
    Level *l2;
    bool textonly = false;
    bool startlevel = false;
    bool scriptfile1 = false;
    bool scriptfile2 = false;
    bool nextheavy = false;
    // bool seed = false;
    string file1string = "sequence1.txt";
    string file2string = "sequence1.txt";
    // list of observers
    std::vector<Observer *> observers;
    // make studio work on canvas
    // studio will take both players
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            if (std::strcmp(argv[i], "-text") == 0)
            {
                // text only
                textonly = true;
            }
            if (std::strcmp(argv[i], "-scriptfile1") == 0)
            {
                // read in to player 1 from argv[i + 1]
                file1string = argv[i + 1];
            }
            if (std::strcmp(argv[i], "-scriptfile2") == 0)
            {
                // read in to player 2 from argv[i + 1]
                file2string = argv[i + 1];
            }
            if (std::strcmp(argv[i], "-startlevel") == 0)
            {
                // l == new Level argv[i + 1]
                if (std::stoi(argv[i + 1]) == 1)
                {
                    l1 = new LevelOne(1);
                    l2 = new LevelOne(2);
                }
                else if (std::stoi(argv[i + 1]) == 2)
                {
                    l1 = new LevelTwo(1);
                    l2 = new LevelTwo(2);
                }
                else if (std::stoi(argv[i + 1]) == 3)
                {
                    l1 = new LevelThree(1, true, file2string);
                    l2 = new LevelThree(2, true, file2string);
                }
                else if (std::stoi(argv[i + 1]) == 4)
                {
                    l1 = new LevelFour(1, true, file2string);
                    l2 = new LevelFour(2, true, file2string);
                }
                startlevel = true;
            }
            // if (std::strcmp(argv[i], "-seed"){
            //     //read in seed from argv[i + 1]
            //     seed = true;
            // }
        }
    }
    if (!startlevel)
    {
        // start level 0
        l1 = new LevelZero(1);
        l2 = new LevelZero(2); // fix this for parameters
    }
    // make a new canvas for tetris
    Board *c1 = new Blank(); // fix this for parameters
    Board *c2 = new Blank();
    // initialize players
    Player *p1 = new Player(c1, 0, 0, 0, 1, l1, file1string, true); // for now make it one player
    Player *p2 = new Player(c2, 0, 0, 0, 2, l2, file2string, true); // for now make it one player
    Player *p = p1;
    // create studio
    Studio s{p1, p2};
    if (!textonly)
    {
        Text *Tobserver = new Text(&s);
        s.attach(Tobserver);
        observers.push_back(Tobserver);
        Graphic *Gobserver = new Graphic(&s);
        s.attach(Gobserver);
        observers.push_back(Gobserver);
    }
    // if textonly, then create the text observer
    if (textonly)
    {
        Text *Tobserver = new Text(&s);
        s.attach(Tobserver);
        observers.push_back(Tobserver);
    }

    bool turn1 = true;

    string command;
    char currentl1 = p1->next();
    char currentl2 = p2->next();
    p->setcur(currentl1);
    s.notifyObservers();
    while (cin >> command)
    {
        if (p->getpic()!= nullptr && p->getpic()->lose()){
            std::cout << "YOU LOSE!" << std::endl;
            break;
        }
        if (command[0] == 'r' && command[2] == 'a')
        { // random
            p->settrue();
        }
        if (command[0] == 'n' && command[2] == 'o')
        { // norandom
            p->setfalse();
        }
        // do the command
        if (command[0] == 'l' && command[2] == 'f')
        { // left
            p->getpic()->left();
            s.notifyObservers();
        }
        else if (command[0] == 'r' && command[1] == 'i')
        { // right
            p->getpic()->right();
            s.notifyObservers();
        }
        else if (command[0] == 'd' && command[1] == 'o')
        { // down
            p->getpic()->down();
            s.notifyObservers();
        }
        else if ((p->getpic() != nullptr) && (command[0] == 'd') && (command[1] == 'r'))
        { // drop
            p->getpic()->drop();
            s.notifyObservers();
        }
        else if (command[0] == 'c' && command[1] == 'l')
        { // clockwise
            p->getpic()->rotateC();
            s.notifyObservers();
        }
        else if (command[0] == 'c' && command[1] == 'o')
        { // counterclockwise
            p->getpic()->rotateCC();
            s.notifyObservers();
        }
        // if (nextheavy == true)
        // {
        //     p->getpic()->down();
        //     s.notifyObservers();
        //     nextheavy = false;
        // }
        // if (command[0] == 'h')
        // {
        //     nextheavy = true;
        // }
        else if (command == "I")
        {
            p->setcur('I');
            s.notifyObservers();
        }
        else if (command == "J")
        {
            p->setcur('J');
            s.notifyObservers();
        }
        else if (command == "L")
        {
            p->setcur('L');
            s.notifyObservers();
        }
        else if (command == "O")
        {
            p->setcur('O');
            s.notifyObservers();
        }
        else if (command == "S")
        {
            p->setcur('S');
            s.notifyObservers();
        }
        else if (command == "Z")
        {
            p->setcur('Z');
            s.notifyObservers();
        }
        else if (command == "T")
        {
            p->setcur('T');
            s.notifyObservers();
        }
        else if (command[0] == 'l' && command[1] == 'e' && command[2] == 'v' && command[5] == 'u' && command[6] == 'p')
        { // levelup
            p->Levelup();
            s.notifyObservers();
        }
        else if (command[0] == 'l' && command[5] == 'd')
        { // level down
            p->Leveldown();
            s.notifyObservers();
        }
        else if (command[0] == 'r' && command[1] == 'e')
        { // restart
            p->restart();
            s.notifyObservers();
        }
        if ((p->getpic() != nullptr) && p->getpic()->done())
        {
            // level will return next block, will call p->setcur('L') and then notify
            if (turn1)
            {
                p = p2;
                turn1 = false;
                // store block when you created it
                currentl2 = p->next();
                p->setcur(currentl2);
            }
            else
            {
                p = p1;
                turn1 = true;
                // store block when you create it
                currentl1 = p->next();
                p->setcur(currentl1);
            }
            s.notifyObservers();
        }
        if (command == "exit")
        { // exit
            break;
        }
    }

    for (Observer *observer : observers)
    {
        delete observer; // Explicitly delete each observer
    }
    return 0;
} // main


