#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H
#include "BoardScanner.h"
#include "Flip.h"
#include "AI.h"
#include "Client.h"
#include <iostream>

class GameManager {
 public:
  //constructor
  GameManager(BoardScanner *scanner, Board *board);
  //destructor
  ~GameManager();
  //Play a single turn of desired color for a player that it got
  Point playOneTurn(Player *player);

 private:
  int wall;
  BoardScanner *scanner;
  Board *board;
  Flip *flip;
};

#endif //EX2_GAMELOGIC_H
