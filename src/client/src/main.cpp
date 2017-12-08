#include <iostream>
#include "../include/Game.h"

using namespace std;

// Main function for running our game
int main() {
  // Creating our game
  Game game;
  // Initializing it and playing
  game.initialize();
  game.playGame();
  return 0;
}
