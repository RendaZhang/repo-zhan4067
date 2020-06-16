/**
 * @file motion_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_H_
#define SRC_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity.h"
#include "src/sensor_base_class.h"
#include "src/sensor_distress.h"
#include "src/sensor_entity_type.h"
#include "src/sensor_proximity.h"
#include "src/sensor_touch.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Motion handler abstract class
 */
class MotionHandler {
 public:
  /**
  * @brief Constructor
  */
  MotionHandler(void) {}
  virtual ~MotionHandler(void) {}

  /**
   * @brief Reset the handlers to their newly constructed/un-commanded state.
   */
  virtual void Reset(void) = 0;

  /**
  * @brief Update entity base on the sensors
  */
  virtual void Update(class ArenaMobileEntity * const ent) = 0;

  /**
  * @brief Get the speed
  */
  double get_speed(void) const { return speed_; }

  /**
  * @brief Set the speed
  */
  void set_speed(double sp) { speed_ = sp; }

  /**
  * @brief Get the heading angle
  */
  double get_heading_angle(void) const { return heading_angle_;}

  /**
  * @brief Set the heading angle
  */
  void set_heading_angle(double ha) { heading_angle_ = ha; }

  /**
  * @brief Get the max speed
  */
  double get_max_speed(void) const { return max_speed_; }

  /**
  * @brief Set the max speed
  */
  void set_max_speed(double ms) { max_speed_ = ms; }

 private:
  double heading_angle_;
  double speed_;
  double max_speed_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_MOTION_HANDLER_H_ */
