#include <gtest/gtest.h>
#include "../include/Cell.h"
enum Color { empty = -1, white, black };

//Simple test for our cell class
TEST(CellTest, SimpleTest) {
  Cell cell;
  //our cell's default needs to be an empty one
  EXPECT_EQ(cell.getColor(), empty);
  //flipping an empty cell should not change it
  cell.flip();
  EXPECT_EQ(cell.getColor(), empty);
  cell.changeColor(black);
  //getting the flipped color should not flip the actual cell
  cell.getFlip();
  EXPECT_EQ(cell.getColor(), black);
  cell.flip();
  //lastly checking the cell actually gets flipped
  EXPECT_EQ(cell.getColor(), white);
  cell.flip();
  EXPECT_EQ(cell.getColor(), black);
  cell.changeColor(empty);
  EXPECT_EQ(cell.getColor(), empty);
}



