#include <iostream>
#include "../include/Game.h"

using namespace std;

/**
 * The main function that runs our game
 * @return - an Integer when the program is done.
 */
int main() {
  //Creating our game
  Game game;
  //Initializing it and playing
  game.initialize();
  //play the game
  game.playGame();
  return 0;
}
