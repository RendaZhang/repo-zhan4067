/**
 * @file motion_handler_home_base.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_home_base.h"
#include "src/home_base.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MotionHandlerHomeBase::MotionHandlerHomeBase() {
  set_heading_angle(0);
  set_speed(0);
  set_max_speed(10);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionHandlerHomeBase::Update(ArenaMobileEntity * const ent) {
  HomeBase * home_base = reinterpret_cast<HomeBase*>(ent);
  SensorTouch * st = home_base->get_sensor_touch();
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
  }
}

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
