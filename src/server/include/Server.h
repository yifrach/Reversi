#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

class Server {
 public:
  Server(int port);
  void start();

 private:
  int port;
  int serverSocket; // the socket's file descriptor
  bool playGame; // bool for whether or not to continue playing
  void handleClient(int activePlayer, int recivePlayer);
};

#endif //SERVER_SERVER_H
