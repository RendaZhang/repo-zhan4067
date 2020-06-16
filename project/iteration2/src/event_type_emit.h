/**
 * @file event_type_emit.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_TYPE_EMIT_H_
#define SRC_EVENT_TYPE_EMIT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include "src/event_base_class.h"
#include "src/position.h"
#include "src/entity_types.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A type emit event
 */
class EventTypeEmit : public EventBaseClass {
 public:
  /**
  * @brief Constructor
  */
  EventTypeEmit(void);

  /**
  * @brief Output message to terminal
  */
  void EmitMessage(void) override;

  /**
   * @brief get status of event, if type emit event is sensed,
   * return true, else false
   */
  bool get_status(void) const { return status_; }

  /**
  * @brief set status for the type emit event.
  */
  void set_status(bool s) { status_ = s; }

  /**
  * @brief get entity type
  */
  enum entity_types get_entity_type(void) {
    return entity_type_;
  }

  /**
  * @brief set enity type
  */
  void set_entity_type(enum entity_types t) {
    entity_type_ = t;
  }

 private:
  bool status_;
  enum entity_types entity_type_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_TYPE_EMIT_H_
