#ifndef EX2_CELL_H
#define EX2_CELL_H
#include <iostream>
#include "Point.h"
using namespace std;

class Cell {
 public:
  //constructor
  Cell();
  //deep constructor
  Cell(const Cell &oldCell);
  //Getter for our cells color
  int getColor();
  //Change the cells color to color
  void changeColor(int color);
  //Flip the cell disk -changing its color
  void flip();
  //Getter for our cells opposite color
  int getFlip();
  //Print our cells color
  void print();

 private:
  int color;
};

#endif //EX2_CELL_H