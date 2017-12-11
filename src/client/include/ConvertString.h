#ifndef REVERSI_CONVERTSTRING_H
#define REVERSI_CONVERTSTRING_H
#include "Point.h"

class ConvertString {
 public:
  //constructor
  ConvertString();
  //Convert 2 integers to "X, Y" format char array Or return NoMove if the point is
  char* convertInt(int num1, int num2);
  //Convert a char array to the corresponding point
  Point convertInput(char* str);
};
#endif //REVERSI_CONVERTSTRING_H
