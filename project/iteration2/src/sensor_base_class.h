/**
 * @file sensor_base_class.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_BASE_CLASS_H_
#define SRC_SENSOR_BASE_CLASS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"
#include "src/arena_entity.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base sensor class from which all sensors should derive from.
 */
class SensorBaseClass {
 public:
  /**
   * @brief Constructor
   */
  SensorBaseClass(void) {}
  virtual ~SensorBaseClass(void) {}

  /**
   * @brief Get the current activation reading from the sensor.
   */
  int activated(void) { return activated_; }

  /**
   * @brief Set the current activation reading from the sensor.
   */
  void activated(int value) { activated_ = value; }

  /**
   * @brief get the entity whcih it belongs
   */
  class ArenaEntity* get_entity(void) { return entity_; }

  /**
   * @brief Set the entity whcih it belongs
   */
  void set_entity(class ArenaEntity* ent) { entity_ = ent; }

  /**
   * @brief get range
   */
  double get_range(void) {
    return range_;
  }

  /**
   * @brief set range
   */
  void set_range(double r) {
    range_ = r;
  }

  /**
   * @brief get field_of_view
   */
  double get_fov_angle(void) {
    return field_of_view_;
  }

  /**
   * @brief set field_of_view
   */
  void set_fov_angle(double fov) {
    field_of_view_ = fov;
  }

  /**
   * @brief Accept an event (any type of event) from the Arena directly
   */
  virtual void Update(const EventBaseClass * const e) = 0;

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  virtual void Reset(void) = 0;

 private:
  int activated_;
  ArenaEntity* entity_;
  double range_;
  double field_of_view_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_SENSOR_BASE_CLASS_H_ */
