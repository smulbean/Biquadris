#include "observer.h"
#include "subject.h"
#include "studio.h"
#include "text.h"
#include <iostream>
using namespace std;

int Text::full1()
{
  for (int i = 0; i < rows; i++)
  {
    int count = 0;
    for (int j = 0; j < cols; j++)
    {
      if (subject->getStatep1(j, i) != ' ')
      {
        count++;
      }
    }
    if (count == cols)
    {
      subject->getp1()->updateScore((subject->getp1()->getLevel() + 1) * (subject->getp1()->getLevel() + 1));
      if (subject->getp1()->getScore() > subject->getp1()->getHighScore())
      {
        subject->getp1()->updateHigh(subject->getp1()->getScore());
      }
      return i;
    }
  }
  return -1;
}

int Text::full2()
{
  for (int i = 0; i < rows; i++)
  {
    int count = 0;
    for (int j = cols + spacing; j < 2 * cols + spacing; ++j)
    {
      if (subject->getStatep2(j - (cols + spacing), i) != ' ')
      {
        count++;
      }
    }
    if (count == cols)
    {
      subject->getp2()->updateScore((subject->getp2()->getLevel() + 1) * (subject->getp2()->getLevel() + 1));
      if (subject->getp2()->getScore() > subject->getp2()->getHighScore())
      {
        subject->getp2()->updateHigh(subject->getp2()->getScore());
      }
      return i;
    }
  }
  return -1;
}

Text::Text(std::shared_ptr<Studio> subject) : subject(subject) {
}

void Text::notify()
{
  if (full1() != -1)
  {
    subject->getp1()->setCor(full1());
  }
  if (full2() != -1)
  {
    subject->getp2()->setCor(full2());
  }
  subject->getp1()->MoreScore();
  subject->getp2()->MoreScore();
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
  for (int i = 0; i <= spacing; i++)
  {
    cout << " ";
  }
  for (int i = cols + spacing; i < 2 * cols + spacing; i++)
  {
    cout << "-";
  }
  cout << endl;
  // print board
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j <= cols; ++j)
    {
      cout << subject->getStatep1(j, i);
    }
    for (int j = 0; j <= spacing; ++j)
    {
      cout << " ";
    }
    for (int j = cols + spacing; j < 2 * cols + spacing; ++j)
    {
      cout << subject->getStatep2(j - (cols + spacing), i);
    }
    cout << endl;
  }
  for (int i = 0; i < cols; i++)
  {
    cout << "-";
  }
  for (int i = 0; i <= spacing + 1; i++)
  {
    cout << " ";
  }
  for (int i = cols + spacing; i < 2 * cols + spacing; i++)
  {
    cout << "-";
  }
  cout << endl;
}


