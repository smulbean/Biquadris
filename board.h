#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board {
 public:
   virtual ~Board();
   virtual char charAt(int row, int col, int tick) = 0;
};

#endif
