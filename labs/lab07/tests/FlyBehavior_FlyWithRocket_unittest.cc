#include <gtest/gtest.h>
#include "../src/FlyBehavior.h"
#include <string.h>

TEST(FlyWithRocketTest, Constructor) {
  FlyWithRocket my_flywithrocket;
  string expect_str="Fly with rocket at speed of 20 mph.";
  EXPECT_STREQ(expect_str.c_str(),my_flywithrocket.fly().c_str())<<"FAIL:FlyWithRocket Contructor!";
}
