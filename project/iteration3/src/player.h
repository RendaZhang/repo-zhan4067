/**
 * @file player.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/player_params.h"
#include "src/motion_handler_player.h"
#include "src/motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/robot_battery.h"
#include "src/arena_mobile_entity.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
#include "src/event_command.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile player within the arena.
 *
 * Players have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 */
class Player : public ArenaMobileEntity {
 public:
  /**
  * @brief Constructor
  */
  explicit Player(const struct player_params* const params);

  /**
  * @brief Remove Copy Constructor
  */
  Player(const Player& other) = delete;

  /**
  * @brief remove operator=
  */
  Player& operator=(const Player& other) = delete;

  /**
   * @brief Reset the player to a newly constructed state (needed for reset
   * button to work in arena GUI).
   */
  void Reset(void) override;

  /**
   * @brief Update the player's position and velocity after the specified
   * duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  /**
   * @brief Accept a recharge event.
   *
   * This causes the player's battery to become fully charged.
   *
   * @param e The recharge event.
   */
  void Update(EventRecharge * e);

  /**
   * @brief Handle user input commands to change the heading or speed.
   *
   * @param cmd The command to process.
   */
  void Update(enum event_commands cmd);

  /**
   * @brief Get the current battery level of the player.
   */
  double get_battery_level(void) { return battery_.level(); }

  /**
  * @brief get the heading angle of the player entity
  */
  double get_heading_angle(void) const override {
    return motion_handler_.get_heading_angle();
  }

  /**
  * @brief set the heading angle of the player entity
  */
  void set_heading_angle(double ha) override {
    motion_handler_.set_heading_angle(ha);
  }

  /**
  * @brief get the speed of the player entitys
  */
  double get_speed(void) const override { return motion_handler_.get_speed(); }

  /**
  * @brief set the speed of the player entity
  */
  void set_speed(double sp) override { motion_handler_.set_speed(sp); }

  /**
  * @brief get the name of player entity
  */
  std::string get_name(void) const override {
    return "Player: " + std::to_string(static_cast<int>(battery_.level()));
  }

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

  /**
  * @brief start the freeze timer
  */
  void set_freeze_timer(int t) {
    freeze_timer_ = t;
  }

 private:
  int freeze_timer_;
  double heading_angle_;
  double angle_delta_;
  double speed_delta_;
  RobotBattery battery_;
  MotionHandlerPlayer motion_handler_;
  MotionBehavior motion_behavior_;
  SensorTouch* sensor_touch_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_PLAYER_H_ */
