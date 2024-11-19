#ifndef _TEXT_H_
#define _TEXT_H_
#include "observer.h"
#include "subject.h"

class Text : public Observer {
  int t, b, l, r;
  Studio *subject;
 public:
  Text(int t, int b, int l, int r, Studio *subject); // constructor
  void notify() override;
  ~Text() override;
};

#endif

