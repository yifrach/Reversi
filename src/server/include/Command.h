#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H

#include <string>
#include "Server.h"
using namespace std;
static pthread_mutex_t count_mutex_lobby;
static pthread_mutex_t count_mutex_vector;

class Command {
public:
  virtual void execute(string args, roomInfo* info) = 0;
  virtual ~Command() {};
};
#endif //SERVER_COMMAND_H
