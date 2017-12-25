#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H
#include "Server.h"

class ClientHandler {
 public:
  ClientHandler(roomInfo* info);
  void handle();

 private:
  roomInfo* info;
};

#endif //SERVER_CLIENTHANDLER_H
