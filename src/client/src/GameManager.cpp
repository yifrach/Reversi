#include "../include/GameManager.h"

/**
 * The constructor of the class
 * @param scanner - a BoardScanner
 * @param board - a Board
 */
GameManager::GameManager(BoardScanner *scanner, Board *board) : scanner(scanner), board(board), wall(board->getSize()) {
  flip = new Flip(board);
}

/**
 * Play a single turn of desired color for a player that it got
 * @param player - a Player that we want to play a turn with
 * @return - a Point that represent of we played a turn or not
 */
Point GameManager::playOneTurn(Player *player) {
  // First freeing our previous turns moves list
  scanner->freeMovesList();
  // If the player has any moves
  if (scanner->hasMoves(player->getColor())) {
    Point p=player->playTurn(board);
    // Adding the cell to the board
    if(p.getX()>0) {
      board->addCell(p.getX(), p.getY(), player->getColor());
      cout << endl;
      // Flipping the board according to the added cell
      flip->flipBoard(p.getX(), p.getY(), player->getColor());
    }
    scanner->freeMovesList();
    return p;
  } else {
    player->passTurn();
  }
}

/**
 * The destructor of the class
 */
GameManager::~GameManager() {
  delete scanner;
  delete flip;
}
