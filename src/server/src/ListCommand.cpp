#include <cstring>
#include <iostream>
#include "../include/ListCommand.h"
#include<sys/socket.h>
#include<unistd.h>

ListCommand::ListCommand() {}

void ListCommand::execute(string args, roomInfo *info) {
  string lobbyRoomList("List of rooms that are availble:\n");
  string isEmpty("NoRoom");
  cout << "Inside List command\n";
  // If the lobbyMap is not empty'
  if (!info->lobbyMap->empty()) {
    // We'll go over our lobby rooms
    map<string, lobbyRoom>::iterator it;
    for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
      // Chaining together a string of the rooms names
      lobbyRoomList += "Room name:  " + it->first + "\n";
    }
    // Sending the room names strings to the user
    char *str;
    strcpy(str, lobbyRoomList.c_str());
    int n = write(info->clientSocket, str, strlen(str));
    if (n < 0) {
      throw "Error writing to socket";
    }
    // Otherwise notifying the user the list is empty
  } else {
    char *str;
    strcpy(str, isEmpty.c_str());
    cout << str;
    int n = write(info->clientSocket, str, strlen(str));
    if (n < 0) {
      throw "Error writing to socket";
    }
  }
  // Lastly closing the users socket forcing him to reconnect
  //close(info->clientSocket);
}