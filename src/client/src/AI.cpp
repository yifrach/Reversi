#include "../include/AI.h"
#include "../include/ColorEnum.h"
AI::AI() {}

/**
 * The method get a Board and calculate his most smart move and return its move
 * @param board - a variable from type Board
 * @return - a Point that represent the player move
 */
Point AI::playTurn(Board *board) {
  Board *tempBoard = new Board(*board);
  BoardScanner *scanner = new BoardScanner(tempBoard);
  scanner->scanBoard(white);
  moves = new vector<int>[scanner->getPointsVector().size()];
  //check the all possible moves of the player
  for (int i = 0; i < scanner->getPointsVector().size(); i++) {
    //deep copy to the board
    tempBoard = new Board(*board);
    //send it to the method checkPoint
    checkPoint(tempBoard, i, scanner);
  }
  //calculate the minimum maximum of the moves
  int *movesMax = new int[scanner->getPointsVector().size()];
  for (int i = 0; i < scanner->getPointsVector().size(); i++) {
    int max = moves[i][0];
    for (int j = 1; j < moves[i].size(); j++) {
      if (max < moves[i][j]) {
        max = moves[i][j];
      }
    }
    movesMax[i] = max;
  }
  //check the minimum move for the player
  int min = 0;
  for (int i = 0; i < scanner->getPointsVector().size() - 1; i++) {
    if (movesMax[i] > movesMax[i + 1]) {
      min = i + 1;
    } else {
      min = i;
    }
  }
  Point resPoint = *scanner->getPointsVector()[min];
  for (int i = 0; i < moves->size(); i++) {
    moves[i].clear();
  }
  delete[] moves;
  delete[] movesMax;
  delete scanner;
  return resPoint;
}

/**
 * The method get a Board and an Integer and check the number of the disks after the move.
 * @param tempBoard - a Board that help us to calculate.
 * @param scanner- a BoardScanner that give us the possible moves
 * @param i - an Integer that help us to save the number of disks
 */
void AI::checkPoint(Board *tempBoard, int i, BoardScanner *scanner) {
  tempBoard->addCell(scanner->getPointsVector()[i]->getX(), scanner->getPointsVector()[i]->getY(), white);
  Flip *flip = new Flip(tempBoard);
  flip->flipBoard(scanner->getPointsVector()[i]->getX(), scanner->getPointsVector()[i]->getY(), white);
  BoardScanner *tempBS = new BoardScanner(tempBoard);
  tempBS->scanBoard(black);
  //check if there is possible moves
  if (!(tempBS->hasMoves(black))) {
    moves[i].push_back(0);
    delete flip;
    delete tempBS;
    return;
  }
  //calculate the number of disks after we made a move.
  int diskFlip = 0;
  for (int j = 0; j < tempBS->getPointsVector().size(); j++) {
    int blackDisk = tempBS->getDisksScore(black);
    int whiteDisk = tempBS->getDisksScore(white);
    diskFlip = tempBS->getPointsVector()[j]->getGrade();
    blackDisk = blackDisk + 1 + diskFlip;
    whiteDisk = whiteDisk - diskFlip;
    moves[i].push_back(blackDisk - whiteDisk);
  }
  tempBS->freeMovesList();
  delete flip;
  delete tempBS;
}

Point AI::passTurn() {
  // If the player has no moves we'll inform him passing the turn back
  cout << "No possible moves! Play passes back to the other player.\n\n";
  return Point(-1,-1);
}