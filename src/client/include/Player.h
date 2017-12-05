#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>
#include "Board.h"

using namespace std;

/**
 * The class Player is an abstract class that the AI and Human heirs.
 */
class Player {
 public:
  //Getting a color and set his value in the member color of the player
  virtual void setColor(int newColor)=0;

  //Printing the players color
  virtual void print()=0;

  //Update the players score based on the board status
  virtual void updateScore(int updatedScore)=0;

  //Get the players color
  virtual int getColor()=0;

  //Get the players score
  virtual int getScore()=0;

  //the method get a board and play a turn ob this board.
  virtual Point playTurn(Board *board)=0;
};

#endif //EX2_PLAYER_H
