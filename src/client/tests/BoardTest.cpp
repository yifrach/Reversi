#include <gtest/gtest.h>
#include "../include/Board.h"
enum Color { empty = -1, white, black };

TEST(BoardTest, SimpleTest) {
  Board board(8);
  //the board size should be as declared
  EXPECT_EQ(board.getSize(), 8);
  //initial board should have 4 disks
  EXPECT_EQ(board.cellMatrix[4][4].getColor(), white);
  EXPECT_EQ(board.cellMatrix[5][5].getColor(), white);
  EXPECT_EQ(board.cellMatrix[4][5].getColor(), black);
  EXPECT_EQ(board.cellMatrix[5][4].getColor(), black);
  board.addCell(2, 4, black);
  //checking placing a simple cell
  EXPECT_EQ(board.cellMatrix[2][4].getColor(), black);
  board.addCell(2, 4, white);
  //placing it again should simply change the color
  EXPECT_EQ(board.cellMatrix[2][4].getColor(), white);
}