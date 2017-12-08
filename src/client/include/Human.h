#ifndef REVERSI_HUMAN_H
#define REVERSI_HUMAN_H
#include <iostream>
#include "Player.h"

//The class AI heirs from the abstract class Player
class Human : public Player {
 public:
  Human();
  ~Human();
};

#endif //REVERSI_HUMAN_H
