/**
 * @file arena_entity_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_PARAMS_H_
#define SRC_ARENA_ENTITY_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include "src/common.h"
#include "src/position.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
 /**
  * @brief Define the parameter for the arena.
  */
struct arena_entity_params {
  /**
  * @brief Constructor
  */
  arena_entity_params(void) : radius(), pos(), color() {}

  /**
  * @brief radius of arena entity
  */
  double radius;

  /**
  * @brief position of arena entity
  */
  Position pos;

  /**
  * @brief color of arena entity
  */
  nanogui::Color color;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_ENTITY_PARAMS_H_
