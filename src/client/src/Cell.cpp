#include "../include/Cell.h"
enum Color { empty = -1, white, black };

/**
 * Our color constructor, initalzing it as an empty cell
 */
Cell::Cell() : color(empty) {
}

Cell::Cell(const Cell &oldCell) {
  color = oldCell.color;
}
/**
 * Getter for our cells color
 * @return - the cells color
 */
int Cell::getColor() {
  return color;
}

/**
 * Print the cells color
 */
void Cell::print() {
  if (color == black) {
    cout << "X";
  } else if (color == white) {
    cout << "O";
  } else {
    cout << " ";
  }
}

/**
 * Change the cells color to the desired color
 * @param color - the desired color
 */
void Cell::changeColor(int color) {
  this->color = color;
}

/**
 * Flip the cells disk based on its color
 */
void Cell::flip() {
  if (color == black) {
    this->color = white;
  } else if (color == white) {
    this->color = black;
  }
}

/**
 * Getter for the cells disk opposite color
 * @return - the disks opposite color
 */
int Cell::getFlip() {
  if (color == black) {
    return white;
  } else if (color == white) {
    return black;
  } else {
    return empty;
  }
}


