#ifndef _TEXT_H_
#define _TEXT_H_
#include "observer.h"
#include "subject.h"

class Text : public Observer {
  Studio *subject;
 public:
  Text(Studio *subject); // constructor
  void notify() override;
  ~Text() override;
};

#endif

