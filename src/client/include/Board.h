#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include <iostream>
#include "Cell.h"

class Board {
 public:
  Board(int size);

  //Boards copy constructor
  Board(const Board &oldBoard);
  ~Board();

  //Getter for the boards size
  int getSize();

  //Adding a single cell
  void addCell(int row, int coll, int color);

  //Printing out the board
  void print();
  Cell **cellMatrix;

 private:
  int size;
};

#endif //EX2_BOARD_H
