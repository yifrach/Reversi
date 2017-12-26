#include "../include/ClientHandler.h"
#include "../include/ConverString.h"
#include "../include/CommandsManager.h"
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#define BUFFER_SIZE 4096

ClientHandler::ClientHandler(roomInfo *info) : info(info) {}

void ClientHandler::handle() {
  cout << "Now Handling socket number " << info->clientSocket << endl;
  char buffer[BUFFER_SIZE];
  // Read players message
  int readBytes = read(info->clientSocket, buffer, sizeof(buffer));
  if (readBytes < 0) {
    cout << "Error reading string" << endl;
  }
  // In case of disconnection
  if (readBytes == 0) {
    cout << "Client disconnected" << endl;
  }

  cout << "Got command " << buffer << endl;

  // Split our buffer with space
  ConvertString bufferConverter;
  string args;
  string command = bufferConverter.convertInput(buffer, &args);
  // Creating a commands manager
  CommandsManager manager;
  // Sending him our command, args and room information
  manager.executeCommand(command, args, info);
}
