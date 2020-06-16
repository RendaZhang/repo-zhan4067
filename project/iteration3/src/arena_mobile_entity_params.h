/**
 * @file arena_mobile_entity_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_PARAMS_H_
#define SRC_ARENA_MOBILE_ENTITY_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_entity_params.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief Define the parameters for a mobile entity within the arena.
 */
struct arena_mobile_entity_params : public arena_entity_params {
  arena_mobile_entity_params(void) : arena_entity_params(),
                                     collision_delta() {}

  /**
  * @brief Minimum distance between entities that qualifies as a collision.
  */
  double collision_delta;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_ARENA_MOBILE_ENTITY_PARAMS_H_ */
