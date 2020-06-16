/**
 * @file sensor_entity_type.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_entity_type.h"


/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorEntityType::SensorEntityType(void) {
  set_fov_angle(360);
  set_range(DEFAULT_RANGE);
  activated(-1);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SensorEntityType::Update(const EventBaseClass * const e) {
  // Sensor output is the enumerated entity type.
  EventTypeEmit * event = const_cast<EventTypeEmit *>
    (reinterpret_cast<const EventTypeEmit *>(e));

  if (event->get_status()) {
    activated(event->get_entity_type());
    set_entity_type(event->get_entity_type());
  } else {
    activated(-1);
  }
}

void SensorEntityType::Reset(void) {
  activated(-1);
} /* reset() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
