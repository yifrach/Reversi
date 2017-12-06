//
// Created by yarin on 12/5/17.
//

#ifndef REVERSI_CONVERTSTRING_H
#define REVERSI_CONVERTSTRING_H

#include "Point.h"
class ConvertString {
 public:
  ConvertString();

  const char* convertInt(int num1, int num2);

  char* endGame();

  Point convertInput(char* str);


};
#endif //REVERSI_CONVERTSTRING_H
