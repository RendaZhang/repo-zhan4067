/**
 * @file event_keypress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_KEYPRESS_H_
#define SRC_EVENT_KEYPRESS_H_

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
 * @brief An event representing that a key on the keyboard has been
 * pressed.
 *
 * They are sent from the graphics framework to the \ref GraphicsArenaViewer,
 * where they are interpreted further
 */
class EventKeypress : public EventBaseClass {
 public:
  /**
  * @brief Constructor
  */
  explicit EventKeypress(int key) : cmd_(COM_TURN_LEFT), key_(key) {
    cmd_ = keypress_to_cmd(key_);
  }

  /**
  * @brief showing message to terminal
  */
  void EmitMessage(void) override { printf("Keypress command received\n"); }

  /**
  * @brief return commands
  */
  enum event_commands cmd(void) const {
    return cmd_;
  }

 private:
  enum event_commands keypress_to_cmd(int key);
  enum event_commands cmd_;
  int key_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_KEYPRESS_H_ */
