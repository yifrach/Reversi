#include "../include/FileReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

FileReader::FileReader() : path(path) {}

// Returns the servers port number
int FileReader::readConfigFile(const char *path) {
  string str;
  ifstream inFile;
  // Opening our file
  inFile.open(path);
  if (!inFile.is_open()) {
    cout << "Error opening file" << endl;
  }
  inFile >> str;
  inFile.close();
  // Separating our string by ":"
  istringstream ss(str);
  string dummy;
  string res;
  getline(ss, dummy, ':');
  getline(ss, res);
  return atoi(res.c_str());
}