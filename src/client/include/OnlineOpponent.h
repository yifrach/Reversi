//
// Created by yarin on 12/8/17.
//

#ifndef REVERSI_ONLINEOPPONENT_H
#define REVERSI_ONLINEOPPONENT_H
#include "Player.h"
#include "Client.h"

//The class OnlineOpponent heirs from the class Player

class OnlineOpponent: public Player {
 public:
  //constructor
  OnlineOpponent(Client *playerClient);
  // The method get a Board and return the point
  Point playTurn(Board* board);
  //the method pass the turn of the player
  Point passTurn();
 private:
  Client* playerClient;
};
#endif //REVERSI_ONLINEOPPONENT_H
