#include "../include/BoardScanner.h"

/**
 * The constructor of the class, get a Board
 * @param board
 */
BoardScanner::BoardScanner(Board *board) : board(board), wall(board->getSize()) {}

/**
 * Scanning our board cell by cell using 8 sub functions and by the color it gets
 * @param color - an Integer that represent the color
 */
void BoardScanner::scanBoard(int color) {
  // Going over each cell in the board
  for (int i = 1; i < wall + 1; i++) {
    for (int j = 1; j < wall + 1; j++) {
      // Checking for moves in all directions based on the disks location
      if (board->cellMatrix[i][j].getColor() == color) {
        if (i > 1) {
          checkUp(i - 1, j);
        }
        if (i < wall) {
          checkDown(i + 1, j);
        }
        if (j > 1) {
          checkLeft(i, j - 1);
        }
        if (j < wall) {
          checkRight(i, j + 1);
        }
        if ((i > 1) && (j > 1)) {
          checkUpLeft(i - 1, j - 1);
        }
        if ((i > 1) && (j < wall)) {
          checkUpRight(i - 1, j + 1);
        }
        if ((i < wall) && (j > 1)) {
          checkDownLeft(i + 1, j - 1);
        }
        if ((i < wall) && (j < wall)) {
          checkDownRight(i + 1, j + 1);
        }
      }
    }
  }
}

/**
 * Get the amount of disks on the board based on the color
 * @param color -an Integer that represent the color
 * @return -an Integer that disks score on the board
 */
int BoardScanner::getDisksScore(int color) {
  int score = 0;
  for (int i = 1; i < wall + 1; i++) {
    for (int j = 1; j < wall + 1; j++) {
      if (board->cellMatrix[i][j].getColor() == color) {
        // Counting up each desired color disk
        score++;
      }
    }
  }
  return score;
}

/**
 * Return whether or not a player has any moves to play
 * @param color --an Integer that represent the color
 * @return - a bool- true if it has moves, false if not
 */
bool BoardScanner::hasMoves(int color) {
  scanBoard(color);
  return !pointsVector.empty();
}

/**
 * Print the players availble moves based on the last board scan
 */
void BoardScanner::printMoves() {
  cout << "Your possible moves are: ";
  for (int i = 0; i < pointsVector.size(); i++) {
    pointsVector[i]->print();
  }
  cout << endl;
}

/**
 * Return whether or not a given move is valid to play
 * @param row -an Integer that represent the row
 * @param col -an Integer that represent the col
 * @return - a bool- true if is valid, false if not
 */
bool BoardScanner::isValidMove(int row, int col) {
  // Going over all of our vector points
  for (int i = 0; i < pointsVector.size(); i++) {
    // Checking if the input move is valid
    if ((pointsVector[i]->getX() == row) && (pointsVector[i]->getY() == col)) {
      return true;
    }
  }
  // Returning false if a move is not valid
  return false;
}

/**
 * Return whether or not a move is in our moves list
 * @param row -an Integer that represent the row
 * @param col -an Integer that represent the col
 * @param counter -an Integer that represent the counter of the move
 * @return -a bool- true if its already exist, false if not
 */
bool BoardScanner::isInVector(int row, int col, int counter) {
  for (int i = 0; i < pointsVector.size(); i++) {
    // Comparing our points
    if ((pointsVector[i]->getX() == row) && (pointsVector[i]->getY() == col)) {
      pointsVector[i]->increaseGrade(counter);
      return true;
    }
  }
  return false;
}

/**
 * Checking up for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkUp(int row, int col) {
  int counter = 0;
  // Getting our flipped color to look for
  int flipped = board->cellMatrix[row + 1][col].getFlip();
  // Traveling up while we haven'tencounteredd a wall or a opposite color disk
  while ((board->cellMatrix[row][col].getColor() == flipped) && row > 1) {
    row--;
    counter++;
    // Lastly checking the point which we stopped making sure it's a valid point
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      // Updating its grade flip
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Checking down for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkDown(int row, int col) {
  int counter = 0;
  int flipped = board->cellMatrix[row - 1][col].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && row < wall) {
    row++;
    counter++;
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Checking left for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkLeft(int row, int col) {
  int counter = 0;
  int flipped = board->cellMatrix[row][col + 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && col > 1) {
    col--;
    counter++;
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Checking right for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkRight(int row, int col) {
  int counter = 0;
  int flipped = board->cellMatrix[row][col - 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && col < wall) {
    col++;
    counter++;
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Checking up and left diagonally for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkUpLeft(int row, int col) {
  int counter = 0;
  int flipped = board->cellMatrix[row + 1][col + 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row > 1) && (col > 1)) {
    row--;
    col--;
    counter++;
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Checking up and right diagonally for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkUpRight(int row, int col) {
  int counter = 0;
  int flipped = board->cellMatrix[row + 1][col - 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row > 1) && (col < wall)) {
    row--;
    col++;
    counter++;
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Checking down and left diagonally for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkDownLeft(int row, int col) {
  int counter = 0;
  int flipped = board->cellMatrix[row - 1][col + 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row < wall) && (col > 1)) {
    row++;
    col--;
    counter++;
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Checking down and right diagonally for possible moves
 * @param row - an Integer that reresent the row
 * @param col - an Integer that reresent the col
 */
void BoardScanner::checkDownRight(int row, int col) {
  int counter = 0;
  int flipped = board->cellMatrix[row - 1][col - 1].getFlip();
  while ((board->cellMatrix[row][col].getColor() == flipped) && (row < wall) && (col < wall)) {
    row++;
    col++;
    counter++;
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

/**
 * Freeing our lastest scans moves list
 */
void BoardScanner::freeMovesList() {
  // Deleting each point in the vector
  for (int i = 0; i < pointsVector.size(); i++) {
    delete pointsVector[i];
  }
  pointsVector.clear();
}

/**
 * Getter for our moves list
 * @return - moves list
 */
vector<Point *> BoardScanner::getPointsVector() {
  return pointsVector;
}

/**
 * Board Scanners destructor
 */
BoardScanner::~BoardScanner() {
  delete board;
  freeMovesList();
}


