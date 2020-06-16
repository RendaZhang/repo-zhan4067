/**
 * @file event_distress_call.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_distress_call.h"
#include "src/arena_mobile_entity.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/
EventDistressCall::EventDistressCall() :
  status_(false) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void EventDistressCall::EmitMessage(void) {
  printf("Distress event happen");
} /* EmitMessage() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
