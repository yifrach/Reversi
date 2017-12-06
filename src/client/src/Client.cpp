//
// Created by yarin on 12/4/17.
//
#include"../include/Client.h"
#include "../include/ConvertString.h"
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>

Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP), serverPort(serverPort), clientSocket(0) {}

Color Client::connectToServer() {
  // Create a socket point
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    throw "Error opening socket";
  }
  // Convert the ip string to a network address
  struct in_addr address;
  if (!inet_aton(serverIP, &address)) {
    throw "Can't parse IP address";
  }
  // Get ahostentstructureforthegivenhost address
  struct hostent *server;
  server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
  if (server == NULL) {
    throw "Host is unreachable";
  }
  // Create a structure for the server address
  struct sockaddr_in serverAddress;
  bzero((char *) &address, sizeof(address));

  serverAddress.sin_family = AF_INET;
  memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
  //htons converts values between host and network byte orders
  serverAddress.sin_port = htons(serverPort);

  // Establish a connection with the TCP server
  if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
    throw "Error connecting to server";
  }
  cout << "Connected to server... " << endl;

  char value;
  int n = read(clientSocket, &value, sizeof(value));

  if (n < 0) {
    throw "Error reading player number";
  }

  if (value == '1') {
    cout << "Waiting for other player to join..." << endl;
    return black;
  } else {
    return white;
  }
}

void Client::sendSocketPoint(int arg1, int arg2) {
  ConvertString convert;
  const char *str = convert.convertInt(arg1, arg2);
  // Write the exercise arguments to the socket
  int n = write(clientSocket, &str, sizeof(str));
  if (n == -1) {
    throw "Error writing arg1 to socket";
  }
}

void Client::sendSocketNoMove(char *str) {
  // Write the exercise arguments to the socket
  int n = write(clientSocket, &str, sizeof(str));
  if (n == -1) {
    throw "Error writing arg1 to socket";
  }
}
//**************************************8*//
Point Client::readSocket() {
  // Read the result from the server
  char buffer[200];
  int n = read(clientSocket, buffer, sizeof(buffer));
  if (n == -1) {
    throw "Error reading result from socket";
  }

  ConvertString convert;
  Point p = convert.convertInput(buffer);

  memset(buffer, '\0', sizeof(buffer));
  return p;
}