#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include <iostream>
#include "Cell.h"

class Board {
 public:
  Board(int size);
  Board(const Board &oldBoard); // boards copy constructor
  ~Board();
  int getSize();
  void addCell(int row, int coll, int color);
  void print();
  Cell **cellMatrix;

 private:
  int size;
};

#endif //EX2_BOARD_H
