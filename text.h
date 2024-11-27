#ifndef _TEXT_H_
#define _TEXT_H_
#include "observer.h"
#include "subject.h"

class Text : public Observer {
  std::shared_ptr<Studio> subject;
  int cols = 11;
  int rows = 18;
  int spacing = 5;
  bool blind; // remember to put in blind
  int full1();
  int full2();
  bool emptytop1();
  bool emptytop2();
 public:
  explicit Text(std::shared_ptr<Studio> subject); // constructor
  void notify() override;
  ~Text() override = default;
};

#endif

