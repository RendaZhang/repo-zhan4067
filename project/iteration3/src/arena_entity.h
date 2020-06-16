/**
 * @file arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_H_
#define SRC_ARENA_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>
#include "src/common.h"
#include "src/position.h"
#include "src/color.h"
#include "src/entity_types.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A base class representing an entity within the arena. All entities
 * within the arena know how to :
 *
 * 1. Update themselves each timestep (i.e. in accordance with current velocity
 *    and position).
 *
 * 2. Reset themselves to a newly constructed state. This is so the user can
 *    click the reset button after completing a game and have things work as
 *    expected.
 *
 * Please note that here use the upper-left coordinate, which means that the
 * origin point (0.0,0.0) is at the upper left.
 *
 * Also, all arena entities are circular.
 */
class ArenaEntity {
 public:
 /**
  * @brief Constructor
  */
  ArenaEntity(double radius, const Position& pos,
              const nanogui::Color& color) :
      radius_(radius), pos_(pos), color_(color),
      init_pos_(pos), old_pos_(pos), entity_type_(kWall) {}
  virtual ~ArenaEntity(void) {}

  /**
   * @brief Perform whatever updates are needed for a particular entity after 1
   * timestep (updating position, changing color, etc.).
   */
  virtual void TimestepUpdate(__unused uint dt) {}

  /**
   * @brief Reset the entity to its newly constructed state.
   */
  virtual void Reset(void) {}

  /**
   * @brief Get the name of an entity for visualization purposes, to aid in
   * debugging.
   */
  virtual std::string get_name(void) const = 0;

  /**
   * @brief Set the position of the home base entity
   */
  void set_pos(const Position& pos) { pos_ = pos; }

  /**
   * @brief Get the position of the home base entity
   */
  const Position& get_pos(void) const { return pos_; }

  /**
   * @brief Get the color of the home base entity
   */
  const nanogui::Color& get_color(void) const { return color_; }

  /**
   * @brief Set the color of the home base entity
   */
  void set_color(const nanogui::Color& color) { color_ = color; }

  /**
   * @brief Get the radius of an entity.
   */
  double get_radius(void) const { return radius_; }

  /**
   * @brief Get the initial position of a home base entity.
   */
  const Position& get_init_pos(void) const {return init_pos_;}

  /**
   * @brief Get the old Position of an home base entity.
   */
  const Position& get_old_pos(void) const {return old_pos_;}

  /**
   * @brief Set the old position of an home base entity.
   */
  void set_old_pos(const Position& pos) { old_pos_ = pos; }

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
  double radius_;
  Position pos_;
  nanogui::Color color_;
  Position init_pos_;
  Position old_pos_;
  enum entity_types entity_type_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_ENTITY_H_
