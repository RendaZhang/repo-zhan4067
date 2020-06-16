/**
 * @file event_type_emit.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_type_emit.h"
#include "src/arena_mobile_entity.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/
EventTypeEmit::EventTypeEmit() :
  status_(false), entity_type_(kWall) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void EventTypeEmit::EmitMessage(void) {
  printf("Type Emit event, the sensed entity type is %d", entity_type_);
} /* EmitMessage() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
