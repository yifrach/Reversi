#include "../include/Game.h"

//enum that represent the numbers, -1, 0 ,1 - help us to understand the code.
enum Color { empty = -1, white, black };

//The constructor
Game::Game() {
  player1Color = white;
  player2Color = black;
}

//The method initialize- choose a mode and initialize by this mode
void Game::initialize() {
  cout << "WELCOME TO REVERSI!" << endl;
  cout << "How many players do you want to play? Enter the number (1 or 2): ";
  cin >> mode;
  //Creating our players based on the mode
  switch (mode) {
    case 1:player1 = new AI();
      player1->setColor(white);
      player2 = new Human();
      player2->setColor(black);
      break;
    case 2:player1 = new Human();
      player1->setColor(white);
      player2 = new Human();
      player2->setColor(black);
      break;
    default:cout << "wrong input!! try again" << endl;
      cin >> mode;
      break;
  }
  //getting a size to the board from the user
  cout << "Please Enter the size of the board: ";
  cin >> size;
  cout << endl;
  board = new Board(size);
  scanner = new BoardScanner(board);
  manage = new GameManager(scanner, board);
}

//The method play the game by the mode that the user had chosen
void Game::playGame() {
  //the black player will always start
  cout << "Please enter your input in the format row column" << endl;
  //playing the game while each player has a possible move
  switch (mode) {
    case 1:playAI();
      break;
    case 2:playHuman();
      break;
    default:break;
  }
  //lastly printing the board
  board->print();
  //announcing the winner
  int p1score = scanner->getDisksScore(white);
  player1->updateScore(p1score);
  int p2score = scanner->getDisksScore(black);
  player2->updateScore(p2score);
  if (player2->getScore() > player1->getScore()) {
    cout << "Player X is the winner with " << player2->getScore() << " disks!" << endl;
  } else {
    cout << "Player O is the winner with " << player1->getScore() << " disks!" << endl;
  }
  cout << "Congratulations!" << endl;
}

//The method play the game by the mode of human against human
void Game::playHuman() {
  //black player will always start
  bool blackPlayed = false;
  while (scanner->hasMoves(black) || scanner->hasMoves(white)) {
    board->print();
    if (blackPlayed) {
      cout << "Player O it's your move." << endl;
      manage->playOneTurn(white);
      blackPlayed = false;
    } else {
      cout << "Player X it's your move." << endl;
      manage->playOneTurn(black);
      blackPlayed = true;
    }
  }
}

//The method play the game by the mode if human against the computer
void Game::playAI() {
  bool blackPlayed = false;
  while (scanner->hasMoves(black) || scanner->hasMoves(white)) {
    board->print();
    if (blackPlayed) {
      Point point = manage->playOneTurnAI(player1);
      //checking it is a correct move
      if (point.getX() != -1) {
        cout << "Player O made a move: ";
        point.print();
        cout << "\n\n";
      }
      blackPlayed = false;
    } else {
      cout << "Player X it's your move." << endl;
      manage->playOneTurn(black);
      blackPlayed = true;
    }
  }
}

//The destructor of the class
Game::~Game() {
  delete manage;
  delete player1;
  delete player2;
}








