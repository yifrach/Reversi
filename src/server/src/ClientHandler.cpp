#include "../include/ClientHandler.h"
#include "../include/ConverString.h"
#include "../include/CommandsManager.h"
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
using namespace std;
#define BUFFER_SIZE 4096

ClientHandler::ClientHandler(roomInfo *info) : info(info) {}

void ClientHandler::handle() {
  char buffer[BUFFER_SIZE];
  cout << "Now Handling socket number " << info->clientSocket << endl;
  // Read players message
  long readBytes = read(info->clientSocket, buffer, sizeof(buffer));
  if (readBytes < 0) {
    cout << "Error reading string!!!" << endl;
    pthread_exit(NULL);
  }
  // In case of disconnection
  if (readBytes == 0) {
    cout << "Client disconnected" << endl;
    pthread_exit(NULL);
  }
  cout << "Got command " << buffer << endl;
  // Split our buffer with space
  ConvertString bufferConverter;
  string args;
  string command = bufferConverter.convertInput(buffer, &args);
  // Creating a commands manager
  CommandsManager manager;
  // Sending him our command, args and room information
  try {
    manager.executeCommand(command, args, info);
    // Catching any throws the commmand might have thrown
  } catch (const char* msg) {
    cout << "Cannot continue with server. Reason: " << msg << endl;
  }
}

ClientHandler::~ClientHandler() {
  delete info;
}
