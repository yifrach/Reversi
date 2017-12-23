#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <iostream>
using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define BUFFER_SIZE 4096
bool serverWorks = true;

Server::Server(int port) : port(port), serverSocket(0)  {
  cout << "Server Port: " << port << endl;
}

void Server::initialize() {
  // Create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  pthread_t acceptThread;
  int n = pthread_create(&acceptThread, NULL, acceptClient, NULL);
  if (n) {
    throw "Error creating client accept thread";
  }
  // WAIT FOR AN EXIT MESSAGE HERE AND UPDATE ALL THREADS APPROPRIATLY
}

void *Server::acceptClient() {
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
  struct sockaddr_in clientAddress;
  socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress);
  // Start accepting clients and handling them
  while (serverWorks) {
    cout << "Waiting for client connections..." << endl;
    // Accept a new clients connection
    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
    if (clientSocket < 0) {
      throw "Error on accept";
    }
    cout << "Client is connected" << endl;
    // Sending him to our new thread to handle
    pthread_t handleThread;
    int n = pthread_create(&handleThread, NULL, handleClient, (void *) clientSocket);
    if (n) {
      throw "Error creating handling thread";
    }
    // Lastly closing his socket
    close(clientSocket);
  }
}

// Handle requests from a specific client
void *Server::handleClient(void *socket) {
  int clientSocket = (int) socket;
  char buffer[BUFFER_SIZE];
  // Read players message
  int readBytes = read(clientSocket, buffer, sizeof(buffer));
  if (readBytes < 0) {
    cout << "Error reading string" << endl;
  }
  // In case of disconnection
  if (readBytes == 0) {
    cout << "Client disconnected" << endl;
  }
  //CREATE A COMMAND MANAGER
  //EXECUTE THE COMMAND JOIN OR START APPROPRIATLY

  memset(buffer, '\0', sizeof(buffer));
}
