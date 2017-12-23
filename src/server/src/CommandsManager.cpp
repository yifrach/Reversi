//
// Created by yarin on 12/22/17.
//

#include "../include/CommandsManager.h"
#include "../include/JoinCommand.h"
#include "../include/StartCommand.h"
#include "../include/PlayCommand.h"

CommandsManager::CommandsManager() {
  commandsMap["start"] = new StartCommand();
  commandsMap["join"] = new JoinCommand();
  commandsMap["play"] = new PlayCommand();

}
void CommandsManager::executeCommand(string command, vector<string> args) {
  Command *commandObj = commandsMap[command];
  commandObj -> execute(args);
}

CommandsManager::~CommandsManager() {
  map<string, Command *>::iterator it;
  for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
    delete it -> second;
  }
}