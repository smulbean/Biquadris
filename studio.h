#ifndef STUDIO_H
#define STUDIO_H
#include <iostream>
#include "subject.h"

class Board;

class Studio : public Subject{
  Board *thePicture;
  int ticks = 0;

 public:
  explicit Studio( Board* picture ): thePicture{picture} {}

  Board*& picture() { return thePicture; }
  void reset();
  void render();
  void animate(int numTicks);

  char getState(int row, int col) const override;

  ~Studio();
};

#endif
