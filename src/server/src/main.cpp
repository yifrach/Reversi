#include "../include/Server.h"
#include "../include/FileReader.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  FileReader fileReader;
  int port = fileReader.readConfigFile("/home/uri/CLionProjects/cpp/Reversi/src/server/server_config.txt");
  Server server(port);
  try {
    server.start();
  } catch (const char *msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
  }
}