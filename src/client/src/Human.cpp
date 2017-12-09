#include <limits>
#include "../include/Human.h"
#include "../include/BoardScanner.h"

Human::Human() {}

Human::~Human() {}

Point Human::playTurn(Board *board) {
  int row, col;
  BoardScanner* scanner=new BoardScanner(board);
  scanner->scanBoard(getColor());
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
  scanner->freeMovesList();
  return Point(row, col);
}

Point Human::passTurn() {
  // If the player has no moves we'll inform him passing the turn back
  cout << "No possible moves! Play passes back to the other player.\n\n";
  return Point(-1,-1);
}