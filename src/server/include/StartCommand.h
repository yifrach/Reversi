#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include <map>
#include "Command.h"
#include "Server.h"

class StartCommand: public Command {
 public:
  StartCommand();
  virtual void execute(string args, roomInfo* info);
};

#endif //SERVER_STARTCOMMAND_H
