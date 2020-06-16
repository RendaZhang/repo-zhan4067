/**
 * @file arena.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_H_
#define SRC_ARENA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include "src/event_keypress.h"
#include "src/event_collision.h"
#include "src/sensor_base_class.h"
#include "src/sensor_touch.h"
#include "src/sensor_proximity.h"
#include "src/sensor_entity_type.h"
#include "src/sensor_distress.h"
#include "src/color.h"
#include "src/motion_handler_super_bot.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
struct arena_params;

/**
 * @brief The main class for the simulation of a 2D world with many robots running
 * around.
 *
 * \ref GraphicsArenaViewer or Tests call \ref AdvanceTime to control the
 * simulation and use the get*() functions to read out the current state of the
 * simulation (i.e., the current positions and orientations of robots and
 * obstacles).
 */
class Arena {
 public:
  /**
  * @brief Constructor for arena
  */
  explicit Arena(const struct arena_params * const params);
  ~Arena(void);

  /**
   * @brief Advance the simulation by the specified # of steps.
   *
   * @param[in] dt The # of steps to increment by.
   */
  void AdvanceTime(double dt);

  /**
  * @brief Handle the key press passed along by the viewer.
  *
  * @param[in] e an event holding the key press.
  *
  */
  void Update(const EventKeypress * const e);

  /**
   * @brief Reset all entities in the arena, effectively restarting the game.
   */
  void Reset(void);

  /**
   * @brief Get # of obstacles in the arena.
   */
  unsigned int n_obstacles(void) { return n_obstacles_; }

  /**
   * @brief Get # of robots in the arena.
   */
  unsigned int n_robots(void) { return n_robots_; }

  /**
   * @brief Get # of status signs in the arena.
   */
  unsigned int n_status_signs(void) { return n_status_signs_; }

  /**
   * @brief Get a list of all obstacles
   */
  std::vector<class Obstacle*> obstacles(void);

  /**
   * @brief Get a list of all robots
   */
  std::vector<class Robot*> robots(void);


  /**
   * @brief Get a list of all status signs
   */
  std::vector<class StatusSign*> status_signs(void);


  /**
  * @brief get the recharge station in arena
  */
  class RechargeStation* recharge_station(void) const {
    return recharge_station_;
  }

  /**
  * @brief get the player in arena
  */
  class Player* player(void) const { return player_; }

  /**
  * @brief Get the home base in arena
  */
  class HomeBase* home_base(void) const { return home_base_; }

 private:
  /**
   * @brief Determine if any entities in the arena are overlapping.
   *
   * @return TRUE if any entities overlap, FALSE if no entities overlap.
   */
  bool any_entities_overlap(void);

  /**
   * @brief Determine if two entities have collided in the arena. Collision is
   * defined as the difference between the extents of the two entities being less
   * than a run-time parameter.
   *
   * @param ent1 Entity #1.
   * @param ent2 Entity #2.
   * @param pointer to a collision event
   *
   * Collision Event is populated appropriately.
   */
  void CheckForEntityCollision(const class ArenaEntity* const ent1,
                               const class ArenaEntity* const ent2,
                               EventCollision * const ec,
                               double collision_delta);

  /**
   * @brief Determine if a particular entity is gone out of the boundaries of
   * the simulation.
   *
   * @param ent The entity to check.
   * @param pointer to a collision event.
   *
   * Collision event is populated appropriately.
   */
  void CheckForEntityOutOfBounds(const class ArenaMobileEntity* const ent,
                                 EventCollision * const ec);

   /**
   * @brief update sensor of player for every timestep
   */
  void UpdatePlayer(void);

  /**
  * @brief update sensor of home base for every timestep
  */
  void UpdateHomeBase(void);

  /**
  * @brief update sensor of robots for every timestep
  */
  void UpdateRobots(void);

  /**
  * @brief check for proximity within range
  */
  double InRange(const class ArenaEntity* const ent1,
               const class ArenaEntity* const ent2,
               double distance);

  /**
  * @brief update the collision event ec
  */
  void UpdateCollisionEvent(class ArenaMobileEntity* ent,
                            EventCollision * const event);

  /**
  * @brief update the proximity event ep
  */
  void UpdateProximityEvent(class ArenaMobileEntity* ent1,
                            class ArenaEntity* ent2,
                            EventProximity * const event,
                            double dist);

 /**
 * @brief helper function to make evert angle positive in range 0 to 360
 */
  double Positive(double angle);

  /**
   * @brief Update all entities for a single timestep
   */
  void UpdateEntitiesTimestep(void);

  // Under certain circumstance, the compiler requires that the copy
  // constructor is not defined. This is deleting the default copy const.
  Arena& operator=(const Arena& other) = delete;
  Arena(const Arena& other) = delete;


  /**
   * @brief Adding sensors to list of sensors
   */
  void RegisterSensor(SensorTouch* s) {
    sensor_touchs_.push_back(s);
  }
  void RegisterSensor(SensorProximity* s) {
    sensor_proximities_.push_back(s);
  }
  void RegisterSensor(SensorEntityType* s) {
    sensor_entity_types_.push_back(s);
  }
  void RegisterSensor(SensorDistress* s) {
    sensor_distresses_.push_back(s);
  }

  /**
   * @brief Removing sensors from list of sensors
   */
  void RemoveSensor(SensorTouch* s) {
      sensor_touchs_.remove(s);
  }
  void RemoveSensor(SensorProximity* s) {
      sensor_proximities_.remove(s);
  }
  void RemoveSensor(SensorEntityType* s) {
      sensor_entity_types_.remove(s);
  }
  void RemoveSensor(SensorDistress* s) {
      sensor_distresses_.remove(s);
  }

  // Dimensions of graphics window inside which players must operate
  double x_dim_;
  double y_dim_;
  unsigned int n_obstacles_;
  unsigned int n_robots_;
  unsigned int n_status_signs_;

  // Entities populating the arena
  Player* player_;
  RechargeStation * recharge_station_;
  HomeBase * home_base_;
  std::vector<Robot*> robots_;
  std::vector<class ArenaEntity*> entities_;
  std::list<class SensorDistress*> sensor_distresses_;
  std::list<class SensorEntityType*> sensor_entity_types_;
  std::list<class SensorProximity*> sensor_proximities_;
  std::list<class SensorTouch*> sensor_touchs_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_H_
