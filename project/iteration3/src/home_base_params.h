/**
 * @file home_base_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_HOME_BASE_PARAMS_H_
#define SRC_HOME_BASE_PARAMS_H_

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
 * @brief home base params struct
 */
struct home_base_params : public arena_mobile_entity_params {
  /**
  * @brief Constructor
  */
  home_base_params(void) :
      arena_mobile_entity_params(),
      angle_delta(),
      speed_delta(),
      max_speed() {}

  /**
  * @brief angle delta of home base
  */
  uint angle_delta;

  /**
  * @brief speed delta of home base
  */
  double speed_delta;

  /**
  * @brief max speed of home base
  */
  double max_speed;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_HOME_BASE_PARAMS_H_ */
