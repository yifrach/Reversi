#include <limits>
#include <cstdlib>
#include "../include/GameManager.h"
#include "../include/ColorEnum.h"
#define NO_MOVE -1
#define END -2

GameManager::GameManager(BoardScanner *scanner, Board *board) : scanner(scanner), board(board), wall(board->getSize()) {
  flip = new Flip(board);
}

// Play a single turn of desired color for a local player
void GameManager::playOneTurn(int color) {
  int row, col;
  // First freeing our previous turns moves list
  scanner->freeMovesList();
  // If the player has any moves
  if (scanner->hasMoves(color)) {
    // We'll print them to the screen asking for an input
    scanner->printMoves();
    cout << "Please enter your move row, col: ";
    cin >> row >> col;
    // Checking the input is indeed correct
    if (!scanner->isValidMove(row, col) || cin.fail()) {
      do {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bad input, please try again: ";
        cin >> row >> col;
      } while (!scanner->isValidMove(row, col) || cin.fail());
    }
    // Adding the cell to the board
    board->addCell(row, col, color);
    cout << endl;
    // Flipping the board according to the added cell
    flip->flipBoard(row, col, color);
  } else {
    // If the player has no moves we'll inform him passing the turn back
    cout << "No possible moves! Play passes back to the other player.\n\n";
  }
}

// Play a single turn of an AI controlled white player
Point GameManager::playOneTurnAI(Player *playerAI) {
  // First freeing our previous turns moves list
  scanner->freeMovesList();
  // If the AI has any moves
  if (scanner->hasMoves(white)) {
    // He'll choose his minimax move
    Point p = ((AI *) playerAI)->playTurn(board);
    // Adding the cell to the board
    board->addCell(p.getX(), p.getY(), white);
    cout << endl;
    // Flipping the board according to the added cell
    flip->flipBoard(p.getX(), p.getY(), white);
    return p;
  } else {
    // If the AI has no moves we'll inform the player
    cout << "No possible moves for player O! Play passes back to the other player." << endl;
    // Lastly returning a fake point letting the game know the AI has no moves
    scanner->freeMovesList();
    return Point(NO_MOVE, NO_MOVE);
  }
}

// Play a single turn of an online match for the local player
void GameManager::playOneTurnClient(int color, Player *playerClient) {
  int row, col;
  // First freeing our previous turns moves list
  scanner->freeMovesList();
  // If the player has any moves
  if (scanner->hasMoves(color)) {
    // We'll print them to the screen asking for an input
    scanner->printMoves();
    cout << "Please enter your move row, col:";
    cin >> row >> col;
    //checking the input is indeed correct
    if (!scanner->isValidMove(row, col) || cin.fail()) {
      do {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bad input, please try again: ";
        cin >> row >> col;
      } while (!scanner->isValidMove(row, col) || cin.fail());
    }
    //************try and catch************//
    try {
      ((Client *) playerClient)->sendSocket(row, col);
    } catch (const char *msg) {
      cout << "Failed to connect to server. Reason:" << msg << endl;
      exit(-1);
    }
    // Adding the cell to the board
    board->addCell(row, col, color);
    cout << endl;
    // Flipping the board according to the added cell
    flip->flipBoard(row, col, color);
  } else {
    // If the player has no moves we'll inform him passing the turn back
    cout << "No possible moves! Play passes back to the other player.\n\n";
    try {
      ((Client *) playerClient)->sendSocket(NO_MOVE, NO_MOVE);
    } catch (const char *msg) {
      cout << "Failed to connect to server. Reason:" << msg << endl;
      exit(-1);
    }
  }
}

// Play a single turn of an online match NON local player
void GameManager::playOneTurnClientFake(Player *playerClient, Player *playerFake) {
  Point point(0, 0);
  try {
    point = ((Client *) playerClient)->readSocket();
  } catch (const char *msg) {
    cout << "Failed to connect to server. Reason:" << msg << endl;
    exit(-1);
  }
  if (point.getX() != -1) {
    board->addCell(point.getX(), point.getY(), playerFake->getColor());
    cout << endl;
    flip->flipBoard(point.getX(), point.getY(), playerFake->getColor());
    cout << "Player played: ";
    point.print();
    cout << endl;
  } else {
    cout << "Player has no moves, it's your turn: " << endl;
  }
}

GameManager::~GameManager() {
  delete scanner;
  delete flip;
}
