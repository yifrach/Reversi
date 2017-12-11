#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <iostream>
#include "Board.h"
using namespace std;

class Player {
 public:
  //constructor
  Player();
  // Setter for our players color
  virtual void setColor(int newColor);
  // Printing the players color
  virtual void print();
  // Updating our players score to updatedScore
  virtual void updateScore(int updatedScore);
  // Getter for our players color
  virtual int getColor();
  // Getter for our players score
  virtual int getScore();
  // The method get a Board and return the point
  virtual Point playTurn(Board *board)=0;
  // The method pass the turn of the player
  virtual Point passTurn()=0;

 private:
  int color;
  int score;
};

#endif //EX2_PLAYER_H
