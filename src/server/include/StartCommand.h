//
// Created by yarin on 12/22/17.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"

class StartCommand: public Command {
 public:
  StartCommand();
  virtual void execute(vector<string> args);
};

#endif //SERVER_STARTCOMMAND_H
