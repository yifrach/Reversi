#ifndef SERVER_PLAYGAME_H
#define SERVER_PLAYGAME_H
#include <string>
#include <map>
#include "Command.h"
#include "Server.h"
using namespace std;

class PlayGame {
 public:
  PlayGame(roomInfo info);
  void play();

 private:
  roomInfo info;
  bool playGame;
  void passMessage(int clientSocket1, int clientSocket2);
};

#endif //SERVER_PLAYGAME_H
