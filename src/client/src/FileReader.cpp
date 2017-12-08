#include "../include/FileReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

FileReader::FileReader(char *path) : path(path) {}

// Reading our clients config file
char* FileReader::readConfigFile() {
  string str[2];
  ifstream inFile;
  // Opening our file
  inFile.open(path);
  if (!inFile.is_open()) {
    cout << "Error opening file" << endl;
  }
  inFile >> str[0];
  inFile >> str[1];
  inFile.close();
  // Seperating our string by ":"
  for (int i = 0 ; i < 2 ; i++) {
    istringstream ss(str[i]);
    string dummy;
    string res;
    getline(ss, dummy, ':');
    getline(ss, res);
    str[i] = res;
  }
  int port = atoi(str[1].c_str());
  char *ip = new char[str[0].length() + 1];
  strcpy(ip, str[0].c_str());
  return ip;
}
