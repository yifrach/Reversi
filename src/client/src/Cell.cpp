#include "../include/Cell.h"
#include "../include/ColorEnum.h"

// Initalzing it as an empty cell as default
Cell::Cell() : color(empty) {
}

// Copy constructor for our cell
Cell::Cell(const Cell &oldCell) {
  color = oldCell.color;
}

// Getter for our cells color
int Cell::getColor() {
  return color;
}

// Print our cells color
void Cell::print() {
  if (color == black) {
    cout << "X";
  } else if (color == white) {
    cout << "O";
  } else {
    cout << " ";
  }
}

// Change the cells color to color
void Cell::changeColor(int color) {
  this->color = color;
}

// Flip the cells disk changing its color
void Cell::flip() {
  if (color == black) {
    this->color = white;
  } else if (color == white) {
    this->color = black;
  }
}

// Getter for our cells opposite color
int Cell::getFlip() {
  if (color == black) {
    return white;
  } else if (color == white) {
    return black;
  } else {
    return empty;
  }
}


