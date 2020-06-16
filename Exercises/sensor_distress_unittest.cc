/*
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/common.h"
#include "../src/robot.h"
#include "../src/sensor_distress.h"
#include "../src/event_distress.h"

//#ifdef SENSOR_DISTRESS_TEST

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class SensorDistressTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    // Initialize Distress Sensors for Collections of TESTS
    robot = new csci3081::Robot();
    sensor = new csci3081::SensorDistress(robot);
    robot_id = robot->get_id();

    event_own_distress.set_id(robot_id);

    event_internal.set_id(robot_id+1);
    event_internal.set_pos(csci3081::Position(10,0));

    event_at_range.set_id(robot_id+1);
    event_at_range.set_pos(csci3081::Position(50,0));

    event_in_range.set_id(robot_id+1);
    event_in_range.set_pos(csci3081::Position(30,0));

    event_out_of_range.set_id(robot_id+1);
    event_out_of_range.set_pos(csci3081::Position(200,200));
  }

  // Default robot is at position (0,0) heading 0
  csci3081::Robot * robot;
  csci3081::SensorDistress * sensor;
  int robot_id;

  // Default range and fov is 50 and 360 degrees
  csci3081::EventDistress event_own_distress;
  csci3081::EventDistress event_internal;
  csci3081::EventDistress event_in_range;
  csci3081::EventDistress event_at_range;
  csci3081::EventDistress event_out_of_range;

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(SensorDistressTest, Constructor) {
  // get range, fov, and activated
  EXPECT_EQ(sensor->get_range(), DEFAULT_RANGE) << "FAIL: Range:Constructor";
  EXPECT_EQ(sensor->get_fov_angle(), DEFAULT_FOV_ANGLE) << "FAIL: FOV:Constructor";
  EXPECT_EQ(sensor->IsActivated(), false) << "FAIL: Active:Constructor";
 }

TEST_F(SensorDistressTest, DistressCallInRange) {
   // A robot distress in range, not itself
   // should activate the sensor
   sensor->Update(event_in_range);
   EXPECT_EQ(sensor->IsActivated(), true);
 }

TEST_F(SensorDistressTest, DistressCallAtRange) {
   // A robot distress in range, not itself
   // should activate the sensor
   sensor->Update(event_at_range);
   EXPECT_EQ(sensor->IsActivated(), true);
 }

TEST_F(SensorDistressTest, MultipleDistressCalls) {
  // Sensor should stay active until a reset,
  // which Robot will perform at each update
  sensor->Update(event_in_range);
  sensor->Update(event_out_of_range);
  EXPECT_EQ(sensor->IsActivated(), true);
}

TEST_F(SensorDistressTest, Reset) {
  sensor->Reset();
  EXPECT_EQ(sensor->get_range(), DEFAULT_RANGE) << "FAIL: Range, Reset";
  EXPECT_EQ(sensor->get_fov_angle(), DEFAULT_FOV_ANGLE) << "FAIL: FOV, Reset";
  EXPECT_EQ(sensor->IsActivated(), false) << "FAIL: Active, Reset";
}

// Receives notice of event of own distress
// Relies on Reset working properly
TEST_F(SensorDistressTest, EventOfSelf) {
  sensor->Reset();
  sensor->Update(event_own_distress);
  EXPECT_EQ(sensor->IsActivated(), false);
}

TEST_F(SensorDistressTest, DistressCallOutOfRange) {
  sensor->Reset();
  sensor->Update(event_out_of_range);
  EXPECT_EQ(sensor->IsActivated(), false);
}

TEST_F(SensorDistressTest, DistressCallInRobot) {
  sensor->Reset();
  sensor->Update(event_internal);
  EXPECT_EQ(sensor->IsActivated(), true);
}

TEST_F(SensorDistressTest, SetRange) {
  // Bad input that should be ignored
  int range = sensor->get_range();
  sensor->set_range(1000);
  EXPECT_EQ(sensor->get_range(), range) << "FAIL: Too big, Range.";
  sensor->set_range(-10);
  EXPECT_EQ(sensor->get_range(), range) << "FAIL: Negative, Range.";

  // Input should be converted to an int
  sensor->set_range(1.2);
  EXPECT_EQ(sensor->get_range(), 1) << "FAIL: Double, Range";

  // Good input
  sensor->set_range(DEFAULT_RANGE+10);
  EXPECT_EQ(sensor->get_range(), DEFAULT_RANGE+10) << "FAIL: Good, Range";

  // Acceptable input that essentially turns off sensor
  sensor->set_range(0);
  EXPECT_EQ(sensor->get_range(), 0) << "FAIL: Zero, range";
}

TEST_F(SensorDistressTest, SetFovAngle) {

  // Bad input that should be ignored
  int angle = sensor->get_fov_angle();
  sensor->set_fov_angle(-10);
  EXPECT_EQ(sensor->get_fov_angle(), angle) << "FAIL: Negative, FOV.";
  sensor->set_fov_angle(500);
  EXPECT_EQ(sensor->get_fov_angle(), angle) << "FAIL: Too big, FOV.";

  // Input should be converted to an int
  sensor->set_fov_angle(3.1);
  EXPECT_EQ(sensor->get_fov_angle(), 3) << "FAIL: double, FOV";

  // Good input
  sensor->set_fov_angle(DEFAULT_FOV_ANGLE-1);
  EXPECT_EQ(sensor->get_fov_angle(), DEFAULT_FOV_ANGLE-1) << "FAIL: good, FOV";

  // Acceptable input that essentially turns off sensor
  sensor->set_fov_angle(0);
  EXPECT_EQ(sensor->get_fov_angle(), 0) << "FAIL: zero, FOV";
}

//#endif /* SENSOR_DISTRESS_TEST */
