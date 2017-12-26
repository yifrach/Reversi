#include "../include/PlayGame.h"
#include "../include/Server.h"
#include "../include/ConverString.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#define BUFFER_SIZE 4096

PlayGame::PlayGame(roomInfo* info) : info(info) {
  playGame = true;
}

void PlayGame::play() {
  cout << "Starting game: " << info->roomName << endl;
  // Get each players socket
  int socket1 = info->lobbyMap->at(info->roomName).clientSocket1;
  int socket2 = info->lobbyMap->at(info->roomName).clientSocket2;
  while (playGame) {
    // Passing messages from player 1 to player 2
    passMessage(socket1, socket2);
    if (playGame) {
      // Passing messages from player 2 to player 1
      passMessage(socket2, socket1);
    }
  }
  // Lastly closing their socket
  close(socket1);
  close(socket2);
}

void PlayGame::passMessage(int activePlayer, int recivePlayer) {
  char buffer[BUFFER_SIZE];
  // Read players message
  int readBytes = read(activePlayer, buffer, sizeof(buffer));
  if (readBytes < 0) {
    cout << "Error reading string" << endl;
    return;
  }
  // Incase of disconnection
  if (readBytes == 0) {
    cout << "Client disconnected" << endl;
    // Stopping the game
    playGame = false;
    return;
  }
  cout << "Got string: " << buffer << endl;
  // If the game has ended we'll inform the server handling loop
  if (strcmp(buffer, "End") == 0) {
    playGame = false;
    return;
  }
  // Write the result back to the receiving player
  int sendBytes = write(recivePlayer, buffer, sizeof(buffer));
  if (sendBytes < 0) {
    cout << "Error writing to socket" << endl;
    return;
  }
  cout << "Sent string: " << buffer << endl;
  // Lastly flushing our buffer
  memset(buffer, '\0', sizeof(buffer));
}