#include "observer.h"
#include "subject.h"
#include "studio.h"
#include "text.h"
#include <iostream>
using namespace std;

// need a function to check if everyline on that board is cleansed, if so, we just not print that line
// and then add the score to score and update highscore
// subject->getp1()->updateScore(int inc) adds inc to current score
// subject->getp1()->updateHigh(int high)changes highscore to high
bool Text::fullrow1(int row)
{
  for (int i = 0; i < cols; i++)
  {
    if (subject->getStatep1(i, row) == ' ')
    {
      return false;
    }
  }
  subject->getp1()->updateScore((subject->getp1()->getLevel() + 1)*(subject->getp1()->getLevel() + 1));
  if (subject->getp1()->getScore() > subject->getp1()->getHighScore()){
    subject->getp1()->updateHigh(subject->getp1()->getScore());
  }
  return true;
}

bool Text::fullrow2(int row)
{
  for (int i = cols + spacing; i < 2 * cols; i++)
  {
    if (subject->getStatep1(i - (cols + spacing), row) == ' ')
    {
      return false;
    }
  }
  subject->getp2()->updateScore((subject->getp2()->getLevel() + 1)*(subject->getp2()->getLevel() + 1));
  if (subject->getp2()->getScore() > subject->getp2()->getHighScore()){
    subject->getp2()->updateHigh(subject->getp2()->getScore());
  }
  return true;
}

void Text::print1(int row)
{
  for (int j = 0; j < cols; ++j)
  {
    cout << subject->getStatep1(j, row);
  }
}

void Text::print2(int row)
{
  for (int j = cols + spacing; j < 2 * cols + spacing; ++j)
  {
    cout << subject->getStatep2(j - (cols + spacing), row);
  }
}

Text::Text(Studio *subject) : subject{subject}
{
}

void Text::notify()
{
  // print the beginning
  cout << "Level:     " << subject->getp1()->getLevel() << "     "; // 5 spaces inbetween board
  cout << "Level:     " << subject->getp2()->getLevel() << endl;
  // print score
  cout << "Score:     " << subject->getp1()->getScore() << "     "; // 5 spaces inbetween board
  cout << "Score:     " << subject->getp2()->getScore() << endl;
  // get high score
  cout << "HighScore: " << subject->getp1()->getHighScore() << "     "; // 5 spaces inbetween board
  cout << "HighScore: " << subject->getp2()->getHighScore() << endl;
  // print top seperator
  for (int i = 0; i < cols; i++)
  {
    cout << "-";
  }
  for (int i = 0; i < spacing; i++)
  {
    cout << " ";
  }
  for (int i = cols + spacing; i < 2 * cols + spacing; i++)
  {
    cout << "-";
  }
  cout << endl;
  // print board
  for (int p1counter = 0, p2counter = 0; p1counter < rows || p2counter < rows;)
  {
    if (!fullrow1(p1counter))
    {
      print1(p1counter); // if its not full print
      p1counter++;
    } else {
      while(fullrow1(p1counter)){ // else loop until its not full
        p1counter++;
      }
      print1(p1counter); // then print
    }
    for (int j = 0; j < spacing; ++j)
    {
      cout << " ";
    }
    if (!fullrow2(p2counter))
    {
      print2(p2counter); // if its not full print
      p2counter++;
    } else {
      while(fullrow2(p2counter)){ // else loop until its not full
        p2counter++;
      }
      print2(p2counter); // then print
    }
    cout << endl;
  }
  // print second seperator
  for (int i = 0; i < cols; i++)
  {
    cout << "-";
  }
  for (int i = 0; i < spacing; i++)
  {
    cout << " ";
  }
  for (int i = cols + spacing; i < 2 * cols + spacing; i++)
  {
    cout << "-";
  }
  cout << endl;
  // next block
  // manual function that presents the blocks
}

Text::~Text()
{
  subject->detach(this);
}
