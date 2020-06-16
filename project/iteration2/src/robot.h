/**
 * @file robot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/robot_params.h"
#include "src/motion_handler_robot.h"
#include "src/motion_behavior.h"
#include "src/sensor_distress.h"
#include "src/sensor_entity_type.h"
#include "src/sensor_proximity.h"
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
 * @brief use strategy pattern to switch from robot to super_bot
 */
class Robot: public ArenaMobileEntity {
 public:
  /**
  * @brief Constructor
  */
  explicit Robot(const struct robot_params* const params);

  /**
  * @brief get name of Robot
  */
  std::string get_name(void) const override {
    return "Robot" + std::to_string(id_);
  }

  /**
  * @brief reset the robot
  */
  void Reset(void) override;

  /**
  * @brief Update time step for robot
  */
  void TimestepUpdate(unsigned int dt) override;

  /**
  * @brief get the heading angle for robot
  */
  double get_heading_angle(void) const override {
    return motion_handler_->get_heading_angle();
  }

  /**
  * @brief set the heading angle for robot
  */
  void set_heading_angle(double ha) override {
    motion_handler_->set_heading_angle(ha);
  }

  /**
  * @brief get the speed for the robot
  */
  double get_speed(void) const override { return motion_handler_->get_speed(); }

  /**
  * @brief set the speed for the robot
  */
  void set_speed(double sp) override { motion_handler_->set_speed(sp); }

  /**
  * @brief set the motion handler
  */
  void set_motion_handler(MotionHandler* mh) {
    motion_handler_ = mh;
  }

  /**
  * @brief set the touch sensor
  */
  void set_sensor_touch(SensorTouch* st) {
    sensor_touch_ = st;
  }

  /**
  * @brief set the prximity sensor
  */
  void set_sensor_proximity(SensorProximity* sp) {
    sensor_proximity_ = sp;
  }

  /**
  * @brief set the distress sensor
  */
  void set_sensor_distress(SensorDistress* sd) {
    sensor_distress_ = sd;
  }

  /**
  * @brief set the entity type sensor
  */
  void set_sensor_entity_type(SensorEntityType* et) {
    sensor_entity_type_ = et;
  }

  /**
  * @brief get the touch sensor
  */
  SensorTouch* get_sensor_touch(void) {
    return sensor_touch_;
  }

  /**
  * @brief get the prximity sensor
  */
  SensorProximity* get_sensor_proximity(void) {
    return sensor_proximity_;
  }

  /**
  * @brief get the distress sensor
  */
  SensorDistress* get_sensor_distress(void) {
    return sensor_distress_;
  }

  /**
  * @brief get the entity type sensor
  */
  SensorEntityType* get_sensor_entity_type(void) {
    return sensor_entity_type_;
  }

 private:
  static unsigned int next_id_;
  int id_;
  double heading_angle_;
  double angle_delta_;
  double speed_delta_;
  MotionHandler* motion_handler_;
  MotionBehavior motion_behavior_;
  SensorTouch* sensor_touch_;
  SensorProximity* sensor_proximity_;
  SensorDistress* sensor_distress_;
  SensorEntityType* sensor_entity_type_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_ROBOT_H_ */
