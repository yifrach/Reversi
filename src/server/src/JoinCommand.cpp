//
// Created by yarin on 12/22/17.
//

#include <cstring>
#include <iostream>
#include "../include/JoinCommand.h"
#include<sys/socket.h>
#include<unistd.h>

pthread_mutex_t count_mutexJoin;

JoinCommand::JoinCommand() {}

void JoinCommand::execute(string args, roomInfo* info) {
  map<string, lobbyRoom>::iterator it;
  for (it = info->lobbyMap.begin(); it != info->lobbyMap.end(); it++) {
    if(strcmp(args.c_str(), it->first.c_str())==0) {
      pthread_mutex_lock(&count_mutexJoin);
      it->second.clientSocket2 = info->clientSocket;
      pthread_mutex_unlock(&count_mutexJoin);
      return;
    }
  }
  string message("NoRoom");
  const char *strConst=message.c_str();
  char *str;
  strcpy(str, strConst);
  // Writing the move or NoMove to the server
  int n = write(info->clientSocket, str, strlen(str));
  if (n < 0) {
    throw "Error writing to socket";
  }
  delete[] str;
  delete[] strConst;
}