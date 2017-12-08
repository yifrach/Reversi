#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H
#include "Player.h"
#include "Point.h"
#include "../include/ColorEnum.h"
using namespace std;

class Client: public Player{
 public:
  Client(const char* serverIP, int serverPort);
  Color connectToServer(); // returns the players color
  void sendSocket(int xPos, int yPos);
  Point readSocket();

 private:
  const char *serverIP;
  int serverPort;
  int clientSocket;
};
#endif //REVERSI_CLIENT_H
