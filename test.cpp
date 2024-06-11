#include <gtest/gtest.h>
//#include <gmock/gmock.h>
#include <stdexcept>
#include "plus_l.cpp"

TEST (sum, test) {
  int a = 2;
  int b = 3;
  EXPECT_EQ(5, slozhi(2, 3));
}
