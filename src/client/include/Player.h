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
  virtual int getOpponentColor();
  virtual Point playTurn(Board *board)=0;
  virtual Point passTurn()=0;

 private:
  int color;
  int score;
};

#endif //EX2_PLAYER_H
