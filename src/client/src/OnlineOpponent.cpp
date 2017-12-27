//
// Created by yarin on 12/8/17.
//

#include <cstdlib>
#include "../include/OnlineOpponent.h"
#define CLOSE_SERVER_INT -3

/**
 * The constructor of the class
 * @param playerClient - a Client pointer
 */
OnlineOpponent::OnlineOpponent(Client *playerClient) : playerClient(playerClient) {}

/**
 * The method pass the turn of the player
 * @return - a Point that represent that the user had no move.
 */
Point OnlineOpponent::passTurn() {
  cout << "\nPlayer has no moves, it's your turn: \n" << endl;
  return Point(-1, -1);
}

/**
 * The method get a Board, read a move from the socket and return it
 * @param board - a variable from type Board
 * @return - a Point that represent the player move
 */
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
    cout << endl;
  } else if (point.getX() == CLOSE_SERVER_INT) {
    cout << "The server is now close, sorry for closing your game.\nBye Bye :)";
    exit(0);
  }
  return point;
}