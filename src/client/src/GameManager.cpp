#include <limits>
#include <cstdlib>
#include "../include/GameManager.h"

/**
 * Our GameLogic constructor
 * @param scanner - the games board BoarScanner
 * @param board - the games Board
 */
GameManager::GameManager(BoardScanner *scanner, Board *board) : scanner(scanner), board(board), wall(board->getSize()) {
  flip = new Flip(board);
}

/**
 * Plays a single turn for the desired color player
 * @param color - the players color
 */
void GameManager::playOneTurn(int color) {
  int row, col;
  //first freeing our previous turns moves listscanner->freeMovesList();
  scanner->freeMovesList();
  //scanning the board again filling the availble moves list
  scanner->scanBoard(color);
  //if the player has any moves
  if (scanner->hasMoves(color)) {
    //we'll print them to the screen asking for an input
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
        //doing so untill the input is correct
      } while (!scanner->isValidMove(row, col) || cin.fail());
    }
    //adding the cell to the board
    board->addCell(row, col, color);
    cout << endl;
    //flipping the board according to the added cell
    flip->flipBoard(row, col, color);
  } else {
    //if the player has no moves we'll inform him passing the turn back
    cout << "No possible moves! Play passes back to the other player.\n\n";
  }
  //first freeing our previous turns moves listscanner->freeMovesList();
  scanner->freeMovesList();
}

/**
 * The method get a Player and playing his turn.
 * @param pointAI - a variable from type Player that represent the AI player
 * @return - a Point that represent the move that the player done.
 */
Point GameManager::playOneTurnAI(Player *playerAI) {
  //first freeing our previous turns moves list
  scanner->freeMovesList();
  //since we defined the AI player will always be white
  if (scanner->hasMoves(white)) {
    Point p = ((AI *) playerAI)->playTurn(board);
    //adding the cell to the board
    board->addCell(p.getX(), p.getY(), white);
    cout << endl;
    //flipping the board according to the added cell
    flip->flipBoard(p.getX(), p.getY(), white);
    scanner->freeMovesList();
    return p;
  } else {
    cout << "No possible moves for player O! Play passes back to the other player." << endl;
    //returning a fake point letting the game know AI has no moves
    scanner->freeMovesList();
    return Point(-1, -1);
  }
}

void GameManager::playOneTurnClient(int color, Player *playerClient) {
  int row, col;
  //first freeing our previous turns moves listscanner->freeMovesList();
  scanner->freeMovesList();
  //scanning the board again filling the availble moves list
  scanner->scanBoard(color);
  //if the player has any moves
  if (scanner->hasMoves(color)) {
    //we'll print them to the screen asking for an input
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
        //doing so untill the input is correct
      } while (!scanner->isValidMove(row, col) || cin.fail());
    }
    //************try and catch************//
    try {
      ((Client *) playerClient)->sendSocketPoint(row, col);
    } catch (const char *msg) {
      cout << "Failed to connect to server. Reason:" << msg << endl;
      exit(-1);
    }
    //adding the cell to the board
    board->addCell(row, col, color);
    cout << endl;
    //flipping the board according to the added cell
    flip->flipBoard(row, col, color);
  } else {
    //if the player has no moves we'll inform him passing the turn back
    if(scanner->hasMoves(playerClient->getColor())) {
      cout << "No possible moves! Play passes back to the other player.\n\n";
      try {
        ((Client *) playerClient)->sendSocketNoMove("NoMove");
      } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
      }
    } else {
      try {
        ((Client *) playerClient)->sendSocketNoMove("End");
      } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
      }
    }
  }
  //first freeing our previous turns moves listscanner->freeMovesList();
  scanner->freeMovesList();
}

void GameManager::playOneTurnClientFake(Player *playerClient, Player *playerFake) {
  Point point(0,0);
  try {
    point=((Client*)playerClient)->readSocket();
  } catch (const char *msg) {
    cout << "Failed to connect to server. Reason:" << msg << endl;
    exit(-1);
  }
  if(point.getX()!=-1) {
    board->addCell(point.getX(), point.getY(), playerFake->getColor());
    cout << endl;
    flip->flipBoard(point.getX(), point.getY(), playerFake->getColor());
    cout<<"Player played: ";
    point.print();
    cout<<endl;
  } else {
    cout<<"Player has no moves, it's your turn: "<<endl;
  }
}

GameManager::~GameManager() {
  delete scanner;
  delete flip;
}
