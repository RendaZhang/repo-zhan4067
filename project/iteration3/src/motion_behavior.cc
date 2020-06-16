/**
 * @file motion_behavior.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_behavior.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionBehavior::UpdatePosition(ArenaMobileEntity * const ent,
                                         unsigned int dt) {
  // Save position for debugging purposes
  Position new_pos = ent->get_pos();
  Position old_pos = ent->get_pos();

  // Movement is always along the heading_angle (i.e. the hypotenuse)
  new_pos.x += cos(ent->get_heading_angle()*M_PI/180.0)*ent->get_speed()*dt;
  new_pos.y += sin(ent->get_heading_angle()*M_PI/180.0)*ent->get_speed()*dt;
  ent->set_pos(new_pos);
  ent->set_old_pos(old_pos);

  // printf("Updated %s kinematics: old_pos=(%d, %d), new_pos=(%d, %d)\n",
  //        ent->get_name().c_str(), old_pos.x(), old_pos.y(), new_pos.x(),
  //        new_pos.y());
} /* update_position() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
