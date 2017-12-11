#ifndef EX2_BOARDSCANNER_H
#define EX2_BOARDSCANNER_H
#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

class BoardScanner {
 public:
  //constructor
  BoardScanner(Board *board);
  //destructor
  ~BoardScanner();
  // scan the board based on the color
  void scanBoard(int color);
  //Get the amount of disks on the board based on the color
  int getDisksScore(int color);
  // return if a color has any moves
  bool hasMoves(int color);
  //Print the players availble moves based on the last board scan
  void printMoves();
  //Return whether or not a given move is valid to play
  bool isValidMove(int row, int col);
  //Freeing our lastest scans moves list
  void freeMovesList();
  // getter for our pointsVector
  vector<Point *> getPointsVector();

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
  //Return whether or not a move is in our moves list
  bool isInVector(int row, int col, int counter);
};

#endif //EX2_BOARDSCANNER_H
