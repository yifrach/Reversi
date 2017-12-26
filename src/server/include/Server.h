#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

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

class Server {
 public:
  Server(int port);
  void initialize();
  int port;
  int serverSocket; // the socket's file descriptor
  map<string, lobbyRoom> lobbyMap;
  vector<pthread_t> threadVector;

};
#endif //SERVER_SERVER_H
