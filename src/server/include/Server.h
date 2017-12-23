#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <map>
#include <string>
using namespace std;

struct lobbyRoom {
  int clientSocket1;
  int clientSocket2;
  bool readyToPlayer = false;
};

class Server {
 public:
  Server(int port);
  void initialize();

 private:
  int port;
  int serverSocket; // the socket's file descriptor
  map<string, lobbyRoom> lobbyMap;
  void *handleClient(void *clientSocket);
  void *acceptClient();

};

#endif //SERVER_SERVER_H
