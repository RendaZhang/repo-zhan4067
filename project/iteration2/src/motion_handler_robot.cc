/**
 * @file motion_handler_robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_robot.h"
#include "src/robot.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MotionHandlerRobot::MotionHandlerRobot() {
  set_heading_angle(30);
  set_speed(DEFAULT_ROBOT_SPEED);
  set_max_speed(10);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void MotionHandlerRobot::Update(ArenaMobileEntity * const ent) {
  Robot * robot = reinterpret_cast<Robot*>(ent);
  SensorTouch * st = robot->get_sensor_touch();
  SensorDistress * sd = robot->get_sensor_distress();
  SensorEntityType * et = robot->get_sensor_entity_type();
  SensorProximity * sp = robot->get_sensor_proximity();
  double speed = get_speed();

  // check for collision event first
  if (st->activated() == 1) {
    double point_x = st->point_of_contact().x;
    double point_y = st->point_of_contact().y;
    double angle = st->angle_of_contact();
    if (point_x == 0) {
      // Right or Left wall
      set_heading_angle(180 - angle);
    } else if (point_y == 0) {
      // Top or Bottom wall
      set_heading_angle(- angle);
    } else {
      double deltaD = angle - (std::atan2(point_y, point_x) * 180 / M_PI);
      set_heading_angle(angle + 180 - (2 * deltaD));
    }
  } else {
    // check entity type, Avoid collision if it is not homebase
    if (et->get_entity_type() != kHomeBase) {
      // check for distress call event
      if (sd->activated() == 0) {
        // check for proximity event
        if (sp->activated() != -1) {
          double dist = sp->activated();
          double ratio = 0.5*dist/DEFAULT_RANGE;
          // span both the upper and lower sensors
          if ((sp->get_sensor_lower()) && (sp->get_sensor_upper())) {
            if (speed != 0) {
              set_heading_angle(fmod((get_heading_angle()-10-ratio), 360));
              set_speed(speed - ratio);
            }
          } else if (sp->get_sensor_lower()) {  // in lower sensor
            if (speed != 0) {
              set_heading_angle(fmod((get_heading_angle()-10-ratio), 360));
              set_speed(speed - ratio);
            }
          } else if (sp->get_sensor_upper()) {  // in upper sensor
            if (speed != 0) {
              set_heading_angle(fmod((get_heading_angle()+10+ratio), 360));
              set_speed(speed - ratio);
            }
          }
        } else if (speed != 0) {
          set_speed(DEFAULT_ROBOT_SPEED);
        }
      }
    }
  }
}

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
