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
  // If the lobbyMap is not empty'
  if (!info->lobbyMap->empty()) {
    // We'll go over our lobby rooms
    map<string, lobbyRoom>::iterator it;
    for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
      // Chaining together a string of the rooms names
      lobbyRoomList += "\nRoom name: " + it->first + "\n";
    }
    lobbyRoomList += "\n";
    // Sending the room names strings to the user
    char *str = new char[lobbyRoomList.size()];
    strcpy(str, lobbyRoomList.c_str());
    int n = write(info->clientSocket, str, strlen(str));
    if (n < 0) {
      throw "Error writing to socket";
    }
    // Otherwise notifying the user the list is empty
  } else {
    int n = write(info->clientSocket, &error, 1);
    if (n < 0) {
      throw "Error writing to socket";
    }
  }
  // Lastly closing the users socket forcing him to reconnect
  //close(info->clientSocket);
  pthread_exit(NULL);
}