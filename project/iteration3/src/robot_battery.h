/**
 * @file robot_battery.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_BATTERY_H_
#define SRC_ROBOT_BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <cstdio>
#include "src/common.h"
#include "src/event_collision.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The battery for a robot.
 */
class RobotBattery {
 public:
  /**
  * @brief Constructor
  */
  explicit RobotBattery(double max_charge) : charge_(max_charge),
                                             max_charge_(max_charge) {}

  /**
   * @brief All robots consume SOME power, even when just sitting there
   * not moving.
   */
  double kBASE_DEPLETION = 0.001;

  /**
   * @brief The amount of energy consumed by the robot due to its linear speed
   * its is directly proportional to that speed, with a scaling factor.
   */
  double kLINEAR_SCALE_FACTOR = 0.05;

  /**
   * @brief The amount of energy consumed by the robot due to its angular speed
   * its is directly proportional to that speed, with a scaling factor.
   */
  double kANGULAR_SCALE_FACTOR = 0.01;

  /**
   * @brief Get the current battery level.
   */
  double level(void) const { return charge_; }

  /**
   * @brief Handle a recharge event by instantly restoring the robot's battery
   * to its maximum value.
   */
  void EventRecharge(void) { charge_ = max_charge_; }

  /**
   * @brief Reset the robot's battery to its newly constructed/undepleted state.
   */
  void Reset(void) { EventRecharge(); }

  /**
   * @brief Calculate the new battery level based on the current linear/angular
   * speed.
   *
   * @param old_pos The old position
   * @param new_pos The new position
   * @param dt the number of steps to increment by
   *
   * @return The updated battery level.
   */
  double Deplete(__unused Position old_pos,
    __unused Position new_pos, __unused double dt);

  /**
   * @brief This is how the battery can be informed a collision occured.
   * Deplete accordingly.
   *
   * @param e Collision event contain if collided is true or false
   */
  void Update(const EventCollision * const e);

 private:
  double charge_;
  double max_charge_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_BATTERY_H_
