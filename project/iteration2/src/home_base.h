/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_HOME_BASE_H_
#define SRC_HOME_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/home_base_params.h"
#include "src/motion_handler_home_base.h"
#include "src/motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/arena_mobile_entity.h"
#include "src/event_collision.h"
/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief Class representing a mobile home base in arena
  */
class HomeBase: public ArenaMobileEntity {
 public:
  /**
  * @brief Constructor
  */
  explicit HomeBase(const struct home_base_params* const params);

  /**
  * @brief get name of Home base
  */
  std::string get_name(void) const override { return "Home Base"; }

  /**
  * @brief reset the home base
  */
  void Reset(void) override;

  /**
  * @brief Update time step for home base
  */
  void TimestepUpdate(unsigned int dt) override;

  /**
  * @brief get the heading angle for home base
  */
  double get_heading_angle(void) const override {
    return motion_handler_.get_heading_angle();
  }

  /**
  * @brief set the heading angle for home base
  */
  void set_heading_angle(double ha) override {
    motion_handler_.set_heading_angle(ha);
  }

  /**
  * @brief get the speed for the home base
  */
  double get_speed(void) const override { return motion_handler_.get_speed(); }

  /**
  * @brief set the speed for the home base
  */
  void set_speed(double sp) override { motion_handler_.set_speed(sp); }

  /**
  * @brief set the touch sensor
  */
  void set_sensor_touch(SensorTouch* st) {
    sensor_touch_ = st;
  }

  /**
  * @brief get the touch sensor
  */
  SensorTouch* get_sensor_touch(void) {
    return sensor_touch_;
  }

 private:
  uint seed_ = 1;

  int id_;
  double heading_angle_;
  double angle_delta_;
  double speed_delta_;
  MotionHandlerHomeBase motion_handler_;
  MotionBehavior motion_behavior_;
  SensorTouch* sensor_touch_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_HOME_BASE_H_ */
