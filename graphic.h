#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include "observer.h"
#include "subject.h"
#include "window.h"

class Graphic : public Observer {
  Studio *subject;
  int t = 0;
  int b = 18;
  int l = 0;
  int r = 11;
  int row = 11;
  int col = 18;
  int spacing = 5;
  int full1();
  int full2();
 public:
  Graphic(Studio *subject); // constructor
  void notify() override;
  ~Graphic() override;
};

#endif

