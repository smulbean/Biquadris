#include <iostream>
#include <vector>
#include "blank.h"
#include "block.h"
#include "level.h"
#include "levelzero.h"
#include "board.h"
#include "observer.h"
#include "text.h"
#include "observer.h"
#include "subject.h"
#include "player.h"
#include "studio.h"


int main(int argc, char* argv[])
{   
    // initialize players
    Player* p1 = new Player(c1, 0, 0, 0, l); // for now make it one player
    Player* p2 = new Player(c2, 0, 0, 0, l); // for now make it one player
    Player* p = p1;
    // make studio work on canvas
    // studio will take both players
    Studio s{p1, p2};
    Level* l;
    if (argc > 1) {
        bool textonly = false;
        for (int i = 1; i < argc; ++i) {
            if (argv[i] == "-text"){
                // text only
                Text *Tobserver = new Text(&s);
                s.attach(Tobserver);
                textonly = true;
            }
            if (argv[i] == "-startlevel"){
                //l == new Level argv[i + 1]
            }
            if (argv[i] == "-scriptfile1"){
                //read in to player 1 from argv[i + 1]
            }
            if (argv[i] == "-scriptfile2"){
                //read in to player 2 from argv[i + 1]
            }
            if (argv[i] == "-seed "){
                //read in seed from argv[i + 1]
            }
        }
        if (!textonly){
            Text *Tobserver = new Text(&s);
            s.attach(Tobserver);
            // Graphic *Gobserver = new Graphic(&s);
            // s.attach(Gobserver);
        }
    } else {
        // start level 0
        l = new Levelzero(); // fix this for parameters
    }
    // make a new canvas for tetris
    Board* c1 = new Blank(); // fix this for parameters
    Board* c2 = new Blank();
   
    // list of observers
    // std::vector<Observer*> observers;
    // make two players, wich store their own canvas
    std::string command;

    while (std::cin >> command)
    {
        if (command[0] == 'l' && command[2] == 'f')
        { // left
            p->curBlock()->left();
            s.notifyObservers();
        }
        else if (command[0] == 'r')
        { // right
            p->curBlock()->right();
            s.notifyObservers();
        }
        else if (command[1] == 'o')
        { // down
            p->curBlock()->down();
            s.notifyObservers();
        }
        else if (command[1] == 'r')
        { // drop
            p->curBlock()->drop();
            s.notifyObservers();
        }
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
        else if (command[0] == 'l' && command[5] == 'u') { // levelup 
            p->Levelup();
        }
        else if (command[0] == 'l' && command[5] == 'd') { // level down
            p->Leveldown();
        }

        // else if (command == "addtext") {
        //   int top, bottom, left, right;
        //   std::cin >> top >> bottom >> left >> right;
        //   Text *Tobserver = new Text(top, bottom, left, right, &s);
        //   s.attach(Tobserver);
        //   observers.push_back(Tobserver);
        // }
        // else if (command == "addgraphics") {
        //   int top, bottom, left, right;
        //   std::cin >> top >> bottom >> left >> right;
        //   Graphic *Gobserver = new Graphic(top, bottom, left, right, &s);
        //   s.attach(Gobserver);
        //   observers.push_back(Gobserver);
        // } // if
    } // while
    //   for (Observer* observer : observers) {
    //     delete observer;  // Explicitly delete each observer
    //   }
    return 0;
} // main
