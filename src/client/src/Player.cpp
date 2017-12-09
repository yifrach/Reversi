#include "../include/Player.h"
#include "../include/ColorEnum.h"

Player::Player() : score(0), color(black) {}

// Printing the players color
void Player::print() {
  if (color == white) {
    cout << "O";
  } else {
    cout << "X";
  }
}

// Getter for our players score
int Player::getScore() {
  return score;
}

// Updating our players score to updatedScore
void Player::updateScore(int updatedScore) {
  score = updatedScore;
}

// Getter for our players color
int Player::getColor() {
  return color;
}

// Setter for our players color
void Player::setColor(int newColor) {
  color = newColor;
}

int Player::getOpponentColor() {
  if (color == white) {
    return black;
  } else {
    return white;
  }
}