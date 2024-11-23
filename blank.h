#ifndef BLANK_H
#define BLANK_H
#include "board.h"
#include <iostream>

class Blank : public Board
{
public:
  char charAt(int row, int col) override;
  void rotateC(){};
  void rotateCC(){};
  void down(){};
  void left(){};
  void right(){};
  void drop(){};
};

#endif
