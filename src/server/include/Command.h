//
// Created by yarin on 12/22/17.
//

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H

#include <vector>
#include <string>
using namespace std;

class Command {
public:
  virtual void execute(vector<string> args) =0;
  virtual ~Command() {};
};
#endif //SERVER_COMMAND_H
