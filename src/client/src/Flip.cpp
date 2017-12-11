#include "../include/Flip.h"

/**
 * The constructor of the class
 * @param newBoard - a Board
 */
Flip::Flip(Board *newBoard) : board(newBoard), wall(board->getSize()) {}

/**
 * Flip the board given the disks position and color using 8 sub functions
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipBoard(int row, int col, int color) {
  if (row != 1) {
    flipUp(row - 1, col, color);
  }
  if (row != wall) {
    flipDown(row + 1, col, color);
  }
  if (col != 1) {
    flipLeft(row, col - 1, color);
  }
  if (col != wall) {
    flipRight(row, col + 1, color);
  }
  if ((row != 1) && (col != 1)) {
    flipUpLeft(row - 1, col - 1, color);
  }
  if ((row != 1) && (col != wall)) {
    flipUpRight(row - 1, col + 1, color);
  }
  if ((row != wall) && (col != 1)) {
    flipDownLeft(row + 1, col - 1, color);
  }
  if ((row != wall) && (col != wall)) {
    flipDownRight(row + 1, col + 1, color);
  }
}

/**
 * Flipping our board up
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipUp(int row, int col, int color) {
  // Reseting our counter and flipped color
  int counter = 0;
  int flipped = board->cellMatrix[row + 1][col].getFlip();
  // Traveling up while we havent reached a diff colored disk or a wall
  while ((board->cellMatrix[row][col].getColor() == flipped) && row > 1) {
    // Counting each move up
    row--;
    counter++;
  }
  // Lastly checking if the point we reached is of the desired color
  if (board->cellMatrix[row][col].getColor() == color) {
    // Flipping each cell on the way back to the origin cell
    for (int i = 0; i < counter; i++) {
      row++;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * Flipping our board down
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipDown(int row, int col, int color) {
  int counter = 0;
  int flipped = board->cellMatrix[row - 1][col].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && row < wall) {
    row++;
    counter++;
  }
  if (board->cellMatrix[row][col].getColor() == color) {
    for (int i = 0; i < counter; i++) {
      row--;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * Flipping our board left
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipLeft(int row, int col, int color) {
  int counter = 0;
  int flipped = board->cellMatrix[row][col + 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && col > 1) {
    col--;
    counter++;
  }
  if (board->cellMatrix[row][col].getColor() == color) {
    for (int i = 0; i < counter; i++) {
      col++;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * Flipping our board right
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */void Flip::flipRight(int row, int col, int color) {
  int counter = 0;
  int flipped = board->cellMatrix[row][col - 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && col < wall) {
    col++;
    counter++;
  }
  if (board->cellMatrix[row][col].getColor() == color) {
    for (int i = 0; i < counter; i++) {
      col--;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * Flipping our board up and left diagonally
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipUpLeft(int row, int col, int color) {
  int counter = 0;
  int flipped = board->cellMatrix[row + 1][col + 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row > 1) && (col > 1)) {
    row--;
    col--;
    counter++;
  }
  if (board->cellMatrix[row][col].getColor() == color) {
    for (int i = 0; i < counter; i++) {
      row++;
      col++;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * Flipping our board up and right diagonally
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipUpRight(int row, int col, int color) {
  int counter = 0;
  int flipped = board->cellMatrix[row + 1][col - 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row > 1) && (col < wall)) {
    row--;
    col++;
    counter++;
  }
  if (board->cellMatrix[row][col].getColor() == color) {
    for (int i = 0; i < counter; i++) {
      row++;
      col--;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * Flipping our board down and left diagonally
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipDownLeft(int row, int col, int color) {
  int counter = 0;
  int flipped = board->cellMatrix[row - 1][col + 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row < wall) && (col > 1)) {
    row++;
    col--;
    counter++;
  }
  if (board->cellMatrix[row][col].getColor() == color) {
    for (int i = 0; i < counter; i++) {
      row--;
      col++;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * Flipping our board down and right diagonally
 * @param row - an Integer that represent the row
 * @param col - an Integer that represent the col
 * @param color - an Integer that represent the color
 */
void Flip::flipDownRight(int row, int col, int color) {
  int counter = 0;
  int flipped = board->cellMatrix[row - 1][col - 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row < wall) && (col < wall)) {
    row++;
    col++;
    counter++;
  }
  if (board->cellMatrix[row][col].getColor() == color) {
    for (int i = 0; i < counter; i++) {
      row--;
      col--;
      board->cellMatrix[row][col].flip();
    }
  }
}

/**
 * The destructor of the class
 */
Flip::~Flip() {
}
