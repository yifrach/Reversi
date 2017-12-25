//
// Created by yarin on 12/22/17.
//

#include "../include/CommandsManager.h"
#include "../include/JoinCommand.h"
#include "../include/StartCommand.h"
#include "../include/ListCommand.h"

CommandsManager::CommandsManager() {
  commandsMap["start"] = new StartCommand();
  commandsMap["join"] = new JoinCommand();
  commandsMap["list"] = new ListCommand();
}

void CommandsManager::executeCommand(string command, string args, roomInfo* info) {
  Command *commandObj = commandsMap[command];
  commandObj -> execute(args, info);
}

CommandsManager::~CommandsManager() {
  map<string, Command *>::iterator it;
  for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
    delete it -> second;
  }
}