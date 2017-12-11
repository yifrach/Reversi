#include "../include/FileReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

/**
 * The constructor of the class
 * @param path
 */
FileReader::FileReader(const char *path) : path(path) {}

/**
 * Reading our clients config file
 * @param port - an Integer pointer to the port of the server
 * @return - a char array that represent the IP
 */
const char* FileReader::readConfigFile(int* port) {
  string str[2];
  ifstream inFile;
  // Opening our file
  inFile.open(path);
  if (!inFile.is_open()) {
    cout << "Error opening file" << endl;
  }
  // First reading our ip
  inFile >> str[0];
  // Then our port number
  inFile >> str[1];
  inFile.close();
  // Separating our strings by ":"
  for (int i = 0 ; i < 2 ; i++) {
    istringstream ss(str[i]);
    string dummy;
    string res;
    getline(ss, dummy, ':');
    getline(ss, res);
    str[i] = res;
  }
  *port = atoi(str[1].c_str());
  char *ip = new char[str[0].length() + 1];
  strcpy(ip, str[0].c_str());
  return ip;
}
