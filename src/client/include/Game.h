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
  //constructor
  Game();
  //destructor
  ~Game();
  // initalzing our games elements
  void initialize();
  // The method play the game by the mode that the user had chosen
  void playGame();
  //The method play the game by the mode of human against human
  void playHuman();
  //The method play the game by the mode - human against the computer
  void playAI();
  //The method play the game by the mode -client against other client
  void playClient();
  // The method read a file and initialize the Client player
  // by the parameters from the file
  void readFile();

 private:
  int size;
  GameManager *manager;
  BoardScanner *scanner;
  Board *board;
  Player *player1;
  Player *player2;
  int mode;
  // show the player the main menu
  void menuGame();
  // initialize the players by the mode
  void initializePlayers();
};

#endif //EX2_GAMEMANAGER_H
