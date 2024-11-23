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
  int rows = 18;
  int spacing = 5;
  // print the beginning
  cout << "Level:     " << subject->getp1()->getLevel() << "     "; // 5 spaces inbetween board
  cout << "Level:     " << subject->getp2()->getLevel() << endl;
  //print score
  cout << "Score:     " << subject->getp1()->getScore() << "     "; // 5 spaces inbetween board
  cout << "Score:     " << subject->getp2()->getScore() << endl;
  //get high score
  cout << "HighScore: " << subject->getp1()->getHighScore() << "     "; // 5 spaces inbetween board
  cout << "HighScore: " << subject->getp2()->getHighScore() << endl;
  // print top seperator
  for (int i = 0; i < cols; i++){
    cout << "-";
  }
  for (int i = cols + spacing; i < 2*cols + spacing; i++){
    cout << "-";
  }
  // print board
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << subject->getStatep1(i, j);
    }
    for (int j = cols+spacing; j < 2*cols+spacing; ++j) {
      cout << subject->getStatep2(i, j);
    }
  }
  // print second seperator
  for (int i = 0; i < cols; i++){
    cout << "-";
  }
  for (int i = cols + spacing; i < 2*cols + spacing; i++){
    cout << "-";
  }
  //next block
  //manual function that presents the blocks
}


Text::~Text(){
  subject->detach(this);
}

