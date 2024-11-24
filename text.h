#ifndef _TEXT_H_
#define _TEXT_H_
#include "observer.h"
#include "subject.h"

class Text : public Observer {
  Studio *subject;
  int cols = 11;
  int rows = 18;
  int spacing = 5;
  bool blind; // remember to put in blind
  int fullrow1();
  int fullrow2(int row);
  void print1(int row);
  void print2(int row);
 public:
  Text(Studio *subject); // constructor
  void notify() override;
  ~Text() override;
};

#endif

