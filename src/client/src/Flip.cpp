//
// Created by yarin on 11/28/17.
//

#include "../include/Flip.h"

Flip::Flip(Board *nBoard) : board(nBoard), wall(board->getSize()) {}

Flip::~Flip() {}

/**
 * Flipps the boards disks based on the given disk
 * @param row - the disks row
 * @param col - the disks colum
 * @param color - the disks color
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
 * Flipping up all opposite colored disks
 * @param row - the new disks row
 * @param col - the new disks colum
 * @param color - the new disks color
 */
void Flip::flipUp(int row, int col, int color) {
  //reseting our counter and flipped color
  int counter = 0;
  int flipped = board->cellMatrix[row + 1][col].getFlip();
  //traveling up while we havent reached a diff colored disk or a wall
  while ((board->cellMatrix[row][col].getColor() == flipped) && row > 1) {
    //counting each move up
    row--;
    counter++;
  }
  //lastly checking if the point we reached is of the desired color
  if (board->cellMatrix[row][col].getColor() == color) {
    //flipping each cell on the way back to the origin cell
    for (int i = 0; i < counter; i++) {
      row++;
      board->cellMatrix[row][col].flip();
    }
  }
}

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

void Flip::flipRight(int row, int col, int color) {
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
