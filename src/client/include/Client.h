#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H
#include "Player.h"
#include "Point.h"
#include "../include/ColorEnum.h"
#include "BoardScanner.h"
using namespace std;

//The class Client heirs from the class Player
class Client: public Player{
 public:
  //constructor
  Client(const char* serverIP, int serverPort);
  //The method connect to the server and determent the color of the player
  Color connectToServer();
  //Sending the server the players move
  void sendSocket(int xPos, int yPos);
  //Reading a message from the server
  Point readSocket();
  // The method get a Board and return the point
  Point playTurn(Board *board);
  //the method pass the turn of the player
  Point passTurn();

 private:
  const char *serverIP;
  int serverPort;
  int clientSocket;
};
#endif //REVERSI_CLIENT_H
