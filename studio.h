#ifndef STUDIO_H
#define STUDIO_H
#include <iostream>
#include "subject.h"

class Board;

class Studio : public Subject{
  Player *p1;
  Player *p2;
  int ticks = 0;

 public:
  explicit Studio( Player* player1, Player* player2): p1{player1}, p2{player2}{}

  void reset();
  void render();
  char getStatep1(int row, int col) const override;
  char getStatep2(int row, int col) const override;

  ~Studio();
};

#endif
