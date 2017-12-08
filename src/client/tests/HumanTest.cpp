#include <gtest/gtest.h>
#include "../include/Human.h"
#include "../include/ColorEnum.h"

TEST(HumanTest, SimpleTest) {
  Human human;
  EXPECT_EQ(human.getColor(), black);
  EXPECT_EQ(human.getScore(), 0);
  human.setColor(white);
  EXPECT_EQ(human.getColor(), white);
  human.updateScore(23);
  EXPECT_EQ(human.getScore(), 23);
}

