#ifndef REVERSI_FLIP_H
#define REVERSI_FLIP_H

#include "Board.h"

class Flip {
 public:
  //constructor
  Flip(Board *nBoard);

  //destructor
  ~Flip();

  //flip our board disks based on the new disks location and color
  void flipBoard(int row, int col, int color);

 private:
  Board *board;
  int wall;

  //flipping the board in all directions
  void flipUp(int row, int col, int color);
  void flipDown(int row, int col, int color);
  void flipLeft(int row, int col, int color);
  void flipRight(int row, int col, int color);
  void flipUpLeft(int row, int col, int color);
  void flipUpRight(int row, int col, int color);
  void flipDownLeft(int row, int col, int color);
  void flipDownRight(int row, int col, int color);
};
#endif //REVERSI_FLIP_H
