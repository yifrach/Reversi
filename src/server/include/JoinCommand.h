#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include <map>
#include "Command.h"
#include "Server.h"

class JoinCommand: public Command {
 public:
  JoinCommand();
  virtual void execute(string args, roomInfo* info);
};

#endif //SERVER_JOINCOMMAND_H
