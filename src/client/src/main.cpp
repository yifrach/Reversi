#include <iostream>
#include "../include/Game.h"
#include "../include/FileReader.h"

using namespace std;

// Main function for running our game
int main() {
  FileReader fileReader("/home/uri/CLionProjects/cpp/Reversi/src/client/client_config.txt");
  int* port;
  char* ip = fileReader.readConfigFile();
  cout << ip << endl;
  cout << port << endl;
//  // Creating our game
//  Game game;
//  // Initializing it and playing
//  game.initialize();
//  game.playGame();
  return 0;
}
