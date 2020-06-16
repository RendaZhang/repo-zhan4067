#include <gtest/gtest.h>
#include "../src/QuackBehavior.h"
#include <string.h>

TEST(SqueakTest, quack) {
  Squeak my_squeak;
  string expect_str="Squeak at 10 decibels.";
  EXPECT_STREQ(expect_str.c_str(),my_squeak.quack().c_str())<<"FAIL:Squeak quack!";
}

TEST(SqueakTest, Contructor){
  Squeak my_squeak(30);
  string expect_str="Squeak at 30 decibels.";
  EXPECT_STREQ(expect_str.c_str(),my_squeak.quack().c_str())<<"FAIL:Squeak Constructor!";
}
