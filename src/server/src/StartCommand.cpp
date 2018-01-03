#include <cstring>
#include <iostream>
#include "../include/StartCommand.h"
#include<sys/socket.h>
#include<unistd.h>


StartCommand::StartCommand() {
  pthread_mutex_init(&count_mutex_lobby, NULL);
}

void StartCommand::execute(string args, roomInfo *info) {
  cout << "Inside Start command\n";
  // Going over our lobby rooms
  map<string, lobbyRoom>::iterator it;
  for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
    // If the room already exists
    if (strcmp(it->first.c_str(), args.c_str()) == 0) {
      // We'll inform the user
      char error = '0';
      // Sending the user the message
      long n = write(info->clientSocket, &error, sizeof(error));
      if (n < 0) {
        throw "Error writing to socket";
      }
      // Lastly closing the users socket killing our thread
      close(info->clientSocket);
      return;
    }
  }
  // Otherwise opening a new room
  lobbyRoom newRoom = {};
  newRoom.clientSocket1 = info->clientSocket;
  newRoom.gameInProgress = false;
  pthread_mutex_lock(&count_mutex_lobby);
  (*info->lobbyMap)[args] = newRoom;
  pthread_mutex_unlock(&count_mutex_lobby);
  // Notifying the user we've opened a room for him and that he is player 1
  char str = '1';
  long n = write(info->clientSocket, &str, sizeof(str));
  if (n < 0) {
    throw "Error writing to socket";
  }
}