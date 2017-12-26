#include <cstring>
#include <iostream>
#include "../include/ListCommand.h"
#include<sys/socket.h>
#include<unistd.h>

ListCommand::ListCommand() {}

void ListCommand::execute(string args, roomInfo *info) {
  // Going over all of our lobby rooms
  map<string, lobbyRoom>::iterator it;
  string lobbyRommList("List of rooms that are availble:\n\n");
  for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
    // Chaining together a string of the rooms names
    lobbyRommList += "Room name:  " + it->first + "\n";
  }
  // Sending the room names strings to the user
  char *str;
  strcpy(str, lobbyRommList.c_str());
  int n = write(info->clientSocket, str, strlen(str));
  if (n < 0) {
    throw "Error writing to socket";
  }
  // Lastly closing the users socket forcing him to reconnect
  close(info->clientSocket);
  delete[] str;
}