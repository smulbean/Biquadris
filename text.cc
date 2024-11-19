#include "observer.h"
#include "subject.h"
#include "studio.h"
#include "text.h"
#include <iostream>
using namespace std;

Text::Text(int t, int b, int l, int r, Studio *subject): t{t}, b{b}, l{l}, r{r}, subject{subject}{
}

void Text::notify(){
  int cols = b - t + 1;
  int rows = r - l + 1;
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

