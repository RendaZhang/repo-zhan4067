/**
 * @file sensor_distress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_DISTRESS_H_
#define SRC_SENSOR_DISTRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/event_distress_call.h"
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
 * @brief A representation of a distress sensor.
 *
 * The distress signal can be sensed when it is within a defined range,
 * but the direction of the signal cannot be determined.
 */
class SensorDistress : public SensorBaseClass {
 public:
   /**
    * @brief Constructor
    */
  SensorDistress();

  /**
   * @brief Compute a new reading based on the distress call event.
   */
  void Update(const EventBaseClass * const e);

  /**
   * @brief Reset the distress sensor to its newly constructed state.
   */
  void Reset(void) override;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_DISTRESS_H_
