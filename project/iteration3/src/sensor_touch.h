/**
 * @file sensor_touch.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_TOUCH_H_
#define SRC_SENSOR_TOUCH_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/event_collision.h"
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
 * @brief A representation of a touch sensor.
 *
 * Touch or "bump" sensors are "active" when pressed. For our purposes, imagine
 * a series of bump sensors around the perimeter of the object. A collision will
 * activate the sensor at a particular point of contact, which translates to an
 * angle of contact.
 */
class SensorTouch : public SensorBaseClass {
 public:
   /**
    * @brief Constructor
    */
  SensorTouch();

  /**
   * @brief Get the Point of contact
   */
  Position point_of_contact() { return point_of_contact_; }

  /**
   * @brief Set the Point of contact
   */
  void point_of_contact(Position p) {
    point_of_contact_ = p;
  }

  /**
   * @brief Get the Point of contact
   */
  double angle_of_contact(void) { return angle_of_contact_; }

  /**
   * @brief Set the Angle of contact
   */
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

  /**
   * @brief Compute a new reading based on the collision event.
   *
   * Note that collision events can report "no collision" which
   * will inactivate the sensor.
   *
   */
  void Update(const EventBaseClass * const e) override;

  /**
   * @brief Reset the touch sensor to its newly constructed state.
   */
  void Reset(void) override;

 private:
  Position point_of_contact_;
  double angle_of_contact_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_TOUCH_H_
