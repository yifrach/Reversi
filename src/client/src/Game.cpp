#include <fstream>
#include "../include/Game.h"
#include <stdlib.h>

//The constructor
Game::Game() {}

//The method initialize- choose a mode and initialize by this mode
void Game::initialize() {
  menuGame();
  //Creating our players
  switch (mode) {
    case 1:player1 = new Human();
      player1->setColor(white);
      player2 = new Human();
      player2->setColor(black);
      break;
    case 2:player1 = new AI();
      player1->setColor(white);
      player2 = new Human();
      player2->setColor(black);
      break;
    case 3:readFile();
      try {
        player1->setColor(((Client*)player1)->connectToServer());
      } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
      }
      player2 = new Human();
      if(player1->getColor()==black) {
        player2->setColor(white);
      } else {
        player2->setColor(black);
      }
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
  manager = new GameManager(scanner, board);
}

//The method print the menu of the game and get the mode that the player want to play
void Game::menuGame() {
  cout << "WELCOME TO REVERSI!" << endl<<endl;
  cout << "choose an opponent type:"<<endl;
  cout<<"1. a human local player\n2. an AI player\n3. a remote player\n";
  cin >> mode;
}


//The method play the game by the mode that the user had chosen
void Game::playGame() {
  //the black player will always start
  cout << "Please enter your input in the format row column" << endl;
  //playing the game while each player has a possible move
  switch (mode) {
    case 1:playHuman();
      break;
    case 2:playAI();
      break;
    case 3: playClient();
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
  bool blackPlayed = false;
  while (scanner->hasMoves(black) || scanner->hasMoves(white)) {
    board->print();
    if (blackPlayed) {
      cout << "Player O it's your move." << endl;
      manager->playOneTurn(white);
      blackPlayed = false;
    } else {
      cout << "Player X it's your move." << endl;
      manager->playOneTurn(black);
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
      Point point = manager->playOneTurnAI(player1);
      //checking it is a correct move
      if (point.getX() != -1) {
        cout << "Player O made a move: ";
        point.print();
        cout << "\n\n";
      }
      blackPlayed = false;
    } else {
      cout << "Player X it's your move." << endl;
      manager->playOneTurn(black);
      blackPlayed = true;
    }
  }
}


//************************************//
void Game::playClient() {
  bool blackPlayed = false;
  while (scanner->hasMoves(black) || scanner->hasMoves(white)) {
    board->print();
    if (blackPlayed) {
      cout << "Player O it's your move." << endl;
      manager->playOneTurnClient(white, player1);
      blackPlayed = false;
    } else {
      cout << "Player X it's your move." << endl;
      manager->playOneTurnClient(black, player1);
      blackPlayed = true;
    }
  }
}


void Game::readFile() {
  char *IP;
  int port;
  ifstream inFile;

  //**********************//
  inFile.open("user.txt");

  inFile>>IP;
  inFile>>port;

  inFile.close();
  player1=new Client(IP,port);
}

//The destructor of the class
Game::~Game() {
  delete manager;
  delete player1;
  delete player2;
}








