//
// Created by yarin on 12/22/17.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include "Command.h"

class JoinCommand: public Command {
 public:
  JoinCommand();
  virtual void execute(vector<string> args);

};

#endif //SERVER_JOINCOMMAND_H
