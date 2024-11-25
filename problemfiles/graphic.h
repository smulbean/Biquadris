#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include "observer.h"
#include "subject.h"

class Graphic : public Observer {
  int t, b, l, r;
  Studio *subject;
 public:
  int full1();
  int full2();
  Graphic(int t, int b, int l, int r, Studio *subject); // constructor
  void notify() override;
  ~Graphic() override;
};

#endif

