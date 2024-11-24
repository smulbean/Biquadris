#ifndef BLANK_H
#define BLANK_H
#include "board.h"
#include <iostream>

class Blank : public Board
{
public:
  char charAt(int row, int col) override;
  void rotateC() override{};
  void rotateCC()override{};
  void down()override{};
  void left()override{};
  void right()override{};
  void drop()override{};
  bool done()override{
    return true;
  };
};

#endif
