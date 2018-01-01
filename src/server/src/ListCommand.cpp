#include <cstring>
#include <iostream>
#include "../include/ListCommand.h"
#include<sys/socket.h>
#include<unistd.h>

ListCommand::ListCommand() {}

void ListCommand::execute(string args, roomInfo *info) {
  cout << "Inside List command\n";
  string lobbyRoomList("List of rooms that are availble:\n");
  char error = '0';
  int counter = 0;
  // We'll go over our lobby rooms
  map<string, lobbyRoom>::iterator it;
  for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
    // Chaining together a string of the rooms names if theyre not playing
    if (!it->second.gameInProgress) {
      lobbyRoomList += "Room name: " + it->first + "\n";
      // Updating our counter
      counter++;
    }
  }
  if (counter != 0) {
    // Sending the room names strings to the user
    char *str = new char[lobbyRoomList.size()];
    strcpy(str, lobbyRoomList.c_str());
    long n = write(info->clientSocket, str, strlen(str));
    if (n < 0) {
      throw "Error writing to socket";
    }
    delete str;
  } else {
    long n = write(info->clientSocket, &error, sizeof(error));
    if (n < 0) {
      throw "Error writing to socket";
    }
  }
  // Lastly closing the users socket forcing him to reconnect
  close(info->clientSocket);
}