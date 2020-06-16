#include <gtest/gtest.h>
#include "../src/Duck.h"
#include <string.h>

TEST(RubberDuckTest, display) {
  RubberDuck my_rubberduck;
  string expect_str="I am a Rubber Duck.";
  EXPECT_STREQ(expect_str.c_str(),my_rubberduck.display().c_str())<<"FAIL:RubberDuck display!";
}

TEST(RubberDuckTest, Constructor) {
  RubberDuck my_rubberduck;
  string expect_str_fly="Cannot fly.";
  string expect_str_quack="Squeak at 2 decibels.";
  EXPECT_STREQ(expect_str_fly.c_str(),my_rubberduck.performFly().c_str())<<"FAIL:RubberDuck Constructor flybehavior!";
  EXPECT_STREQ(expect_str_quack.c_str(),my_rubberduck.performQuack().c_str())<<"FAIL:RubberDuck Constructor quackbehavior!";
}
