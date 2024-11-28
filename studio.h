#ifndef STUDIO_H
#define STUDIO_H
#include <iostream>
#include "subject.h"
#include <memory>
#include "player.h"

class Board;

class Studio : public Subject{
  std::shared_ptr<Player> p1;
  std::shared_ptr<Player> p2;

 public:
  explicit Studio(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
    : p1{player1}, p2{player2} {}

  void reset();
  std::shared_ptr<Player> getp1();  
  std::shared_ptr<Player> getp2();  
  char getStatep1(int row, int col) const override;
  char getStatep2(int row, int col) const override;

  ~Studio() = default;
};

#endif
