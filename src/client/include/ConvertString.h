#ifndef REVERSI_CONVERTSTRING_H
#define REVERSI_CONVERTSTRING_H
#include "Point.h"

class ConvertString {
 public:
  ConvertString();
  char* convertInt(int num1, int num2);
  Point convertInput(char* str);
};
#endif //REVERSI_CONVERTSTRING_H
