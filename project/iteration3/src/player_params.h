/**
 * @file player_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_PLAYER_PARAMS_H_
#define SRC_PLAYER_PARAMS_H_

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
  * @brief Inherits from mobile_entity_params to set various
  * properties of the player.
  **/
struct player_params : public arena_mobile_entity_params {
  player_params(void) :
      arena_mobile_entity_params(),
      battery_max_charge(),
      angle_delta(),
      speed_delta(),
      max_speed() {}

  /**
  * @brief max battery charge of player
  */
  double battery_max_charge;

  /**
  * @brief angle delta of player
  */
  uint angle_delta;

  /**
  * @brief speed delta of player
  */
  double speed_delta;

  /**
  * @brief max_speed of player
  */
  double max_speed;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_PLAYER_PARAMS_H_ */
