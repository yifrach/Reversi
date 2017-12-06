//
// Created by yarin on 12/4/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#include "Player.h"
#include "Point.h"
using namespace std;

class Client: public Player{
 public:
  Client(const char* serverIP, int serverPort);
  Color connectToServer();
  void sendSocketPoint(int arg1, int arg2);
  void sendSocketNoMove(char* str);
  Point readSocket();
 private:
  const char *serverIP;
  int serverPort;
  int clientSocket;
};
#endif //REVERSI_CLIENT_H
