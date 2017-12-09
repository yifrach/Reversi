//
// Created by yarin on 12/8/17.
//

#include <cstdlib>
#include "../include/OnlineOpponent.h"

OnlineOpponent::OnlineOpponent(Client* playerClient): playerClient(playerClient) {}

Point OnlineOpponent::passTurn() {
  cout << "\nPlayer has no moves, it's your turn: \n" << endl;
}

Point OnlineOpponent::playTurn(Board *board) {
  Point point(0, 0);
  try {
    point = playerClient->readSocket();
  } catch (const char *msg) {
    cout << "Failed to connect to server. Reason:" << msg << endl;
    exit(-1);
  }
  if (point.getX() > 0) {
    cout << "\nPlayer played: ";
    point.print();
    cout <<endl;
  }
  return point;
}