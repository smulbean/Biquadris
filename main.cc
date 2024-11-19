#include <iostream>
#include <vector>
#include "blank.h"
#include "block.h"
#include "level.h"
#include "board.h"
#include "observer.h"
#include "text.h"
#include "observer.h"
#include "subject.h"
#include "player.h"


int main()
{
    // make a new canvas for tetris
    Board* canvas = new Blank;
    // make studio work on canvas
    Player* p1 = new Player(canvas); // for now make it one player
    // list of observers
    // std::vector<Observer*> observers;
    // make two players, wich store their own canvas
    std::string command;

    while (std::cin >> command)
    {
        if (command[0] == 'l')
        { // left
        }
        else if (command[0] == 'r')
        { // right
        }
        else if (command[1] == 'o')
        { // down
        }
        else if (command[1] == 'r')
        { // drop
        }
        else if (command == "I")
        {
        }
        else if (command == "J")
        {
            
        }
        else if (command == "L")
        {
            
        }
        else if (command == "O")
        {
            
        }
        else if (command == "S")
        {
            
        }
        else if (command == "Z")
        {
            
        }
        else if (command == "T")
        {
            
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
