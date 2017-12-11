#include "../include/Cell.h"
#include "../include/ColorEnum.h"

/**
 * Initalzing it as an empty cell as default
 */
Cell::Cell() : color(empty) {
}

/**
 * Copy constructor for our cell
 * @param oldCell - a Cell that we do deep copy for
 */
Cell::Cell(const Cell &oldCell) {
  color = oldCell.color;
}

/**
 * Getter for our cells color
 * @return - an Integer that represent the color og the cell
 */
int Cell::getColor() {
  return color;
}

/**
 * Print our cells color
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
 * Change the cells color to color
 * @param color - an Integer that represent the newColor
 */
void Cell::changeColor(int color) {
  this->color = color;
}

/**
 * Flip the cell disk - changing its color
 */
void Cell::flip() {
  if (color == black) {
    this->color = white;
  } else if (color == white) {
    this->color = black;
  }
}

/**
 * Getter for our cells opposite color
 * @return - an Integer that represent the opposit color
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


