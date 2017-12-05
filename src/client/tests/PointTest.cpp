#include <gtest/gtest.h>
#include "../include/Point.h"

TEST(PointTest, SimpleTest) {
  Point point(5, 6);
  EXPECT_EQ(point.getY(), 6);
  EXPECT_EQ(point.getX(), 5);
  point.increaseGrade(4);
  EXPECT_EQ(point.getGrade(), 4);
  point.increaseGrade(2);
  EXPECT_EQ(point.getGrade(), 6);
}
