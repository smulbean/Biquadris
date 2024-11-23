#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board
{
public:
  virtual ~Board();
  virtual char charAt(int row, int col) = 0;
  virtual void rotateC() = 0;
  virtual void rotateCC() = 0;
  virtual void down() = 0;
  virtual void left() = 0;
  virtual void right() = 0;
  virtual void drop() = 0;
};

#endif
