/**
 * @file entity_types.h
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 */

#ifndef SRC_ENTITY_TYPES_H_
#define SRC_ENTITY_TYPES_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * @brief an enumerated type entity_type for representing the type of entities.
 */
enum entity_types {
  kRobot,
  kSuperBot,
  kPlayer,
  kHomeBase,
  kRechargeStation,
  kWall
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_ENTITY_TYPES_H_ */
