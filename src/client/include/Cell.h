#ifndef EX2_CELL_H
#define EX2_CELL_H

#include <iostream>
#include "Point.h"

using namespace std;

class Cell {
 public:
  Cell();

  Cell(const Cell &oldCell);

  //getter for our cells disk color
  int getColor();

  //change our disk color to the desiers one
  void changeColor(int color);

  //flip the disks color
  void flip();

  //get the disks flipped color without flipping it
  int getFlip();

  //print the disk
  void print();

 private:
  int color;
};

#endif //EX2_CELL_H