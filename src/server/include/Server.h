#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <map>
#include <string>
#include <vector>
using namespace std;

struct lobbyRoom {
  int clientSocket1;
  int clientSocket2;
  bool gameInProgress;
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
  ~Server();
  void initialize();
  void shutDown();
  int port;
  int serverSocket; // the socket's file descriptor
  map<string, lobbyRoom> lobbyMap;
  pthread_t mainThread;
  vector<pthread_t> threadVector;
  bool stopServer;

};
#endif //SERVER_SERVER_H
