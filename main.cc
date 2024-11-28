#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
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


std::string file1string = "sequence1.txt";
std::string file2string = "sequence2.txt";
int seed = 288;
bool isSeed = false;

int main(int argc, char *argv[])
{
    // initialize a level
    std::shared_ptr<Level> l1;
    std::shared_ptr<Level> l2;
    bool textonly = false;
    bool startlevel = false;
    bool scriptfile1 = false;
    bool scriptfile2 = false;
    // string file1string;
    // string file2string;
    // list of observers
    std::vector<std::shared_ptr<Observer>> observers;

    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            if (std::strcmp(argv[i], "-text") == 0)
            {
                // text only
                std::cout << "Entering text-only mode!" << std::endl;
                textonly = true;
            }
            if (std::strcmp(argv[i], "-scriptfile1") == 0)
            {
                if (i + 1 < argc && argv[i + 1][0] == '-') {
                    std::cout << "You forgot to give us a file!" << std::endl;
                } else {
                    file1string = argv[i + 1];
                }
            }
            if (std::strcmp(argv[i], "-scriptfile2") == 0)
            {
                if (i + 1 < argc && argv[i + 1][0] == '-') {
                    std::cout << "You forgot to give us a file!" << std::endl;
                } else {
                    file2string = argv[i + 1];
                }
            }
            if (std::strcmp(argv[i], "-startlevel") == 0)
            {
                if (std::stoi(argv[i + 1]) == 1)
                {
                    l1 = std::make_shared<LevelOne>(1);
                    l2 = std::make_shared<LevelOne>(2);
                    std::cout << "Starting Level 1" << std::endl;
                }
                else if (std::stoi(argv[i + 1]) == 2)
                {
                    l1 = std::make_shared<LevelTwo>(1);
                    l2 = std::make_shared<LevelTwo>(2);
                    std::cout << "Starting Level 2" << std::endl;
                }
                else if (std::stoi(argv[i + 1]) == 3)
                {
                    l1 = std::make_shared<LevelThree>(1, true, file1string);
                    l2 = std::make_shared<LevelThree>(2, true, file2string);
                    std::cout << "Starting Level 3" << std::endl;
                }
                else if (std::stoi(argv[i + 1]) == 4)
                {
                    l1 = std::make_shared<LevelFour>(1, true, file1string);
                    l2 = std::make_shared<LevelFour>(2, true, file2string);
                    std::cout << "Starting Level 4" << std::endl;
                }
                startlevel = true;
            }
            if (std::strcmp(argv[i], "-seed") == 0){
                 //read in seed from argv[i + 1]
                 if (i + 1 < argc && ('0' <= argv[i + 1][0] && argv[i + 1][0] <= '9')) {
                    seed = std::stoi(argv[i + 1]);
                 } else {
                    std::cout << "Please enter a valid number for your seed!" << std::endl;
                 }
                 isSeed = true;
            }
            if (std::strcmp(argv[i], "-noseed") == 0) {
                // for true randomness
                std::cout << "You entered random-mode!" << std::endl;
                isSeed = false;
            }
        }
    }
    if (!startlevel)
    {
        // start level 0
        l1 = std::make_shared<LevelZero>(1);
        l2 = std::make_shared<LevelZero>(2); 
    }
    // make a new canvas for tetris
    std::shared_ptr<Board> c1 = std::make_shared<Blank>(); 
    std::shared_ptr<Board> c2 = std::make_shared<Blank>();
    // initialize players
    std::shared_ptr<Player> p1 = std::make_shared<Player>(c1, 0, 0, 0, 1, l1, file1string, true); 
    std::shared_ptr<Player> p2 = std::make_shared<Player>(c2, 0, 0, 0, 2, l2, file2string, true); 
    std::shared_ptr<Player> p = p1;
    // create studio
    Studio s{p1, p2};
    auto s_ptr = std::make_shared<Studio>(s); 

    auto Tobserver = std::make_shared<Text>(s_ptr); 
    s.attach(Tobserver);
    observers.push_back(Tobserver);

    if (!textonly)
    {
        auto Gobserver = std::make_shared<Graphic>(s_ptr); 
        s.attach(Gobserver);
        observers.push_back(Gobserver);
    }

    bool turn1 = true;
    bool sequence = false;

    string command;
    char currentl1 = p1->next();
    char currentl2 = p2->next();
    p->setcur(currentl1);
    string file = "";
    std::ifstream f;
    s.notifyObservers();
    while (true)
    {
        string number = "";
        int n = 0;
        int digit = 0;
        if (sequence){
            if (!(f >> command)) { // Check for EOF or read failure
                sequence = false; // Reset sequence mode
                f.close();        // Close the file
                continue;         // Skip further input until the next iteration
            }
        } else {
            std::cin >> command;
        }
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] >= '0' && command[i] <= '9')
            {
                digit++;
            }
        }
        number = command.substr(0, digit);
        command = command.substr(digit);
        try
        {
            n = stoi(number);
        }
        catch (const std::invalid_argument &e)
        {
            n = 1;
        }

        if (p->getpic() != nullptr && p->getpic()->lose())
        {
            std::cout << "YOU LOSE!" << std::endl;
            break;
        }
        if (command[0] == 's' && command[1] == 'e'){
            sequence = true;
            std::cin >> file;
            f.open(file);
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
            for (int i = 0; i < n; i++)
            {
                p->getpic()->left();
            }
            if (p->getLevel() == 3 || p->getLevel() == 4)
            {
                p->getpic()->down();
            }
            s.notifyObservers();
        }
        else if (command[0] == 'r' && command[1] == 'i')
        { // right
            for (int i = 0; i < n; i++)
            {
                p->getpic()->right();
            }
            if (p->getLevel() == 3 || p->getLevel() == 4)
            {
                p->getpic()->down();
            }
            s.notifyObservers();
        }
        else if (command[0] == 'd' && command[1] == 'o')
        { // down
            for (int i = 0; i < n; i++)
            {
                p->getpic()->down();
            }
            if (p->getLevel() == 3 || p->getLevel() == 4)
            {
                p->getpic()->down();
            }
            s.notifyObservers();
        }
        else if ((p->getpic() != nullptr) && (command[0] == 'd') && (command[1] == 'r'))
        { // drop
            for (int i = 0; i < n; i++)
            {
                p->getpic()->drop();
            }
            if (p->getLevel() == 3 || p->getLevel() == 4)
            {
                p->getpic()->down();
            }
            s.notifyObservers();
        }
        else if (command[0] == 'c' && command[1] == 'l')
        { // clockwise
            for (int i = 0; i < n; i++)
            {
                p->getpic()->rotateC();
            }
            if (p->getLevel() == 3 || p->getLevel() == 4)
            {
                p->getpic()->down();
            }
            s.notifyObservers();
        }
        else if (command[0] == 'c' && command[1] == 'o')
        { // counterclockwise
            for (int i = 0; i < n; i++)
            {
                p->getpic()->rotateCC();
            }
            if (p->getLevel() == 3 || p->getLevel() == 4)
            {
                p->getpic()->down();
            }
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
        else if (command[0] == 'l' && command[1] == 'e' && command[2] == 'v' && command[5] == 'u' && command[6] == 'p')
        { // levelup
            for (int i = 0; i < n; i++)
            {
                p->Levelup();
            }
            s.notifyObservers();
        }
        else if (command[0] == 'l' && command[5] == 'd')
        { // level down
            for (int i = 0; i < n; i++)
            {
                p->Leveldown();
            }
            s.notifyObservers();
        }
        else if (command[0] == 'r' && command[1] == 'e')
        { // restart
            p->restart();
            if (turn1)
            {
                currentl2 = p->next();
                p->setcur(currentl2);
            }
            else
            {
                currentl1 = p->next();
                p->setcur(currentl1);
            }
            s.notifyObservers();
        }
        if ((p->getLevel() == 4) && (p->blocknum() % 5 == 0))
        {
            p->setcur('B');
            p->getpic()->drop();
        }
        if ((p->getpic() != nullptr) && p->getpic()->done())
        {

            if ((p->getpic() != nullptr) && p->getpic()->exceeded())
            {
                std::cout << "You lose!" << std::endl;
                break;
            }
            if (turn1)
            {
                p = p2;
                turn1 = false;
                currentl2 = p->next();
                p->setcur(currentl2);
            }
            else
            {
                p = p1;
                turn1 = true;
                currentl1 = p->next();
                p->setcur(currentl1);
            }
            s.notifyObservers();
        }
        if (command == "exit")
        { 
            break;
        }
    }
    return 0;
} 

