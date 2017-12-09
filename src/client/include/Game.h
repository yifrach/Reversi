#ifndef EX2_GAMEMANAGER_H
#define EX2_GAMEMANAGER_H
#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "AI.h"
#include "Human.h"
#include "OnlineOpponent.h"

class Game {
 public:
  Game();
  ~Game();
  void initialize();  // initalzing our games elements
  void playGame();
  void playHuman();
  void playAI();
  void playClient();
  void readFile();

 private:
  int size;
  GameManager *manager;
  BoardScanner *scanner;
  Board *board;
  Player *player1;
  Player *player2;
  int mode;
  void menuGame(); // show the player the main menu
  void initializePlayers();
};

#endif //EX2_GAMEMANAGER_H
