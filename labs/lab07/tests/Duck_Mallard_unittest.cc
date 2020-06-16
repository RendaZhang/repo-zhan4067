#include <gtest/gtest.h>
#include "../src/Duck.h"
#include <string.h>

TEST(MallardTest, display) {
  Mallard my_mallard;
  string expect_str="I am a Mallard.";
  EXPECT_STREQ(expect_str.c_str(),my_mallard.display().c_str())<<"FAIL:Mallard display!";
}

TEST(MallardTest, Constructor) {
  Mallard my_mallard;
  string expect_str_fly="Fly with wings at speed of 5 mph.";
  string expect_str_quack="Quack at 10 decibels.";
  EXPECT_STREQ(expect_str_fly.c_str(),my_mallard.performFly().c_str())<<"FAIL:Mallard Constructor flybehavior!";
  EXPECT_STREQ(expect_str_quack.c_str(),my_mallard.performQuack().c_str())<<"FAIL:Mallard Constructor quackbehavior!";
}
