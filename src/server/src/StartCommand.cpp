#include <cstring>
#include <iostream>
#include "../include/StartCommand.h"
#include<sys/socket.h>
#include<unistd.h>

pthread_mutex_t count_mutexStart;

StartCommand::StartCommand() {}

void StartCommand::execute(string args, roomInfo *info) {
  // Going over our lobby rooms
  map<string, lobbyRoom>::iterator it;
  for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
    // If the room already exists
    if (strcmp(it->first.c_str(), args.c_str()) == 0) {
      // We'll inform the user
      string message("NoRoom");
      char *str;
      strcpy(str, message.c_str());
      // Sending the user the message
      int n = write(info->clientSocket, str, strlen(str));
      if (n < 0) {
        throw "Error writing to socket";
      }
      delete[] str;
      // Lastly killing the thread and closing the users socket
      close(info->clientSocket);
      return;
    }
  }
  // Otherwise opening a new room
  lobbyRoom newRoom;
  newRoom.clientSocket1 = info->clientSocket;
  pthread_mutex_lock(&count_mutexStart);
  (*info->lobbyMap)[args] = newRoom;
  pthread_mutex_unlock(&count_mutexStart);
}