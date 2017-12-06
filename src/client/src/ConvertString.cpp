//
// Created by yarin on 12/5/17.
//


#include "../include/ConvertString.h"
#include <sstream>
#include <cstring>
using namespace std;

ConvertString::ConvertString() {}

char *ConvertString::endGame() {

}

const char *ConvertString::convertInt(int num1, int num2) {
  string str;

  ostringstream convert;

  convert << num1 << ", " << num2;

  str = convert.str();

  cout << str << endl;

  return str.c_str();
}

Point ConvertString::convertInput(char *str) {
  if (strcmp(str, "NoMove") == 0) {
    return Point(-1, -1);
  } else {
    return Point(str[0]-'0', str[3]-'0');
  }
}