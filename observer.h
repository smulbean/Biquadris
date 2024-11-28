#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "subject.h"
#include "studio.h"

class Observer {
   std::shared_ptr<Studio>subject;
 public:
  virtual void notify() = 0;
  virtual ~Observer() = default;
};

#endif
