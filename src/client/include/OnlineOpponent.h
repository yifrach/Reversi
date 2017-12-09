//
// Created by yarin on 12/8/17.
//

#ifndef REVERSI_ONLINEOPPONENT_H
#define REVERSI_ONLINEOPPONENT_H
#include "Player.h"
#include "Client.h"

class OnlineOpponent: public Player {
 public:
  OnlineOpponent(Client *playerClient);
  Point playTurn(Board* board);
  Point passTurn();
 private:
  Client* playerClient;
};
#endif //REVERSI_ONLINEOPPONENT_H
