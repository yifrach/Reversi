#include "../include/BoardScanner.h"

/**
 * Constructor for our board scanner
 * @param board - the board which to scan.
 */
BoardScanner::BoardScanner(Board *board) : board(board), wall(board->getSize()) {}

/**
 * Scanning our board, each cell, using 8 sub functions
 * @param color - the color to scan for possible moves
 */
void BoardScanner::scanBoard(int color) {
  //going over each cell in the board
  for (int i = 1; i < wall + 1; i++) {
    for (int j = 1; j < wall + 1; j++) {
      //checking for moves in all directions based on the disks location
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
 * Get the amount of disks on the board of the color
 * @param color - the color to check the score for
 * @return - the amount of colored disks on the board.
 */
int BoardScanner::getDisksScore(int color) {
  int score = 0;
  for (int i = 1; i < wall + 1; i++) {
    for (int j = 1; j < wall + 1; j++) {
      if (board->cellMatrix[i][j].getColor() == color) {
        //counting up each desired color disk
        score++;
      }
    }
  }
  return score;
}

/**
 * Check whether or not a player has any turns
 * @param color - the players color
 * @return - true or false if the player has any moves to make
 */
bool BoardScanner::hasMoves(int color) {
  scanBoard(color);
  return !pointsVector.empty();
}

/**
 * Print the playeres availble moves list based on who we scanned last
 */
void BoardScanner::printMoves() {
  cout << "Your possible moves are: ";
  for (int i = 0; i < pointsVector.size(); i++) {
    pointsVector[i]->print();
  }
  cout << endl;
}

bool BoardScanner::isValidMove(int row, int col) {
  //going over all of our vector points
  for (int i = 0; i < pointsVector.size(); i++) {
    //checking if the input move is valid
    if ((pointsVector[i]->getX() == row) && (pointsVector[i]->getY() == col)) {
      return true;
    }
  }
  //returning false if a move is not valid
  return false;
}

/**
 * Check whehther or not a possible move was already considerd
 * @param row - the moves row
 * @param col - the moves col
 * @return - true or false if the move was already counted
 */
bool BoardScanner::isInVector(int row, int col, int counter) {
  for (int i = 0; i < pointsVector.size(); i++) {
    //comparing our points
    if ((pointsVector[i]->getX() == row) && (pointsVector[i]->getY() == col)) {
      pointsVector[i]->increaseGrade(counter);
      return true;
    }
  }
  return false;
}

/**
 * Checking for possible moves up
 * @param row - the disks row
 * @param col - the disks col
 */
void BoardScanner::checkUp(int row, int col) {
  int counter = 0;
  //getting our flipped color to look for
  int flipped = board->cellMatrix[row + 1][col].getFlip();
  //traveling up while we havent encountred a wall or a opposite color disk
  while ((board->cellMatrix[row][col].getColor() == flipped) && row > 1) {
    row--;
    counter++;
    //lastly checking the point which we stopped making sure its a valid p
    if ((board->cellMatrix[row][col].getColor() == -1) && !(isInVector(row, col, counter))) {
      Point *po = new Point(row, col);
      po->increaseGrade(counter);
      pointsVector.push_back(po);
    }
  }
}

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
 * Freeing our availble moves list for the next players turn
 */
void BoardScanner::freeMovesList() {
  for (int i = 0; i < pointsVector.size(); i++) {
    delete pointsVector[i];
  }
  pointsVector.clear();
}
/**
 * Getter for our pointsVector
 * @return the available moves points vector
 */
vector<Point *> BoardScanner::getPointsVector() {
  return pointsVector;
}
/**
 * Our BoardScanner destructor
 */
BoardScanner::~BoardScanner() {
  delete board;
  for (int i = 0; i < pointsVector.size(); i++) {
    delete pointsVector[i];
  }
  pointsVector.clear();
}


