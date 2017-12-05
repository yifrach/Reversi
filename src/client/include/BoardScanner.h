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

  //scanning our board for possible moves based on the players color
  void scanBoard(int color);

  //check for the amount of each disk on the board
  int getDisksScore(int color);

  //true or false whether the player has any moves
  bool hasMoves(int color);

  //print the players possible moves
  void printMoves();

  //true or false if a move is valid
  bool isValidMove(int row, int col);

  //Freeing our available moves vector
  void freeMovesList();

  //the method return the member pointsVector that represent the possible moves
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

  //checks whether a possible moves is already on the list or not
  bool isInVector(int row, int col, int counter);
};

#endif //EX2_BOARDSCANNER_H
