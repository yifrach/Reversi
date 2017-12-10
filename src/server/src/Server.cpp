#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define BUFFER_SIZE 4096

Server::Server(int port) : port(port), serverSocket(0), playGame(true) {
  cout << "Server Port: " << port << endl;
}

void Server::start() {
  // Create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  // Assign a local address to the socket
  struct sockaddr_in serverAddress;
  bzero((void *) &serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port);
  if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
    throw "Error on binding";
  }
  // Start listening to incoming connections
  listen(serverSocket, MAX_CONNECTED_CLIENTS);
  // Define the client socket's structures
  struct sockaddr_in clientAddress1;
  socklen_t clientAddressLen1 = sizeof((struct sockaddr*) &clientAddress1);
  struct sockaddr_in clientAddress2;
  socklen_t clientAddressLen2 = sizeof((struct sockaddr*) &clientAddress2);
  // Start accepting clients and passing messages
  while (true) {
    cout << "Waiting for client connections..." << endl;
    // Accept 2 new clients connection
    int clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress1, &clientAddressLen1);
    if (clientSocket1 < 0) {
      throw "Error on accept 1";
    }
    cout << "Client 1 is connected" << endl;
    // Sending the first client his player number letting him wait
    char playerNum = '1';
    int n = write(clientSocket1, &playerNum, sizeof(playerNum));
    if (n < 0) {
      cout << "Error writing to socket 1" << endl;
      return;
    }
    int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress2, &clientAddressLen2);
    if (clientSocket2 < 0) {
      throw "Error on accept 2";
    }
    cout << "Client 2 is connected" << endl;
    // Sending both clients a message the game is ready to start
    n = write(clientSocket1, &playerNum, sizeof(playerNum));
    if (n < 0) {
      cout << "Error writing to socket 1" << endl;
      return;
    }
    playerNum = '2';
    n = write(clientSocket2, &playerNum, sizeof(playerNum));
    if (n < 0) {
      cout << "Error writing to socket 2" << endl;
      return;
    }
    while (playGame) {
      // Passing messages from player 1 to player 2
      handleClient(clientSocket1, clientSocket2);
      if (playGame) {
        // Passing messages from player 2 to player 1
        handleClient(clientSocket2, clientSocket1);
      }
    }
    // Close communication with the client
    close(clientSocket1);
    close(clientSocket2);
    // And get ready for another game
    playGame = true;
  }
}

// Handle requests from a specific client
void Server::handleClient(int activePlayer, int recivePlayer) {
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