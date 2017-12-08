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
  void playOneTurn(int color);
  Point playOneTurnAI(Player *playerAI);
  void playOneTurnClient(int color, Player *playerClient);
  void playOneTurnClientFake(Player *playerClient, Player *playerFake);

 private:
  int wall;
  BoardScanner *scanner;
  Board *board;
  Flip *flip;
};

#endif //EX2_GAMELOGIC_H
