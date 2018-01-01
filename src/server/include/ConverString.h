#ifndef SERVER_CONVERTSTRING_H
#define SERVER_CONVERTSTRING_H

#include <string>
using namespace std;

class ConvertString {
 public:
  //constructor
  ConvertString();
  //Split our str into two strings by space
  string convertInput(char* str, string* roomName);
};
#endif //SERVER_CONVERTSTRING_H
