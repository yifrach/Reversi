#include "../include/ConvertString.h"
#include <sstream>
#include <cstring>
#include <stdlib.h>
#define NO_MOVE -1
using namespace std;

ConvertString::ConvertString() {}

// Convert 2 integers to "X, Y" format char array
// Or return NoMove if the point is fake
char *ConvertString::convertInt(int xPos, int yPos) {
  // If the point is a fake one
  if (xPos == NO_MOVE) {
    char *str = new char[strlen("NoMove")];
    strcpy(str, "NoMove");
    return str;
  } else {
    // Otherwise converting the it to the format
    string str;
    ostringstream convert;
    convert << xPos << ", " << yPos;
    str = convert.str();
    // Converting our string to a char array
    char *move = new char[str.length() + 1];
    strcpy(move, str.c_str());
    return move;
  }
}

// Convert a char array to the corresponding point
Point ConvertString::convertInput(char *str) {
  // Return a fake point if there are no moves
  if (strcmp(str, "NoMove") == 0) {
    return Point(NO_MOVE, NO_MOVE);
  } else {
    // Separate the string by comma
    istringstream ss(str);
    string xPos;
    string yPos;
    getline(ss, xPos, ',');
    getline(ss, yPos);
    // Lastly converting it to our point using atoi
    return Point(atoi(xPos.c_str()), atoi(yPos.c_str()));
  }
}