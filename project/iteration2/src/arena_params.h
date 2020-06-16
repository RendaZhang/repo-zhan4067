/**
 * @file arena_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 */

#ifndef SRC_ARENA_PARAMS_H_
#define SRC_ARENA_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player_params.h"
#include "src/home_base_params.h"
#include "src/robot_params.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/

 /**
 * @brief maximum obstavles
 */
#define MAX_OBSTACLES 8

/**
* @brief maximum obstavles
*/
#define MAX_ROBOTS 8

/**
* @brief maximum signs
*/
#define MAX_STATUS_SIGNS 5
/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
 /**
 * @brief Define the parameter for the arena.
 *
 * This includes the arena geometry as well as the parameters for \c ALL
 * entities within the arena.
 */
struct arena_params {
  /**
  * @brief Constructor
  */
  arena_params(void) : player(), recharge_station(), home_base(),
    obstacles(), n_obstacles(), robots(), n_robots(),
    status_signs(), n_status_signs(), x_dim(), y_dim() {}

  /**
  * @brief player struct
  */
  struct player_params player;

  /**
  * @brief recharge station struct
  */
  struct arena_entity_params recharge_station;

  /**
  * @brief home base struct
  */
  struct home_base_params home_base;

  /**
  * @brief obstacles struct
  */
  struct arena_entity_params obstacles[MAX_OBSTACLES];

  /**
  * @brief robots struct
  */
  struct robot_params robots[MAX_ROBOTS];

  /**
  * @brief status signs struct
  */
  struct arena_entity_params status_signs[MAX_STATUS_SIGNS];

  /**
  * @brief number of status signs
  */
  size_t n_status_signs;

  /**
  * @brief number of obstavles
  */
  size_t n_obstacles;

  /**
  * @brief number of obstavles
  */
  size_t n_robots;

  /**
  * @brief x dimension
  */
  uint x_dim;

  /**
  * @brief y dimension
  */
  uint y_dim;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_PARAMS_H_ */
