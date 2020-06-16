/**
 * @file event_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_PROXIMITY_H_
#define SRC_EVENT_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include "src/event_base_class.h"
#include "src/position.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A Proximity event
 */
class EventProximity : public EventBaseClass {
 public:
  /**
  * @brief Constructor
  */
  EventProximity(void);

  /**
  * @brief Output message to terminal
  */
  void EmitMessage(void) override;

  /**
   * @brief get status of event, if proximity event is sensed,
   * return true, else false
   */
  bool get_status(void) const { return status_; }

  /**
  * @brief set status for the proximity event.
  */
  void set_status(bool s) { status_ = s; }

  /**
  * @brief get range
  */
  double get_range(void) const { return range_; }

  /**
  * @brief set range
  */
  void set_range(double r) { range_ = r; }

  /**
  * @brief set lower part of proximity sensor
  */
  bool set_sensor_lower(bool x) {
    sensor_lower_ = x;
  }

  /**
  * @brief set upper part of proximity sensor
  */
  bool set_sensor_upper(bool x) {
    sensor_upper_ = x;
  }

  /**
  * @brief get lower part of proximity sensor
  */
  bool get_sensor_lower(void) {
    return sensor_lower_;
  }

  /**
  * @brief get upper part of proximity sensor
  */
  bool get_sensor_upper(void) {
    return sensor_upper_;
  }

 private:
  bool status_;
  double range_;
  bool sensor_lower_;
  bool sensor_upper_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_PROXIMITY_H_
