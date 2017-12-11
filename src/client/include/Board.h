#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include <iostream>
#include "Cell.h"

class Board {
 public:
  //constructor
  Board(int size);
  //deep copy constructor
  Board(const Board &oldBoard); // boards copy constructor
  //destructor
  ~Board();
  //Getter for our boards size
  int getSize();
  //Add a single cell to the board
  void addCell(int row, int coll, int color);
  //Printing the board at its current state
  void print();

  Cell **cellMatrix;

 private:
  int size;
};

#endif //EX2_BOARD_H
