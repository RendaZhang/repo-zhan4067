/**
 * @file sensor_proximity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_proximity.h"


/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorProximity::SensorProximity(void) {
  set_fov_angle(DEFAULT_FOV_ANGLE);
  set_range(DEFAULT_RANGE);
  activated(-1);
  set_sensor_lower(false);
  set_sensor_upper(false);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SensorProximity::Update(const EventBaseClass * const e) {
  // Sensor output is the distance (range) to an obstacle.
  // If there is no obstacle, it should output -1.
  EventProximity * event = const_cast<EventProximity *>
    (reinterpret_cast<const EventProximity *>(e));

  if (event->get_status()) {
    activated(event->get_range());
    set_sensor_lower(event->get_sensor_lower());
    set_sensor_upper(event->get_sensor_upper());
  } else {
    activated(-1);
  }
}

void SensorProximity::Reset(void) {
  activated(-1);
} /* reset() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
