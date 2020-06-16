/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_touch.h"


/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorTouch::SensorTouch(void) :
  point_of_contact_(0, 0),
  angle_of_contact_(0) {
  set_fov_angle(360);
  set_range(0);
  activated(0);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorTouch::Update(const EventBaseClass * const e) {
  // Determine if the sensor should be activated or inactivated (1 or 0).
  EventCollision * event = const_cast<EventCollision *>
    (reinterpret_cast<const EventCollision *>(e));

  // check if it is collided
  if (event->collided()) {
    activated(1);
    point_of_contact_ = event->point_of_contact();
    angle_of_contact_ = event->angle_of_contact();
  } else {
    activated(0);
  }
}

void SensorTouch::Reset(void) {
  point_of_contact(Position(0.0, 0.0));
  angle_of_contact(0.0);
  activated(0);
} /* reset() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
