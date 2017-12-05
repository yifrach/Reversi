//
// Created by yarin on 11/25/17.
//

#ifndef REVERSI_AI_H
#define REVERSI_AI_H

#include <iostream>
#include "Player.h"
#include "Board.h"
#include <vector>
#include "Point.h"
#include "GameManager.h"

//The class AI heirs from the abstract class Player
class AI : public Player {
 public:
  //constructor
  AI();

  //the method get a board and play a turn ob this board.
  Point playTurn(Board *board);

  //Getting a color and set his value in the member color of the player
  virtual void setColor(int newColor);

  //Printing the players color
  void print();

  //Update the players score based on the board status
  void updateScore(int updatedScore);

  //Get the players color
  int getColor();

  //Get the players score
  int getScore();

 private:
  //this method is private because just the playTurn method use it.
  void checkPoint(Board *tempBoard, int i, BoardScanner *scanner);
  vector<int> *moves;
  int color;
  int score;
};

#endif //REVERSI_AI_H
