//
// Created by yarin on 12/5/17.
//

#include "../include/Player.h"


Player::Player() : score(0), color(black) {}

Player::~Player() {}

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
 * @return - the players score
 */
int Player::getScore() {
  return score;
}

/**
 * Updating the players score accoring to the board
 * @param updatedScore - the players new score
 */
void Player::updateScore(int updatedScore) {
  score = updatedScore;
}

/**
 * Getter for the players color
 * @return - the players color
 */
int Player::getColor() {
  return color;
}

/**
 * The method get a color and set is value in the member color
 * @param newColor - an Integer that represent the new color value of the member
 */
void Player::setColor(int newColor) {
  color = newColor;
}