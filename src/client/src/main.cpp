#include <iostream>
#include "../include/Game.h"

using namespace std;

/**
 * Main function for running our game
 * @return - an Integer in the end of the run
 */
int main() {
  Game game;
  // Initializing it and playing
  game.initialize();
  game.playGame();
  return 0;
}
