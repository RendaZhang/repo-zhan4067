/**
 * @file sensor_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_PROXIMITY_H_
#define SRC_SENSOR_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/event_proximity.h"
#include "src/sensor_base_class.h"
#include "src/position.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief A representation of a proximity sensor.
 *
 * A proximity sensor should have a range and field of view,
 * such that it has a limited cone in which it can sense objects.
 * A single cone emanating from the center of the robot, split in two,
 * signifies the two fields of view for the two sensors.
 * The range and field of view, expressed as an angle,
 * are attributes of the sensor. Sensor output is the distance to an obstacle.
 * If there is no obstacle, it should output -1.
 */
class SensorProximity : public SensorBaseClass {
 public:
  /**
  * @brief Constructor
  */
  SensorProximity();

  /**
   * @brief Compute a new reading based on the proximity event.
   */
  void Update(const EventBaseClass * const e);

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  void Reset(void) override;

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
  bool sensor_lower_;
  bool sensor_upper_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_PROXIMITY_H_
