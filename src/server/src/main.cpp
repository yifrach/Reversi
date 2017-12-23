#include "../include/Server.h"
#include "../include/FileReader.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  // Reading our servers port number
  FileReader fileReader;
  int port = fileReader.readConfigFile("server_config.txt");
  // Creating our server
  Server server(port);
  try {
    server.initialize();
  } catch (const char *msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
  }
}