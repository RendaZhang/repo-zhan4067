/**
 * @file home_base.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/home_base.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
HomeBase::HomeBase(const struct home_base_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
                    params->pos, params->color),
  heading_angle_(0),
  angle_delta_(params->angle_delta),
  speed_delta_(params->speed_delta),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_() {
  motion_handler_.set_heading_angle(270);
  motion_handler_.set_speed(5);
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void HomeBase::TimestepUpdate(uint dt) {
  // change the angle at random time
  seed_ = (seed_ + 1) % 10000;
  int rand_n = rand_r(&seed_) % 10 + 1;
  if (rand_n == 4) {
    set_heading_angle(
      (static_cast<int>(get_heading_angle()) + (rand_n * 5)) % 360);
  }

  // Update heading and speed as indicated by touch sensor
  motion_handler_.Update(this);

  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
} /* TimestepUpdate() */

void HomeBase::Reset(void) {
  motion_handler_.Reset();
  sensor_touch_->Reset();
  set_pos(get_init_pos());
} /* Reset() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
