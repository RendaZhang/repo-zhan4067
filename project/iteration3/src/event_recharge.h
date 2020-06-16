/**
 * @file event_recharge.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_RECHARGE_H_
#define SRC_EVENT_RECHARGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "src/event_base_class.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An event representing an encounter (really a collision) that a
 * rechargeable object has with a \ref RechargeStation.
 */
class EventRecharge : public EventBaseClass {
 public:
  EventRecharge(void) {}

  void EmitMessage(void) override { printf("Battery recharged!\n"); }
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_RECHARGE_H_ */
