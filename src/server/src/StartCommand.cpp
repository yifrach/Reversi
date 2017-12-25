//
// Created by yarin on 12/22/17.
//

#include <cstring>
#include <iostream>
#include "../include/StartCommand.h"
#include<sys/socket.h>
#include<unistd.h>

pthread_mutex_t count_mutex;

StartCommand::StartCommand() {}

void StartCommand::execute(string args, roomInfo* info) {
  map<string, lobbyRoom>::iterator it;
  for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
    if(strcmp(it->first.c_str(),args.c_str())==0) {
      string message ("NoRoom");
      const char *strConst=message.c_str();
      char *str;
      strcpy(str, strConst);
      // Writing the move or NoMove to the server
      int n = write(info->socket, str, strlen(str));
      if (n < 0) {
        throw "Error writing to socket";
      }
      delete[] str;
      delete[] strConst;
      return;
    }
  }
  lobbyRoom newRoom;
  newRoom.clientSocket1=info->socket;
  pthread_mutex_lock(&count_mutex);
  (*info->lobbyMap)[args]=newRoom;
  pthread_mutex_unlock(&count_mutex);
}