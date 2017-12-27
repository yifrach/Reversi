#include "../include/ConvertString.h"
#include <sstream>
#include <cstring>
#include <stdlib.h>
#define NO_MOVE -1
#define END -2
#define CLOSE_SERVER_INT -3
using namespace std;

/**
 * The constructor of the class
 */
ConvertString::ConvertString() {}

//
/**
 * Convert 2 integers to "X, Y" format char array Or return NoMove if the point is
 * @param xPos - an Integer that represent the X
 * @param yPos - an Integer that represent the Y
 * @return - "X, Y" format char array Or return NoMove if the point is
 */
char *ConvertString::convertInt(int xPos, int yPos) {
  // If the point is a fake one
  if (xPos == NO_MOVE) {
    char *strNoMove = new char[strlen("NoMove")];
    strcpy(strNoMove, "NoMove");
    return strNoMove;
    // If the point it to mark the games end
  } else if (xPos == END) {
    char *strEnd = new char[strlen("End")];
    strcpy(strEnd, "End");
    return strEnd;
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

/**
 * Convert a char array to the corresponding point
 * @param str -a char array that we read from the server
 * @return - a Point that represent the move
 */
Point ConvertString::convertInput(char *str) {
  // Return a fake point if there are no moves
  if (strcmp(str, "NoMove") == 0) {
    return Point(NO_MOVE, NO_MOVE);
  } else if (strcmp(str, "Exit") == 0) {
    return Point(CLOSE_SERVER_INT, CLOSE_SERVER_INT);
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