#include "../include/Server.h"
#include "../include/ClientHandler.h"
#include "../include/Command.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;
#define MAX_CONNECTED_CLIENTS 50
void *acceptClient(void *obj);
void *handleClient(void *information);

Server::Server(int port) : port(port), serverSocket(0) {
  cout << "Opened the server with port: " << port << "!\n";
  stopServer = false;
}

void Server::initialize() {
  cout << "Type \"Exit\" at any time to close the server!\n\n";
  // Create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  // Create our main thread for accepting clients
  pthread_t mainThread;
  int n = pthread_create(&mainThread, NULL, acceptClient, this);
  // Saving our main thread so we'll close it first later
  this->mainThread = mainThread;
  if (n) {
    throw "Error creating client accept thread";
  }
  // Wait for the users exit command
  string exitCommand;
  cin >> exitCommand;
  do {
    // Stop the server if told so
    if (strcmp(exitCommand.c_str(), "Exit") == 0) {
      stopServer = true;
    } else {
      // Else flushing our buffer
      cout << "Sorry, im only familiar with the command \"Exit\"" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> exitCommand;
    }
  } while (!stopServer);
  this->shutDown();
}

// Shutting down our server notifying all clients
void Server::shutDown() {
  long n;
  char exit[10];
  memset(exit, '\0', sizeof(exit));
  strcpy(exit, "Exit");
  // Notifying all clients the server is shutting down
  map<string, lobbyRoom>::iterator it;
  for (it = lobbyMap.begin(); it != lobbyMap.end(); it++) {
    n = write(it->second.clientSocket1, exit, sizeof(exit));
    if (n < 0) {
      cout << "Error writing to socket";
    }
    // If the room is full we'll notify the second player too
    if (it->second.gameInProgress) {
      n = write(it->second.clientSocket2, exit, sizeof(exit));
      if (n < 0) {
        cout << "Error writing to socket";
      }
    }
    // Lastly closing both sockets
    close(it->second.clientSocket1);
    close(it->second.clientSocket2);
  }
  // Closing our main thread so we wont accept clients
  pthread_cancel(mainThread);
  pthread_join(mainThread, NULL);
  // Lastly closing all of our pthreads
  for (int i = 0; i < threadVector.size(); i++) {
    pthread_cancel(threadVector[i]);
    pthread_join(threadVector[i], NULL);

  }
}

// Our main thread for accepting clients and passing them to a new thread to handle
void *acceptClient(void *obj) {
  try {

    int i = 1;
    cout << "Created the accept thread!" << endl;
    Server *server = (Server *) obj;
    int port = server->port;
    int serverSocket = server->serverSocket;
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
    // Start accepting clients and handling them while server is running
    while (true) {
      cout << "From acceptThread: Waiting for client connections..." << endl;
      // Accept a new clients connection
      int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
      if (clientSocket < 0) {
        throw "Error on accept";
      }
      cout << "Client " << i << " is connected" << endl;
      // Creating a new thread to handle our client
      pthread_t handleThread;
      i++;
      // initalzing our clients lobby room information
      roomInfo *info = new roomInfo;
      info->lobbyMap = &(server->lobbyMap);
      info->clientSocket = clientSocket;
      info->threadVector = server->threadVector;

      // Lastly opening the thread with the clients room information
      int n = pthread_create(&handleThread, NULL, handleClient, info);
      pthread_mutex_lock(&count_mutex_vector);
      server->threadVector.push_back(handleThread);
      pthread_mutex_unlock(&count_mutex_vector);

      if (n) {
        throw "Error creating handling thread";
      }
    }
    // Catching our bind, listen, accept throws within the thread
  } catch (const char* msg) {
    cout << "Cannot continue with server. Reason: " << msg << endl;
  }
}

// Our thread for handling each incoming client
void *handleClient(void *information) {
  // Our handler will be deleted in the stack
  ClientHandler handler((roomInfo *) information);
  handler.handle();
}

Server::~Server() {
  lobbyMap.clear();
  threadVector.clear();

}