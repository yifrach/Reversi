//
// Created by yarin on 12/22/17.
//
#include <cstring>
#include <iostream>
#include "../include/ListCommand.h"
#include<sys/socket.h>
#include<unistd.h>

ListCommand::ListCommand() {}

void ListCommand::execute(string args, roomInfo* info) {
  map<string, lobbyRoom>::iterator it;
  string lobbyRommList("List of rooms that are availble:\n\n");
  for (it = info->lobbyMap.begin(); it != info->lobbyMap.end(); it++) {
    lobbyRommList+="Room name:  "+it->first+"\n";
  }
  const char *strConst=lobbyRommList.c_str();
  char *str;
  strcpy(str, strConst);
  int n = write(info->clientSocket, str, strlen(str));
  if (n < 0) {
    throw "Error writing to socket";
  }
  delete[] str;
  delete[] strConst;
}