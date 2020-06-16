/**
 * @file sensor_entity_type.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_ENTITY_TYPE_H_
#define SRC_SENSOR_ENTITY_TYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/event_type_emit.h"
#include "src/sensor_base_class.h"
#include "src/position.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief A representation of a entity type sensor.
 *
 * The type of the entity emitting the signal can be sensed
 * when it is within a defined range, but the direction of
 * the signal cannot be determined.
 */
class SensorEntityType : public SensorBaseClass {
 public:
   /**
    * @brief Constructor
    */
  SensorEntityType();

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

  /**
   * @brief Compute a new reading based on the type emit event.
   */
  void Update(const EventBaseClass * const e) override;

  /**
   * @brief Reset the entity type sensor to its newly constructed state.
   */
  void Reset(void) override;

 private:
  enum entity_types entity_type_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_SENSOR_ENTITY_TYPE_H_
