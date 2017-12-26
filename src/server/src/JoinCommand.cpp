#include <cstring>
#include <iostream>
#include "../include/JoinCommand.h"
#include<sys/socket.h>
#include "../include/PlayGame.h"
#include<unistd.h>
void *playGame(void *roomName);
pthread_mutex_t count_mutexJoin;

JoinCommand::JoinCommand() {}

void JoinCommand::execute(string args, roomInfo *info) {
  cout << "Inside Join command\n";
  // Going over our lobby rooms
  map<string, lobbyRoom>::iterator it;
  for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
    // If the room exists
    if (strcmp(args.c_str(), it->first.c_str()) == 0) {
      // We'll put the players socket in the room information
      pthread_mutex_lock(&count_mutexJoin);
      it->second.clientSocket2 = info->clientSocket;
      pthread_mutex_unlock(&count_mutexJoin);
      // Notifying the user the game is about to start and he is player 2
      char str = '2';
      int n = write(info->clientSocket, &str, 1);
      if (n < 0) {
        throw "Error writing to socket";
      }
      // Creating a new thread to play the game in
      pthread_t playGameThread;
      n = pthread_create(&playGameThread, NULL, playGame, &info);
      if (n) {
        throw "Error creating client accept thread";
      }
      // Exiting this thread
      return;
    }
  }
  // Otherwise informing the user the room does not exist
  string message("NoRoom");
  char *str;
  strcpy(str, message.c_str());
  // Writing the move or NoMove to the server
  int n = write(info->clientSocket, str, strlen(str));
  if (n < 0) {
    throw "Error writing to socket";
  }
  // Lastly closing his socket forcing him to reconnect
  close(info->clientSocket);
  delete[] str;
}

void *playGame(void *information) {
  PlayGame *game = new PlayGame((roomInfo *) information);
  game->play();
  delete game;
}
