#include <gtest/gtest.h>
#include "../include/Board.h"
#include "../include/Flip.h"
#include "../include/AI.h"
enum Color { white, black };

TEST(AI_Test, SimpleTest) {
  AI playerAI;
  playerAI.setColor(white);
  EXPECT_EQ(playerAI.getColor(), white);
  playerAI.updateScore(17);
  EXPECT_EQ(playerAI.getScore(), 17);
}

TEST(AI_Test, CorrectMoves) {
  Board *board = new Board(6);
  Flip flip(board);
  AI playerAI;
  playerAI.setColor(white);
  board->addCell(5, 4, black);
  flip.flipBoard(5, 4, black);
  Point p = playerAI.playTurn(board);
  board->addCell(p.getX(), p.getY(), white);
  flip.flipBoard(p.getX(), p.getY(), white);
  EXPECT_EQ(board->cellMatrix[3][5].getColor(), white);
  board->addCell(2, 5, black);
  flip.flipBoard(2, 5, black);
  p = playerAI.playTurn(board);
  board->addCell(p.getX(), p.getY(), white);
  flip.flipBoard(p.getX(), p.getY(), white);
  EXPECT_EQ(board->cellMatrix[1][5].getColor(), white);
  board->addCell(2, 2, black);
  flip.flipBoard(2, 2, black);
  p = playerAI.playTurn(board);
  board->addCell(p.getX(), p.getY(), white);
  flip.flipBoard(p.getX(), p.getY(), white);
  EXPECT_EQ(board->cellMatrix[5][3].getColor(), white);

}