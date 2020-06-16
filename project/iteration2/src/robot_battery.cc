/**
 * @file robot_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_battery.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double RobotBattery::Deplete(__unused Position old_pos,
  __unused Position new_pos, __unused double dt) {
  int old_x = old_pos.x;
  int old_y = old_pos.y;
  int new_x = new_pos.x;
  int new_y = new_pos.y;
  double deplete_c;
  if (((old_x != new_x) || (old_y != new_y)) && charge_ > 0) {
    double dist = std::sqrt(std::pow(new_x - old_x, 2) +
                            std::pow(new_y - old_y, 2));
    deplete_c = dist * kLINEAR_SCALE_FACTOR / dt;
    charge_ = charge_ - deplete_c;
    if (charge_ < 0) {
      charge_ = 0;
    }
  }
  return charge_;
} /* deplete() */

void RobotBattery::Update(__unused const EventCollision * const e) {
  if (e->collided()) {
    double deplete_c = max_charge_ / 20;
    charge_ = charge_ - deplete_c;
    if (charge_ < 0) {
      charge_ = 0;
    }
  }
}

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
