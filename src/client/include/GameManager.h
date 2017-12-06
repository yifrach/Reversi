#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H

#include "BoardScanner.h"
#include "Flip.h"
#include "AI.h"
#include "Client.h"
#include <iostream>

/**
 * The class responsible for the logic of the game
 */
class GameManager {
 public:
  // the constructor of the class, get a Board and a BoardScanner
  GameManager(BoardScanner *scanner, Board *board);

  //the destructor
  ~GameManager();

  //playing a single turn based on the player color
  void playOneTurn(int color);

  //the method get a player and playing a single turn of the AI.
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
