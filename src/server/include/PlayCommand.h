//
// Created by yarin on 12/22/17.
//

#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H

#include "Command.h"

class PlayCommand: public Command {
 public:
  PlayCommand();
  virtual void execute(vector<string> args);
};

#endif //SERVER_PLAYCOMMAND_H
