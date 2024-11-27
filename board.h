#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <memory>

class Board
{
public:
  virtual ~Board();
  virtual char charAt(int row, int col) = 0;
};

#endif
