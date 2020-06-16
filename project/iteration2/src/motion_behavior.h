/**
 * @file motion_behavior.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_BEHAVIOR_H_
#define SRC_MOTION_BEHAVIOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <Eigen/Dense>
#include "src/common.h"
#include "src/arena_mobile_entity.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Manages the modification to the velocity based on user
 * input and collisions.
 *
 * Translates velocity and position to a new position. Both of these are
 * straightforward, but the framework allows for more sophisticated models of
 * motion in which each wheel has distinct speed.
 */
class MotionBehavior {
 public:
  MotionBehavior(void) {}

  /**
   * @brief Update the position for an ArenaEntity, based on its current
   * position and velocity.
   *
   * @param[in] ent The entitity to update.
   * @param dt the number of steps to increment by
   */
  void UpdatePosition(class ArenaMobileEntity * const ent, unsigned int dt);
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_MOTION_BEHAVIOR_H_ */
