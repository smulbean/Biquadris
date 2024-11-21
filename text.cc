#include "observer.h"
#include "subject.h"
#include "studio.h"
#include "text.h"
#include <iostream>
using namespace std;

Text::Text(Studio *subject): subject{subject}{
}

void Text::notify(){
  int cols = 11;
  int rows = 18; // but in reality 15 as the top 3 is display only, die when you hit 15
  cout << '+';
  for (int j = 0; j < cols; ++j) cout << '-';
  cout << '+' << std::endl;
  for (int i = 0; i < rows; ++i) {
    cout << '|';
    for (int j = 0; j < cols; ++j) {
      cout << subject->getState(i, j);
    }
    cout << '|' << std::endl;
  }
  cout << '+';
  for (int j = 0; j < cols; ++j) cout << '-';
  cout << '+' << std::endl;
}

Text::~Text(){
  subject->detach(this);
}

