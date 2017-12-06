#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>
#include "Board.h"
//enum that represent the numbers, -1, 0 ,1 - help us to understand the code.
enum Color { white, black };

using namespace std;

/**
 * The class Player is an abstract class that the AI and Human heirs.
 */
class Player {
 public:
  Player();
  ~Player();

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

//  //the method get a board and play a turn ob this board.
//  virtual Point playTurn(Board *board)=0;
 private:
  int color;
  int score;
};

#endif //EX2_PLAYER_H
