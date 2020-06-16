/* STUDENTS: Write your own unit tests in this file.  Or, better yet,
   rename this file to something more meaningful and/or add additional
   files of tests to this directory to test your project code in
   whatever ways you see fit!
 */

// The Google Test framework
#include <gtest/gtest.h>
// Includes for project code in the ../src directory
#include "../src/operator.h"
#include "../src/sensor_touch.h"
#include "../src/sensor_proximity.h"
#include "../src/sensor_distress.h"
#include "../src/sensor_entity_type.h"

// Sensor Touch
TEST(SensorTouch, SanityCheck) {
  csci3081::SensorTouch st;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorTouch>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(st.activated(), 0);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(0, 0));
  EXPECT_EQ(st.angle_of_contact(), 0.0);

  st.activated(1);
  st.point_of_contact(csci3081::Position(1.0, 1.0));
  EXPECT_EQ(st.activated(), 1);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(1.0, 1.0));
}

TEST(SensorTouch, Reset) {
  csci3081::SensorTouch st;

  st.activated(1);
  st.point_of_contact(csci3081::Position(1.0, 1.0));
  st.angle_of_contact(45.0);
  EXPECT_EQ(st.activated(), 1);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(1.0, 1.0));
  EXPECT_DOUBLE_EQ(st.angle_of_contact(), 45.0);

  st.Reset();
  EXPECT_EQ(st.activated(), 0);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(0.0, 0.0));
  EXPECT_DOUBLE_EQ(st.angle_of_contact(), 0.0);
}

TEST(SensorTouch, Update) {
  csci3081::SensorTouch st;

  csci3081::EventCollision event;
  event.collided(true);
  event.point_of_contact(csci3081::Position(1.0, 1.0));
  event.angle_of_contact(45.0);
  st.Update(&event);
  EXPECT_EQ(st.activated(), 1);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(1.0, 1.0));
  EXPECT_DOUBLE_EQ(st.angle_of_contact(), 45.0);

  event.collided(false);
  event.point_of_contact(csci3081::Position(0.0, 0.0));
  event.angle_of_contact(0.0);
  st.Update(&event);
  EXPECT_EQ(st.activated(), 0);
}

// Sensor Proximity
TEST(SensorProximity, SanityCheck) {
  csci3081::SensorProximity sp;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorProximity>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(sp.activated(), -1);
  EXPECT_EQ(sp.get_range(), DEFAULT_RANGE);
  EXPECT_EQ(sp.get_fov_angle(), DEFAULT_FOV_ANGLE);

  sp.activated(45);
  sp.set_range(50.0);
  sp.set_fov_angle(100.0);
  EXPECT_EQ(sp.activated(), 45.0);
  EXPECT_EQ(sp.get_range(), 50.0);
  EXPECT_EQ(sp.get_fov_angle(), 100.0);
}

TEST(SensorProximity, Reset) {
  csci3081::SensorProximity sp;

  sp.activated(45);
  sp.set_range(50.0);
  sp.set_fov_angle(100.0);
  sp.Reset();
  EXPECT_EQ(sp.activated(), -1);
  EXPECT_EQ(sp.get_range(), 50.0);
  EXPECT_EQ(sp.get_fov_angle(), 100.0);
}

TEST(SensorProximity, Update) {
  csci3081::SensorProximity sp;

  csci3081::EventProximity event;
  event.set_status(true);
  event.set_range(45.0);
  sp.Update(&event);
  EXPECT_EQ(sp.activated(), 45.0);

  event.set_status(false);
  event.set_range(70.0);
  sp.Update(&event);
  EXPECT_EQ(sp.activated(), -1);
}

// Sensor Distress
TEST(SensorDistress, SanityCheck) {
  csci3081::SensorDistress sd;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorDistress>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(sd.activated(), 0);
  EXPECT_EQ(sd.get_range(), DEFAULT_RANGE);

  sd.activated(1);
  sd.set_range(50.0);
  EXPECT_EQ(sd.activated(), 1);
  EXPECT_EQ(sd.get_range(), 50.0);
}

TEST(SensorDistress, Reset) {
  csci3081::SensorDistress sd;

  sd.activated(1);
  sd.set_range(50.0);
  sd.Reset();
  EXPECT_EQ(sd.activated(), 0);
  EXPECT_EQ(sd.get_range(), 50.0);
}

TEST(SensorDistress, Update) {
  csci3081::SensorDistress sd;

  csci3081::EventDistressCall event;
  event.set_status(true);
  sd.Update(&event);
  EXPECT_EQ(sd.activated(), 1);

  event.set_status(false);
  sd.Update(&event);
  EXPECT_EQ(sd.activated(), 0);
}

// Sensor EntityType
TEST(SensorEntityType, SanityCheck) {
  csci3081::SensorEntityType et;

  bool val = std::is_base_of<csci3081::SensorBaseClass, csci3081::SensorEntityType>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(et.activated(), -1);
  EXPECT_EQ(et.get_range(), DEFAULT_RANGE);

  et.activated(4);
  et.set_range(50.0);
  EXPECT_EQ(et.activated(), 4);
  EXPECT_EQ(et.get_range(), 50.0);
}

TEST(SensorEntityType, Reset) {
  csci3081::SensorEntityType et;

  et.activated(4);
  et.set_range(50.0);
  et.Reset();
  EXPECT_EQ(et.activated(), -1);
  EXPECT_EQ(et.get_range(), 50.0);
}

TEST(SensorEntityType, Update) {
  csci3081::SensorEntityType et;

  csci3081::EventTypeEmit event;
  event.set_status(true);
  event.set_entity_type(csci3081::kPlayer);
  et.Update(&event);
  EXPECT_EQ(et.activated(), csci3081::kPlayer);

  event.set_status(false);
  et.Update(&event);
  EXPECT_EQ(et.activated(), -1);
}
