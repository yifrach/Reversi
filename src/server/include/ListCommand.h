#ifndef SERVER_LISTCOMMAND_H
#define SERVER_LISTCOMMAND_H

#include <map>
#include "Command.h"
#include "Server.h"

class ListCommand: public Command {
 public:
  ListCommand();
  virtual void execute(string args, roomInfo* info);
};

#endif //SERVER_LISTCOMMAND_H
