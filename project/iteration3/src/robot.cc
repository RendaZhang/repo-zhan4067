/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Robot::next_id_ = 1;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot(const struct robot_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
                    params->pos, params->color),
  id_(-1),
  heading_angle_(0),
  angle_delta_(params->angle_delta),
  speed_delta_(params->speed_delta),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_(),
  sensor_proximity_(),
  sensor_distress_(),
  sensor_entity_type_() {
  set_motion_handler(new MotionHandlerRobot());
  id_ = next_id_++;
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Robot::TimestepUpdate(uint dt) {
  // Update heading and speed as indicated by touch sensor
  motion_handler_->Update(this);

  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
} /* TimestepUpdate() */

void Robot::Reset(void) {
  sensor_touch_->Reset();
  set_pos(get_init_pos());
  set_color(nanogui::Color(255, 255, 255, 255));
  set_motion_handler(new MotionHandlerRobot());
  set_entity_type(kRobot);
} /* Reset() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
