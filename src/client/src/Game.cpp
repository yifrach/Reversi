#include <fstream>
#include "../include/Game.h"
#include "../include/FileReader.h"
#include <stdlib.h>
#define END -2
#define BOARD_SIZE 8;

/**
 * The constructor of the class
 */
Game::Game() {}

/**
 * The method initialize- choose a mode and initialize by this mode
 */
void Game::initialize() {
  menuGame();
  initializePlayers();
  // the size of the board
  size = BOARD_SIZE;
  board = new Board(size);
  scanner = new BoardScanner(board);
  manager = new GameManager(scanner, board);
}

/**
 * The method print the menu of the game and get the mode that the player want to play
 */
void Game::menuGame() {
  cout << "WELCOME TO REVERSI!" << endl << endl;
  cout << "choose an opponent type:" << endl;
  cout << "1. a human local player\n2. an AI player\n3. a remote player\n";
  cin >> mode;
}

/**
 * The method initialize the players by the mode that the user want
 */
void Game::initializePlayers() {
  bool modeCoorect = false;
  while (!modeCoorect) {
    //Creating our players
    switch (mode) {
      case 1:player1 = new Human();
        player1->setColor(white);
        player2 = new Human();
        player2->setColor(black);
        modeCoorect = true;
        break;
      case 2:player1 = new AI();
        player1->setColor(white);
        player2 = new Human();
        player2->setColor(black);
        modeCoorect = true;
        break;
      case 3:readFile();
        try {
          player1->setColor(((Client *) player1)->connectToServer());
        } catch (const char *msg) {
          cout << "Failed to connect to server. Reason:" << msg << endl;
          exit(-1);
        }
        player2 = new OnlineOpponent((Client *) player1);
        if (player1->getColor() == black) {
          player2->setColor(white);
        } else {
          player2->setColor(black);
        }
        modeCoorect = true;
        break;
      default:cout << "wrong input!! try again" << endl;
        cin >> mode;
        break;
    }
  }
}

/**
 * The method play the game by the mode that the user had chosen
 */
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

/**
 * The method play the game by the mode of human against human
 */
void Game::playHuman() {
  bool blackPlayed = false;
  while (scanner->hasMoves(black) || scanner->hasMoves(white)) {
    board->print();
    if (blackPlayed) {
      cout << "Player O it's your move." << endl;
      manager->playOneTurn(player1);
      blackPlayed = false;
    } else {
      cout << "Player X it's your move." << endl;
      manager->playOneTurn(player2);
      blackPlayed = true;
    }
  }
}

/**
 * The method play the game by the mode - human against the computer
 */
void Game::playAI() {
  bool blackPlayed = false;
  while (scanner->hasMoves(black) || scanner->hasMoves(white)) {
    board->print();
    if (blackPlayed) {
      Point point = manager->playOneTurn(player1);
      //checking it is a correct move
      if (point.getX() != -1) {
        cout << "Player O made a move: ";
        point.print();
        cout << "\n\n";
      }
      blackPlayed = false;
    } else {
      cout << "Player X it's your move." << endl;
      manager->playOneTurn(player2);
      blackPlayed = true;
    }
  }
}

/**
 * The method play the game by the mode -client against other client
 */
void Game::playClient() {
  bool blackPlayed = false;
  while (scanner->hasMoves(black) || scanner->hasMoves(white)) {
    board->print();
    if (blackPlayed) {
      if (player1->getColor() == white) {
        cout << "Player O it's your move." << endl;
        manager->playOneTurn(player1);
      } else {
        manager->playOneTurn(player2);
      }
      blackPlayed = false;
    } else {
      if (player1->getColor() == black) {
        cout << "Player X it's your move." << endl;
        manager->playOneTurn(player1);
      } else {
        manager->playOneTurn(player2);;
      }
      blackPlayed = true;
    }
  }
  try {
    ((Client *) player1)->sendSocket(END, END);
  } catch (const char *msg) {
    cout << "Failed to connect to server. Reason:" << msg << endl;
    exit(-1);
  }
}

/**
 * The method read a file and initialize the Client player
 * by the parameters from the file
 */
void Game::readFile() {
  FileReader fileReader("client_config.txt");
  int port;
  const char *ip = fileReader.readConfigFile(&port);
  player1 = new Client(ip, port);
}

//The destructor of the class
Game::~Game() {
  delete manager;
  delete player1;
  delete player2;
}








