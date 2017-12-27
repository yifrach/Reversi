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
pthread_mutex_t count_mutexPlay;


PlayGame::PlayGame(roomInfo info) : info(info) {
  playGame = true;
}

void PlayGame::play() {
  cout << "Starting game: " << info.roomName << endl;
  // Get each players socket
  int socket1 = info.lobbyMap->at(info.roomName).clientSocket1;
  int socket2 = info.lobbyMap->at(info.roomName).clientSocket2;

  // FIND DIFFERENT WAY TO DELETE ROOM SO WE CAN SEND IT EXIT!


  // Notify both players the game is starting
  char start = '2';
  int sendBytes = write(socket1, &start, 1);
  if (sendBytes < 0) {
    cout << "Error writing to socket" << endl;
    return;
  }
  int n = write(socket2, &start, 1);
  if (n < 0) {
    throw "Error writing to socket";
  }
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
  // Erasing the games lobby room
  pthread_mutex_lock(&count_mutexPlay);
  info.lobbyMap->erase(info.roomName);
  pthread_mutex_unlock(&count_mutexPlay);
  pthread_exit(NULL);
}

void PlayGame::passMessage(int activePlayer, int recivePlayer) {
  char buffer[BUFFER_SIZE];
  // Read players message
  int readBytes = read(activePlayer, buffer, sizeof(buffer));
  if (readBytes < 0) {
    cout << "Error reading string" << endl;
    playGame = false;
    return;
  }
  // Incase of disconnection
  if (readBytes == 0) {
    cout << "Client disconnected" << endl;
    // Stopping the game
    playGame = false;
    return;
  }
  cout << "In Room: " << info.roomName << ", Got string: " << buffer << endl;
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
  // Lastly flushing our buffer
  memset(buffer, '\0', sizeof(buffer));
}