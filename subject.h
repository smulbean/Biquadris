#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory> 

class Observer; // forward declaration

class Subject {
  std::vector<std::shared_ptr<Observer>> observers;
 public:
  void attach(std::shared_ptr<Observer> o);  
  void detach(std::shared_ptr<Observer> o);  
  void notifyObservers();  
  virtual char getStatep1(int row, int col) const = 0; 
  virtual char getStatep2(int row, int col) const = 0;
  virtual ~Subject() = default; 
};

#endif
