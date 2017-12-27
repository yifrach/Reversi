#ifndef SERVER_GAMEDATA_H
#define SERVER_GAMEDATA_H

#include <map>
#include <string>
#include <vector>
using namespace std;

struct lobbyRoom {
  int clientSocket1;
  int clientSocket2;
};

struct roomInfo {
  int clientSocket;
  string roomName;
  map<string, lobbyRoom>* lobbyMap;
  vector<pthread_t> threadVector;
};

class GameData {
 public:
  static GameData *instance();
  map<string, lobbyRoom> lobbyMap;
  vector<pthread_t> threadVector;

 private:
  GameData();
};

#endif //SERVER_GAMEDATA_H
