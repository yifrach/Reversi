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

  Point passTurn();

 private:
  //this method is private because just the playTurn method use it.
  void checkPoint(Board *tempBoard, int i, BoardScanner *scanner);
  vector<int> *moves;
};

#endif //REVERSI_AI_H
