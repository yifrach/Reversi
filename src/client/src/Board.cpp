#include "../include/Board.h"
enum Color { empty = -1, white, black };

/**
 * Initialzing our board
 *
 * @param size - the desires boards size
 */
Board::Board(int size) : size(size) {
  //initialize our cellMatrix
  cellMatrix = new Cell *[size + 1];
  for (int i = 0; i < size + 1; i++) {
    cellMatrix[i] = new Cell[size + 1];
  }
  //placing our four initials disks
  cellMatrix[size / 2][size / 2].changeColor(white);
  cellMatrix[(size / 2) + 1][(size / 2) + 1].changeColor(white);
  cellMatrix[(size / 2) + 1][size / 2].changeColor(black);
  cellMatrix[size / 2][(size / 2) + 1].changeColor(black);
}

Board::Board(const Board &oldBoard) {
  size = oldBoard.size;
  cellMatrix = new Cell *[size + 1];
  for (int i = 0; i < size + 1; i++) {
    cellMatrix[i] = new Cell[size + 1];
  }
  for (int i = 0; i < size + 1; i++) {
    for (int j = 0; j < size + 1; j++) {
      cellMatrix[i][j] = oldBoard.cellMatrix[i][j];
    }
  }
}

/**
 * Printing the board at its current state
 */
void Board::print() {
  string line = "----";
  for (int i = 0; i < size + 1; i++) {
    for (int j = 0; j < size + 1; j++) {
      if ((i == 0) && (j == 0)) {
        cout << "  ";
      } else if ((i == 0) && (j != 0)) {
        cout << j;
      } else if ((i != 0) && (j == 0)) {
        cout << " " << i;
      } else {
        cellMatrix[i][j].print();
      }
      cout << " | ";
    }
    cout << endl;
    for (int j = 0; j < size + 1; j++) {
      cout << line;
    }
    cout << endl;
  }
}

/**
 * Getter for our boards size
 * @return - the boards size
 */
int Board::getSize() {
  return size;
}

/**
 * Add a single disk to the board
 * @param row - the disks row
 * @param coll - the disks col
 * @param color - the disks color
 */
void Board::addCell(int row, int col, int color) {
  cellMatrix[row][col].changeColor(color);
}

/**
 * Our boards destructor
 */
Board::~Board() {
  //deleting each cell in the board
  for (int i = 0; i < size + 1; i++) {
    delete[] cellMatrix[i];
  }
  //lastly deleting the cell matrix
  delete[] cellMatrix;
}

