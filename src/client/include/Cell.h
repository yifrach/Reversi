#ifndef EX2_CELL_H
#define EX2_CELL_H
#include <iostream>
#include "Point.h"
using namespace std;

class Cell {
 public:
  Cell();
  Cell(const Cell &oldCell);
  int getColor();
  void changeColor(int color);
  void flip();
  int getFlip();
  void print();

 private:
  int color;
};

#endif //EX2_CELL_H