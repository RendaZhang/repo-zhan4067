/**
 * @file arena_mobile_entity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void ArenaMobileEntity::TimestepUpdate(uint dt) {
  MotionBehavior h;
  h.UpdatePosition(this, dt);
} /* TimestepUpdate() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
