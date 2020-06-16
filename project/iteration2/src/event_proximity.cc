/**
 * @file event_proximity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_proximity.h"
#include "src/arena_mobile_entity.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/
EventProximity::EventProximity() :
  status_(false),
  range_(0.0),
  sensor_lower_(false),
  sensor_upper_(false) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void EventProximity::EmitMessage(void) {
  printf("Proximity event at range %f", range_);
} /* EmitMessage() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
