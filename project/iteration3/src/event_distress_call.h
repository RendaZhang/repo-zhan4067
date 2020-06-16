/**
 * @file event_distress_call.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_DISTRESS_CALL_H_
#define SRC_EVENT_DISTRESS_CALL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include "src/event_base_class.h"
#include "src/position.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A distress event
 */
class EventDistressCall : public EventBaseClass {
 public:
  /**
  * @brief Constructor
  */
  EventDistressCall(void);

  /**
  * @brief Output message to terminal
  */
  void EmitMessage(void) override;

  /**
   * @brief get status of event, if distress event is sensed,
   * return true, else false
   */
  bool get_status(void) const { return status_; }

  /**
  * @brief set status for the distress call event.
  */
  void set_status(bool s) { status_ = s; }

 private:
  bool status_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_DISTRESS_CALL_H_
