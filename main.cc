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


int main(int argc, char* argv[])
{      
    //initialize a level
    Level* l1;
    Level* l2;
    bool textonly = false;
    bool startlevel = false;
    bool scriptfile1 = false;
    bool scriptfile2 = false;
    // bool seed = false;
    string file1string;
    string file2string;
    // list of observers
    std::vector<Observer*> observers;
    // make studio work on canvas
    // studio will take both players
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (std::strcmp(argv[i], "-text") == 0){
                // text only
                textonly = true;
            }
            // if (std::strcmp(argv[i], "-startlevel") == 0){
            //     //l == new Level argv[i + 1]
            //     if (std::stoi(argv[i + 1]) == 1){
            //         l1 = new LevelOne();
            //     }
            //     else if (std::stoi(argv[i + 1]) == 2){
            //         l1 = new LevelTwo();
            //     }
            //     else if (std::stoi(argv[i + 1]) == 3){
            //         l1 = new Levelthree(); 
            //     }
            //     else if (std::stoi(argv[i + 1]) == 4){
            //         l1 = new Levelfour();
            //          l2 = new Levelfour();
            //     }
            //     startlevel = true;
            // }
            // if (std::strcmp(argv[i], "-scriptfile1"){
            //     //read in to player 1 from argv[i + 1]
            //     file1string = argv[i + 1];
            //     scriptfile1 = true;
            // }
            // if (std::strcmp(argv[i], "-scriptfile2"){
            //     //read in to player 2 from argv[i + 1]
            //     file2string = argv[i+1];
            //     scriptfile2 = true;
            // }
            // if (std::strcmp(argv[i], "-seed"){
            //     //read in seed from argv[i + 1]
            //     seed = true;
            // }
        }
    } 
    if (!startlevel){
        // start level 0
        l1 = new LevelZero(1);
        l2 = new LevelZero(2); // fix this for parameters
    }
    if (!scriptfile1){
        file1string = "sequence1.txt"; // wrong
    }
    if (!scriptfile2){
        file2string = "sequence2.txt";
    }
    // make a new canvas for tetris
    Board* c1 = new Blank(); // fix this for parameters
    Board* c2 = new Blank();
    // initialize players
    Player* p1 = new Player(c1, 0, 0, l1); // for now make it one player
    Player* p2 = new Player(c2, 0, 0, l2); // for now make it one player
    Player* p = p1;
    // create studio
    Studio s{p1, p2};
    if (!textonly){
        Text *Tobserver = new Text(&s);
        s.attach(Tobserver);
        observers.push_back(Tobserver);
        // Graphic *Gobserver = new Graphic(&s);
        // s.attach(Gobserver);
        //observers.push_back(Gobserver);
    }
    //if textonly, then create the text observer
    if (textonly){
        Text *Tobserver = new Text(&s);
        s.attach(Tobserver);
        observers.push_back(Tobserver);
    }

    //read from files
    std::ifstream file1(file1string); // did not account for the edge case where one file is longer than the other one
    std::ifstream file2(file2string);
    std::string line; // Flag to alternate between files

    bool turn1 = true;

    string command;
    char currentl1 = l1->createBlock();
    char currentl2 = l2->createBlock();
    p->setcur(currentl1);
    s.notifyObservers();
    while (cin >> command)
    {
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
        else if (command == "I")
        {
            p->setcur('I');
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
        // else if (command[0] == 'l' && command[5] == 'u') { // levelup 
        //     p->Levelup();
        // }
        // else if (command[0] == 'l' && command[5] == 'd') { // level down
        //     p->Leveldown();
        // }
        else if (command[0] == 'r' && command[1] == 'e') { // restart
            p->restart();
            s.notifyObservers();
        }
        if ((p->getpic() != nullptr) && p->getpic()->done()){
            // level will return next block, will call p->setcur('L') and then notify
            if (turn1){
                p = p2;
                turn1 = false;
                // store block when you created it
                currentl2 = l2->createBlock();
                p->setcur(currentl2);
            } else {
                p = p1;
                turn1 = true;
                // store block when you create it
                currentl1 = l1->createBlock();
                p->setcur(currentl1);
            }
            s.notifyObservers();
        }
        if (command == "exit")
        { // exit
            cin.eof();
        }
    } 
    file1.close();
    file2.close();
    for (Observer* observer : observers) {
        delete observer;  // Explicitly delete each observer
    }
    return 0;
} // main

