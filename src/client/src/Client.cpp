#include"../include/Client.h"
#include "../include/ConvertString.h"
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include <limits>
#include <cstdlib>
#include "../include/BoardScanner.h"
#define BUFFER_SIZE 4096
#define NO_MOVE -1



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
  // Get a hostent structure for the given host address
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
  if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
    throw "Error connecting to server";
  }
  cout << "Connected to server... " << endl;
  // Getting our players color from the server
  char value;
  int n = read(clientSocket, &value, sizeof(value));
  if (n < 0) {
    throw "Error reading player number";
  }
  // If the player is the first player
  if (value == '1') {
    cout << "You are player X" << endl;
    cout << "Waiting for other player to join..." << endl;
    // We'll wait for another server message the other player is ready
    int n = read(clientSocket, &value, sizeof(value));
    if (n < 0) {
      throw "Error reading player number";
    }
    // Lastly returning the players color
    return black;
  } else {
    cout << "You are player O" << endl;
    return white;
  }
}

// Sending the server the players move
void Client::sendSocket(int xPos, int yPos) {
  // First converting out point to a char array o
  // If the point is a fake point conversion will take care it
  ConvertString convert;
  char* str = convert.convertInt(xPos, yPos);
  // Writing the move or NoMove to the server
  int n = write(clientSocket, str, strlen(str));
  if (n < 0) {
    throw "Error writing to socket";
  }
  //REMEMBER YOURE DELETING BECAUSE ITS A NEW STR
  delete str;
}

// Reading a message from the server
Point Client::readSocket() {
  char buffer[BUFFER_SIZE];
  int n = read(clientSocket, buffer, sizeof(buffer));
  if (n < 0) {
    throw "Error reading from socket";
  }
  // Converting our message
  ConvertString convert;
  Point p = convert.convertInput(buffer);
  // Lastly flushing our buffer
  memset(buffer, '\0', sizeof(buffer));
  return p;
}

Point Client::playTurn(Board *board) {
  int row, col;
  BoardScanner* scanner=new BoardScanner(board);
  scanner->scanBoard(getColor());
  // We'll print them to the screen asking for an input
  scanner->printMoves();
  cout << "Please enter your move row, col:";
  cin >> row >> col;
  //checking the input is indeed correct
  if (!scanner->isValidMove(row, col) || cin.fail()) {
    do {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Bad input, please try again: ";
      cin >> row >> col;
    } while (!scanner->isValidMove(row, col) || cin.fail());
  }
  //************try and catch************//
  try {
    sendSocket(row, col);
  } catch (const char *msg) {
    cout << "Failed to connect to server. Reason:" << msg << endl;
    exit(-1);
  }
  scanner->freeMovesList();
  return Point(row,col);
}

Point Client::passTurn() {
  // If the player has no moves we'll inform him passing the turn back
  cout << "No possible moves! Play passes back to the other player.\n\n";
  try {
    sendSocket(NO_MOVE, NO_MOVE);
  } catch (const char *msg) {
    cout << "Failed to connect to server. Reason:" << msg << endl;
    exit(-1);
  }
}