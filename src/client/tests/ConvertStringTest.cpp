#include <gtest/gtest.h>
#include "../include/ConvertString.h"
#include "../include/Point.h"

TEST(ConvertStringTest, SimpleTest) {
  ConvertString convert;
  char *str = convert.convertInt(-1, -1);
}
