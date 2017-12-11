#ifndef REVERSI_HUMAN_H
#define REVERSI_HUMAN_H
#include <iostream>
#include "Player.h"

//The class Human heirs from the class Player
class Human : public Player {
 public:
  //constructor
  Human();
  //destructor
  ~Human();
  // The method get a Board and return the point
  Point playTurn(Board *board);
  //the method pass the turn of the player
  Point passTurn();
};

#endif //REVERSI_HUMAN_H
