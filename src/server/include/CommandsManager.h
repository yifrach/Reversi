//
// Created by yarin on 12/22/17.
//

#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

#include <map>
#include "Command.h"
#include "Server.h"

class CommandsManager
{
public:
  CommandsManager();
  ~CommandsManager();
  void executeCommand(string command, string args, roomInfo* info);
private:
  map<string, Command *> commandsMap;
};

#endif //SERVER_COMMANDSMANAGER_H
