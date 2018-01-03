#include <cstring>
#include <iostream>
#include "../include/JoinCommand.h"
#include<sys/socket.h>
#include "../include/PlayGame.h"
#include<unistd.h>
void *playGame(void *information);

JoinCommand::JoinCommand() {
  pthread_mutex_init(&count_mutex_lobby,  NULL);
}

void JoinCommand::execute(string args, roomInfo *info) {
  cout << "Inside Join command\n";
  // Going over our lobby rooms
  map<string, lobbyRoom>::iterator it;
  for (it = info->lobbyMap->begin(); it != info->lobbyMap->end(); it++) {
    // If the room exists
    if ((strcmp(args.c_str(), it->first.c_str()) == 0) && (!it->second.gameInProgress)) {
      // We'll put the players socket in the room information
      pthread_mutex_lock(&count_mutex_lobby);
      it->second.clientSocket2 = info->clientSocket;
      it->second.gameInProgress = true;
      pthread_mutex_unlock(&count_mutex_lobby);
      // Updating our users information room name
      info->roomName = args;
      // Creating a new thread to play the game in
      pthread_t playGameThread;
      int n = pthread_create(&playGameThread, NULL, playGame, info);
      pthread_mutex_lock(&count_mutex_vector);
      info->threadVector.push_back(playGameThread);
      pthread_mutex_unlock(&count_mutex_vector);
      if (n) {
        throw "Error creating client accept thread";
      }
      // Ending our current thread
      return;
    }
  }
  // Otherwise informing the user the room does not exist
  char error = '0';
  // Writing the move or NoMove to the server
  long n = write(info->clientSocket, &error, sizeof(error));
  if (n < 0) {
    throw "Error writing to socket";
  }
  // Lastly closing his socket forcing him to reconnect
  close(info->clientSocket);
}


void *playGame(void *information) {
  PlayGame game((roomInfo *) information);
  game.play();
}
