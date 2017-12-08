#ifndef EX2_BOARDSCANNER_H
#define EX2_BOARDSCANNER_H
#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

class BoardScanner {
 public:
  BoardScanner(Board *board);
  ~BoardScanner();
  void scanBoard(int color); // scan the board based on the color
  int getDisksScore(int color);
  bool hasMoves(int color); // return if a color has any moves
  void printMoves();
  bool isValidMove(int row, int col);
  void freeMovesList();
  vector<Point *> getPointsVector(); // getter for our pointsVector

 private:
  int wall;
  Board *board;
  vector<Point *> pointsVector;
  //checking for possible moves in all directions
  //using 8 sub function checking in each direction
  void checkUp(int row, int col);
  void checkDown(int row, int col);
  void checkLeft(int row, int col);
  void checkRight(int row, int col);
  void checkUpLeft(int row, int col);
  void checkUpRight(int row, int col);
  void checkDownLeft(int row, int col);
  void checkDownRight(int row, int col);
  bool isInVector(int row, int col, int counter);
};

#endif //EX2_BOARDSCANNER_H
