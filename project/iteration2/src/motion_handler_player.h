/**
 * @file motion_handler_player.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_PLAYER_H_
#define SRC_MOTION_HANDLER_PLAYER_H_

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
 * @brief Motion handler for player
 */
class MotionHandlerPlayer : public MotionHandler {
 public:
  /**
  * @brief Constructor
  */
  MotionHandlerPlayer(void);

  /**
   * @brief Reset the actuators to their newly constructed/un-commanded state.
   */
  void Reset(void) {
    set_speed(5);
    set_heading_angle(37);
  }

  /**
   * @brief Command from user keypress via the viewer.
   *
   * @param cmd The command.
   */
  void AcceptCommand(enum event_commands cmd);

  /**
  * @brief Update player base on sensor
  */
  void Update(class ArenaMobileEntity * const ent) override;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_MOTION_HANDLER_PLAYER_H_ */
