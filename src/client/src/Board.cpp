#include "../include/Board.h"
#include "../include/ColorEnum.h"

Board::Board(int size) : size(size) {
  // Initialize our cellMatrix
  cellMatrix = new Cell *[size + 1];
  for (int i = 0; i < size + 1; i++) {
    cellMatrix[i] = new Cell[size + 1];
  }
  // Placing our four initials disks
  cellMatrix[size / 2][size / 2].changeColor(white);
  cellMatrix[(size / 2) + 1][(size / 2) + 1].changeColor(white);
  cellMatrix[(size / 2) + 1][size / 2].changeColor(black);
  cellMatrix[size / 2][(size / 2) + 1].changeColor(black);
}

// Boards copy constructor
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

// Printing the board at its current state
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

// Getter for our boards size
int Board::getSize() {
  return size;
}

// Add a single cell to the board
void Board::addCell(int row, int col, int color) {
  cellMatrix[row][col].changeColor(color);
}

// Boards destructor
Board::~Board() {
  // Deleting each cell in the board
  for (int i = 0; i < size + 1; i++) {
    delete[] cellMatrix[i];
  }
  // Lastly deleting the cell matrix
  delete[] cellMatrix;
}

