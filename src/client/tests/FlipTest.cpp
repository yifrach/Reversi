#include <gtest/gtest.h>
#include "../include/Flip.h"
enum Color { white, black };

TEST(FlipTest, SimpleTest) {
  Board *board = new Board(8);
  Flip flip(board);
  board->addCell(6, 5, black);
  flip.flipBoard(6, 5, black);
  //checking a simple game start flip
  EXPECT_EQ(board->cellMatrix[5][5].getColor(), black);
  EXPECT_EQ(board->cellMatrix[4][5].getColor(), black);
  //same for a white flip
  board->addCell(6, 4, white);
  flip.flipBoard(6, 4, white);
  EXPECT_EQ(board->cellMatrix[5][4].getColor(), white);
  EXPECT_EQ(board->cellMatrix[4][4].getColor(), white);
  //checking for a flip in two directions
  board->addCell(6, 6, white);
  flip.flipBoard(6, 6, white);
  EXPECT_EQ(board->cellMatrix[6][5].getColor(), white);
  EXPECT_EQ(board->cellMatrix[5][5].getColor(), white);
  delete board;
}

TEST(FlipTest, MultipleFlip) {
  Board *board = new Board(6);
  Flip flip(board);
  //creating a board that cant really exist
  board->addCell(3, 1, white);
  board->addCell(3, 5, white);
  board->addCell(4, 4, white);
  board->addCell(5, 1, white);
  board->addCell(6, 3, white);
  board->addCell(1, 3, white);
  board->addCell(2, 3, black);
  board->addCell(3, 2, black);
  board->addCell(4, 2, black);
  board->addCell(5, 3, black);
  board->addCell(5, 5, black);
  flip.flipBoard(3, 3, white);
  //checking it flips correctly in several directions
  EXPECT_EQ(board->cellMatrix[2][3].getColor(), white);
  EXPECT_EQ(board->cellMatrix[3][2].getColor(), white);
  EXPECT_EQ(board->cellMatrix[3][4].getColor(), white);
  EXPECT_EQ(board->cellMatrix[4][2].getColor(), white);
  EXPECT_EQ(board->cellMatrix[4][3].getColor(), white);
  EXPECT_EQ(board->cellMatrix[5][3].getColor(), white);
  EXPECT_EQ(board->cellMatrix[4][4].getColor(), white);
  EXPECT_EQ(board->cellMatrix[5][5].getColor(), black);
  delete board;
}
