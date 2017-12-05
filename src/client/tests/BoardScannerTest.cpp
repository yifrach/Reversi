#include <gtest/gtest.h>
#include "../include/BoardScanner.h"

enum Color { empty = -1, white, black };

class ScannerTest : public testing::Test {
  virtual void SetUp() {
    //creating a board with many disks
    Board *board = new Board(8);
    board->addCell(3, 3, 0);
    board->addCell(3, 4, 1);
    board->addCell(5, 3, 1);
    board->addCell(6, 4, 1);
    board->addCell(6, 5, 0);
    board->addCell(6, 6, 0);
    board->addCell(7, 4, 1);
    scanner = BoardScanner(board);
  }

  virtual void TearDown() {
  }

 protected:
  BoardScanner scanner;
};

//TEST_F(ScannerTest, Mid_Game) {
//  //creating a board with many disks
//  scanner.scanBoard(black);
//  EXPECT_TRUE(scanner.isValidMove(3, 2));
//  EXPECT_TRUE(scanner.isValidMove(4, 3));
//  EXPECT_TRUE(scanner.isValidMove(5, 6));
//  EXPECT_TRUE(scanner.isValidMove(6, 7));
//  EXPECT_TRUE(scanner.isValidMove(7, 5));
//  EXPECT_TRUE(scanner.isValidMove(3, 5));
//  EXPECT_TRUE(scanner.isValidMove(4, 6));
//  EXPECT_TRUE(scanner.isValidMove(7, 6));
//  EXPECT_TRUE(scanner.isValidMove(6, 7));
//  scanner.scanBoard(white);
//  EXPECT_TRUE(scanner.isValidMove(3, 5));
//  EXPECT_TRUE(scanner.isValidMove(2, 4));
//  EXPECT_TRUE(scanner.isValidMove(8, 4));
//  EXPECT_TRUE(scanner.isValidMove(4, 6));
//  EXPECT_TRUE(scanner.isValidMove(6, 2));
//  EXPECT_TRUE(scanner.isValidMove(5, 2));
//  EXPECT_TRUE(scanner.isValidMove(7, 3));
//  EXPECT_TRUE(scanner.isValidMove(6, 3));
//  EXPECT_FALSE(scanner.isValidMove(4, 4));
//  EXPECT_FALSE(scanner.isValidMove(8, 5));
//}

TEST(BoardScannerTest, SimpleTest) {
  Board *board = new Board(16);
  BoardScanner scanner(board);
  //scan for the correct score for each color
  EXPECT_EQ(scanner.getDisksScore(1), 2);
  EXPECT_EQ(scanner.getDisksScore(0), 2);
  //both players should have available moves at start
  EXPECT_TRUE(scanner.hasMoves(0));
  EXPECT_TRUE(scanner.hasMoves(1));
}

TEST(BoardScannerTest, GameStart) {
  Board *board = new Board(8);
  BoardScanner scanner(board);
  //each initial player should have 4 available moves
  scanner.scanBoard(black);
  EXPECT_TRUE(scanner.isValidMove(6, 5));
  EXPECT_TRUE(scanner.isValidMove(4, 3));
  EXPECT_TRUE(scanner.isValidMove(3, 4));
  EXPECT_TRUE(scanner.isValidMove(5, 6));
  EXPECT_FALSE(scanner.isValidMove(6, 6));
  EXPECT_FALSE(scanner.isValidMove(4, 5));
  scanner.freeMovesList();
  scanner.scanBoard(white);
  EXPECT_TRUE(scanner.isValidMove(3, 5));
  EXPECT_TRUE(scanner.isValidMove(4, 6));
  EXPECT_TRUE(scanner.isValidMove(5, 3));
  EXPECT_TRUE(scanner.isValidMove(6, 4));
  EXPECT_FALSE(scanner.isValidMove(6, 3));
  EXPECT_FALSE(scanner.isValidMove(4, 4));
}

TEST(ScannerTest, EndGame) {
  Board *board = new Board(4);
  BoardScanner scanner(board);
  board->addCell(1, 1, white);
  board->addCell(4, 4, white);
  board->addCell(1, 4, black);
  board->addCell(3, 1, black);
  board->addCell(4, 1, black);
  board->addCell(4, 2, black);
  EXPECT_TRUE(scanner.hasMoves(white));
  scanner.freeMovesList();
  EXPECT_TRUE(scanner.hasMoves(black));
  board->addCell(1, 3, black);
  board->addCell(2, 4, black);
  scanner.freeMovesList();
  EXPECT_FALSE(scanner.hasMoves(white));
  scanner.freeMovesList();
  EXPECT_TRUE(scanner.hasMoves(black));

}

