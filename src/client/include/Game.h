#ifndef EX2_GAMEMANAGER_H
#define EX2_GAMEMANAGER_H

#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "AI.h"
#include "Human.h"

/**
 * The class Game responsible to initialize all the members
 * and it runs by the mode that the user choose.
 */
class Game {

 public:
  //the constructor of the class
  Game();

  //destructor of the class
  ~Game();

  //initilazing all of our game elements
  void initialize();

  //playing a single game
  void playGame();

  //playing a 2 player game
  void playHuman();

  //playing the game against the AI
  void playAI();

  //present the main
  void menuGame();

  //p;aying the game with a remote player
  void playClient();

  //read a word from the file
  void readFile();

 private:
  int size;
//  int player1Color;
//  int player2Color;
  GameManager *manager;
  BoardScanner *scanner;
  Board *board;
  Player *player1;
  Player *player2;
  int mode;
  int clientColor;
};

#endif //EX2_GAMEMANAGER_H
