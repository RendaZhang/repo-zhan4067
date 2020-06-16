/**
 * @file sensor_distress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_distress.h"


/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorDistress::SensorDistress(void) {
  set_fov_angle(360);
  set_range(DEFAULT_RANGE);
  activated(0);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SensorDistress::Update(const EventBaseClass * const e) {
  // Sensor output is 1 for a sensed call and 0 for none.
  EventDistressCall * event = const_cast<EventDistressCall *>
    (reinterpret_cast<const EventDistressCall *>(e));

  if (event->get_status()) {
    activated(1);
  } else {
    activated(0);
  }
}

void SensorDistress::Reset(void) {
  activated(0);
} /* reset() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
