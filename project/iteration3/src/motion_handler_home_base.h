/**
 * @file motion_handler_home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_HOME_BASE_H_
#define SRC_MOTION_HANDLER_HOME_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler.h"
#include "src/event_commands.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The motion handler for the homebase. Control the directiona and speed
 * based on the sensor
 */
class MotionHandlerHomeBase : public MotionHandler {
 public:
  /**
  * @brief Constructor
  */
  MotionHandlerHomeBase(void);

  /**
   * @brief Reset the actuators to their newly constructed/un-commanded state.
   */
  void Reset(void) override {
    set_speed(5);
    set_heading_angle(37);
  }

  /**
  * @brief Update home base base on sensor
  */
  void Update(class ArenaMobileEntity * const ent) override;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_MOTION_HANDLER_HOME_BASE_H_ */
