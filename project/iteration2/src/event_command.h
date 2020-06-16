/**
 * @file event_command.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_COMMAND_H_
#define SRC_EVENT_COMMAND_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "src/event_base_class.h"
#include "src/event_commands.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An event representing a keypress command from the user that should be
 * sent to the player.
 */
class EventCommand : public EventBaseClass {
 public:
  /**
  * @brief Constructor
  */
  explicit EventCommand(enum event_commands cmd) : cmd_(cmd) {}

  /**
  * @brief Send message to terminal
  */
  void EmitMessage(void) override { printf("Motion cmd %d received\n", cmd_); }

  /**
  * @brief Get the command
  */
  enum event_commands cmd(void) const { return cmd_; }

 private:
  enum event_commands cmd_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_COMMAND_H_ */
