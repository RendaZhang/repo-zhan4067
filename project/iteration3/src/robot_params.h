/**
 * @file robot_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_PARAMS_H_
#define SRC_ROBOT_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity_params.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
 /**
 * @brief robot params struct
 */
struct robot_params : public arena_mobile_entity_params {
  /**
  * @brief Constructor
  */
  robot_params(void) :
      arena_mobile_entity_params(),
      angle_delta(),
      speed_delta(),
      max_speed() {}

  /**
  * @brief angle delta of robot
  */
  uint angle_delta;

  /**
  * @brief speed delta of robot
  */
  double speed_delta;

  /**
  * @brief max speed of robot
  */
  double max_speed;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_ROBOT_PARAMS_H_ */
