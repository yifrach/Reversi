#include "../include/ConverString.h"
#include <sstream>
using namespace std;

/**
 * The constructor of the class
 */
ConvertString::ConvertString() {}

/**
 * Convert a char array to the corresponding point
 * @param str -a char array that we read from the server
 * @return - a Point that represent the move
 */
string ConvertString::convertInput(char *str, string roomName) {
  // Separate the string by space
  istringstream ss(str);
  string commandType;
  string tempRoomName;
  getline(ss, commandType, ' ');
  getline(ss, tempRoomName);
  roomName = tempRoomName;
  return commandType;
}