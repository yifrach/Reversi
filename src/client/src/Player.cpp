#include "../include/Player.h"
#include "../include/ColorEnum.h"

/**
 * The constructor of the class
 */
Player::Player() : score(0), color(black) {}

/**
 * Printing the players color
 */
void Player::print() {
  if (color == white) {
    cout << "O";
  } else {
    cout << "X";
  }
}

/**
 * Getter for our players score
 * @return - an Integer  that represent the color of the player
 */
int Player::getScore() {
  return score;
}

/**
 * Updating our players score to updatedScore
 * @param updatedScore - an Integer that repersent the update score
 */
void Player::updateScore(int updatedScore) {
  score = updatedScore;
}

/**
 * Getter for our players color
 * @return - an Integer that represent the color of the player
 */
int Player::getColor() {
  return color;
}

/**
 * Setter for our players color
 * @param newColor - an Integer that represent the new color of the player
 */
void Player::setColor(int newColor) {
  color = newColor;
}