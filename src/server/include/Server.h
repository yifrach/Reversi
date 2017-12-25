#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <map>
#include <string>
using namespace std;

struct lobbyRoom {
  int clientSocket1;
  int clientSocket2;
};

struct roomInfo {
  map<string, lobbyRoom>* lobbyMap;
  int socket;
  string roomName;
};

class Server {
 public:
  Server(int port);
  void initialize();

  friend class JoinCommand;
  friend class StartCommand;

 private:
  int port;
  int serverSocket; // the socket's file descriptor
  map<string, lobbyRoom> lobbyMap;
  void *handleClient(void *clientSocket);
  void *acceptClient();

};

#endif //SERVER_SERVER_H
