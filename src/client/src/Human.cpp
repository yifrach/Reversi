#include "../include/Human.h"
enum Color { white, black };

Human::Human() : score(0), color(black) {}

Human::~Human() {}

/**
 * Printing the players color
 */
void Human::print() {
  if (color == white) {
    cout << "O";
  } else {
    cout << "X";
  }
}

/**
 * Getter for our players score
 * @return - the players score
 */
int Human::getScore() {
  return score;
}

/**
 * Updating the players score accoring to the board
 * @param updatedScore - the players new score
 */
void Human::updateScore(int updatedScore) {
  score = updatedScore;
}

/**
 * Getter for the players color
 * @return - the players color
 */
int Human::getColor() {
  return color;
}

/**
 * The method get a color and set is value in the member color
 * @param newColor - an Integer that represent the new color value of the member
 */
void Human::setColor(int newColor) {
  color = newColor;
}

/**
 * The method get a Board and calculate his most smart move and return its move
 * @param board - a variable from type Board
 * @return - a Point that represent the player move
 */
Point Human::playTurn(Board *board) {}