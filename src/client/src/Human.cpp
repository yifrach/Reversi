#include <limits>
#include "../include/Human.h"
#include "../include/BoardScanner.h"

/**
 * The constructor of the class
 */
Human::Human() {}

/**
 * The destructor of the class
 */
Human::~Human() {}

/**
 * The method get a Board, get a move from the user and return a Point
 * @param board - a variable from type Board
 * @return - a Point that represent the player move
 */
Point Human::playTurn(Board *board) {
  int row, col;
  Board *tempBoard = new Board(*board);
  BoardScanner *scanner = new BoardScanner(tempBoard);
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
  delete scanner;
  return Point(row, col);
}

/**
 * The method pass the turn of the player
 * @return - a Point that represent that the user had no move.
 */
Point Human::passTurn() {
  // If the player has no moves we'll inform him passing the turn back
  cout << "No possible moves! Play passes back to the other player.\n\n";
  return Point(-1,-1);
}