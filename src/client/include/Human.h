#ifndef REVERSI_HUMAN_H
#define REVERSI_HUMAN_H

#include <iostream>
#include "Player.h"

//The class AI heirs from the abstract class Player
class Human : public Player {
 public:
  //constructor
  Human();

  //destructor
  ~Human();

  //Getting a color and set his value in the member color of the player
  virtual void setColor(int newColor);

  //Printing the players color
  virtual void print();

  //Update the players score based on the board status
  virtual void updateScore(int updatedScore);

  //Get the players color
  virtual int getColor();

  //Get the players score
  virtual int getScore();

  //the method get a board and play a turn ob this board.
  virtual Point playTurn(Board *board);

 private:
  int score;
  int color;
};

#endif //REVERSI_HUMAN_H
