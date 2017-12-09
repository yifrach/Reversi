#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H
#include "BoardScanner.h"
#include "Flip.h"
#include "AI.h"
#include "Client.h"
#include <iostream>

class GameManager {
 public:
  GameManager(BoardScanner *scanner, Board *board);
  ~GameManager();
  Point playOneTurn(Player* player);
 private:
  int wall;
  BoardScanner *scanner;
  Board *board;
  Flip *flip;
};

#endif //EX2_GAMELOGIC_H
