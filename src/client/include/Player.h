#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <iostream>
#include "Board.h"
using namespace std;

class Player {
 public:
  Player();
  virtual void setColor(int newColor);
  virtual void print();
  virtual void updateScore(int updatedScore);
  virtual int getColor();
  virtual int getScore();

 private:
  int color;
  int score;
};

#endif //EX2_PLAYER_H
