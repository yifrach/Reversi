#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

class Server {
 public:
  Server(int port);
  void start();
  void stop();
 private:
  int port;
  int serverSocket; // the socket's file descriptor
  void handleClient(int activePlayer, int recivePlayer, bool &playGame);
};

#endif //SERVER_SERVER_H
