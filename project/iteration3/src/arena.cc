/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>

#include "src/arena.h"
#include "src/player.h"
#include "src/obstacle.h"
#include "src/robot.h"
#include "src/status_sign.h"
#include "src/event_collision.h"
#include "src/arena_params.h"
#include "src/recharge_station.h"
#include "src/home_base.h"
#include "src/event_recharge.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params* const params) :
  x_dim_(params->x_dim), y_dim_(params->y_dim),
  n_obstacles_(params->n_obstacles),
  n_robots_(params->n_robots),
  n_status_signs_(params->n_status_signs),
  player_(new Player(&params->player)),
  recharge_station_(new RechargeStation(params->recharge_station.radius,
                                        params->recharge_station.pos,
                                        params->recharge_station.color)),
  home_base_(new HomeBase(&params->home_base)),
  robots_(),
  entities_(),
  sensor_distresses_(),
  sensor_entity_types_(),
  sensor_proximities_(),
  sensor_touchs_() {
  // add recharge station to entities
  recharge_station_->set_entity_type(kRechargeStation);
  entities_.push_back(recharge_station_);

  player_->set_heading_angle(37);
  player_->set_entity_type(kPlayer);
  home_base_->set_heading_angle(30);
  home_base_->set_entity_type(kHomeBase);

  // setup sensors for player and home base
  SensorTouch * st_player = new SensorTouch();
  SensorTouch * st_home_base = new SensorTouch();
  player_->set_sensor_touch(st_player);
  home_base_->set_sensor_touch(st_home_base);
  st_player->set_entity(player_);
  st_home_base->set_entity(home_base_);
  RegisterSensor(st_player);
  RegisterSensor(st_home_base);

  // add player and home base to entities
  entities_.push_back(player_);
  entities_.push_back(home_base_);

  // loop to add all the robots to entities
  for (size_t i = 0; i < n_robots_; ++i) {
    Robot * R = new Robot(&params->robots[i]);
    R->set_entity_type(kRobot);

    // setup sensors for Robot
    SensorDistress * sd_r = new SensorDistress();
    SensorEntityType * et_r = new SensorEntityType();
    SensorProximity * sp_r = new SensorProximity();
    SensorTouch * st_r = new SensorTouch();
    R->set_sensor_distress(sd_r);
    R->set_sensor_entity_type(et_r);
    R->set_sensor_proximity(sp_r);
    R->set_sensor_touch(st_r);
    sd_r->set_entity(R);
    et_r->set_entity(R);
    sp_r->set_entity(R);
    st_r->set_entity(R);
    RegisterSensor(sd_r);
    RegisterSensor(et_r);
    RegisterSensor(sp_r);
    RegisterSensor(st_r);

    entities_.push_back(R);
  } /* for(i..) */

  for (size_t i = 0; i < n_obstacles_; ++i) {
    Obstacle * o = new Obstacle(
        params->obstacles[i].radius,
        params->obstacles[i].pos,
        params->obstacles[i].color);
    o->set_entity_type(kWall);
    entities_.push_back(o);
  } /* for(i..) */

  for (size_t i = 0; i < n_status_signs_; ++i) {
    StatusSign * o = new StatusSign(
        params->status_signs[i].radius,
        params->status_signs[i].pos,
        params->status_signs[i].color);
    o->set_entity_type(kWall);
    entities_.push_back(o);
  } /* for(i..) */

  // get the robots
  robots_ = robots();
}

Arena::~Arena(void) {
  for (auto ent : entities_) {
    delete ent;
  } /* for(ent..) */
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Arena::Reset(void) {
  for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
} /* reset() */

std::vector<Obstacle*> Arena::obstacles(void) {
  std::vector<Obstacle*> res;
  for (auto ent : entities_) {
    Obstacle* o = dynamic_cast<Obstacle*>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* obstacles() */

std::vector<Robot*> Arena::robots(void) {
  std::vector<Robot*> res;
  for (auto ent : entities_) {
    Robot* o = dynamic_cast<Robot*>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* robots() */

std::vector<StatusSign*> Arena::status_signs(void) {
  std::vector<StatusSign*> res2;
  for (auto ent : entities_) {
    StatusSign* o = dynamic_cast<StatusSign*>(ent);
    if (o) {
      res2.push_back(o);
    }
  } /* for(ent..) */
  return res2;
} /* status_signs() */

void Arena::AdvanceTime(double dt) {
  if (false) {
    std::cout << "Advancing simulation time by " << dt << " timesteps\n";
  }

  for (size_t i = 0; i < 1; ++i) {
    UpdateEntitiesTimestep();
  } /* for(i..) */
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep(void) {
  /*
   * First, update the position of all entities, according to their current
   * velocities.
   */
  for (auto ent : entities_) {
    ent->TimestepUpdate(1);
  } /* for(ent..) */

  /*
   * Check if the player has collided with the recharge station or the home
   * base.
   */
  UpdatePlayer();
  UpdateHomeBase();
  UpdateRobots();
} /* UpdateEntities() */

void Arena::UpdatePlayer(void) {
  /*
   * check if the player has run out of battery
   */
  double player_battry_level = player_->get_battery_level();
  if (player_battry_level <=0) {
    player_->set_speed(0);
    home_base_->set_speed(0);
    player_->set_freeze_timer(100);
    (Arena::status_signs())[0]->set_name("LOSE!!!");
    for (size_t i = 0; i < robots_.size(); i++) {
      robots_[i]->set_speed(0);
    } /* for(i..) */
  }

  EventCollision ec;

  // freeze robot as collision happen between player and robot
  for (size_t i = 0; i < robots_.size(); i++) {
    CheckForEntityCollision(player_, robots_[i], &ec,
      player_->collision_delta());

    if (ec.collided()) {
      Robot * robot = robots_[i];
      if (robot->get_entity_type() == kRobot) {
        robot->set_speed(0);
      }
      if (robot->get_entity_type() == kSuperBot) {
        player_->set_freeze_timer(40);
      }
    }
  } /* for(i..) */

  CheckForEntityCollision(player_, recharge_station_, &ec,
                          player_->collision_delta());

  if (ec.collided()) {
    EventRecharge er;
    player_->Update(&er);
  }

  SensorTouch* st = player_->get_sensor_touch();

  UpdateCollisionEvent(player_, &ec);

  st->Update(&ec);
}

void Arena::UpdateHomeBase(void) {
  EventCollision ec;
  SensorTouch* st = home_base_->get_sensor_touch();

  UpdateCollisionEvent(home_base_, &ec);

  st->Update(&ec);
}

void Arena::UpdateRobots(void) {
  uint win = 0;
  uint lose = 0;
  // loop through every robot and update the sensors
  for (auto robot : robots_) {
    if ((robot->get_speed() == 0) && (home_base_->get_speed() != 0)) {
      win++;
    }
    if (robot->get_entity_type() == kSuperBot) {
      lose++;
    }

    // create all the events
    EventCollision ec = EventCollision();
    EventDistressCall dc = EventDistressCall();
    EventTypeEmit te = EventTypeEmit();
    EventProximity ep = EventProximity();

    // get the sensors for update
    SensorTouch* st = robot->get_sensor_touch();
    SensorDistress* sd = robot->get_sensor_distress();
    SensorEntityType* et = robot->get_sensor_entity_type();
    SensorProximity* sp = robot->get_sensor_proximity();


    // loop through entity to check for type emit event
    for (auto ent : entities_) {
      if (ent == robot) {
        continue;
      }
      double dist = ProximityInRange(robot, ent, DEFAULT_RANGE);
      if (dist != -1) {
        // check for distress call event
        if (ent->get_entity_type() == kRobot) {
          Robot* R = reinterpret_cast<Robot*>(ent);
          if (R->get_speed() == 0) {
            // distress call event
            dc.set_status(true);
          }
        }

        // type emit event
        te.set_status(true);
        te.set_entity_type(ent->get_entity_type());

        // proximity event
        UpdateProximityEvent(robot, ent, &ep, dist);

        break;
      }
    }

    UpdateRobotCollisionEvent(robot, &ec);

    // update the sensors
    st->Update(&ec);  // touch sensor
    sd->Update(&dc);  // distress sensor
    et->Update(&te);  // entity type sensor
    sp->Update(&ep);  // proximity sensor
  }

  // check if player wins
  if (win >= (robots_.size()-lose)) {
    player_->set_speed(0);
    home_base_->set_speed(0);
    player_->set_freeze_timer(100);
    (Arena::status_signs())[0]->set_name("WIN!!!");
    for (size_t i = 0; i < robots_.size(); i++) {
      robots_[i]->set_speed(0);
    } /* for(i..) */
  }

  // check if player loses
  if (lose >= robots_.size()) {
    player_->set_speed(0);
    home_base_->set_speed(0);
    player_->set_freeze_timer(100);
    (Arena::status_signs())[0]->set_name("LOSE!!!");
    for (size_t i = 0; i < robots_.size(); i++) {
      robots_[i]->set_speed(0);
    } /* for(i..) */
  }
}

void Arena::UpdateRobotCollisionEvent(Robot * robot,
                                      EventCollision * const event) {
  // Check if it is out of bounds. If so, use that as point of contact.
  CheckForEntityOutOfBounds(robot, event);

  // If not at wall, check if it is colliding with any other entities (not
  // itself)
  if (!event->collided()) {
    for (auto ent : entities_) {
      if (ent == robot) {
        continue;
      }
      CheckForEntityCollision(robot, ent, event, robot->collision_delta());
      if (event->collided()) {
        if (ent->get_entity_type() == kRobot) {
          Robot* R = reinterpret_cast<Robot*>(ent);
          if (R->get_speed() == 0) {
            R->set_speed(DEFAULT_ROBOT_SPEED);
          }
        }

        // robot become super bot as it collied with home base
        if (ent->get_entity_type() == kHomeBase) {
          robot->set_color(nanogui::Color(205, 24, 24, 255));
          double speed = DEFAULT_ROBOT_SPEED;
          double angle = robot->get_heading_angle();
          robot->set_motion_handler(new MotionHandlerSuperBot(speed, angle));
          robot->set_entity_type(kSuperBot);
        }
        break;
      }
    } /* for(i..) */
  } /* else */
  if (event->collided()) {
    robot->set_pos(robot->get_old_pos());
  }
}

void Arena::UpdateCollisionEvent(ArenaMobileEntity * ent,
                                 EventCollision * const event) {
  // Check if it is out of bounds. If so, use that as point of contact.
  CheckForEntityOutOfBounds(ent, event);

  // If not at wall, check if it is colliding with any other entities (not
  // itself)
  if (!event->collided()) {
    for (size_t i = 0; i < entities_.size(); ++i) {
      if (entities_[i] == ent) {
       continue;
      }
      CheckForEntityCollision(ent, entities_[i], event, ent->collision_delta());
      if (event->collided()) {
       break;
      }
    } /* for(i..) */
  } /* else */
  if (event->collided()) {
    ent->set_pos(ent->get_old_pos());
  }
}

void Arena::CheckForEntityOutOfBounds(const ArenaMobileEntity * const ent,
                                     EventCollision * const event) {
  // Angle of reflection should be 180-heading for walls
  uint right = x_dim_ - 100;
  uint left = 100;
  uint bottom = y_dim_ - 100;
  uint top = 100;
  if (ent->get_pos().x + ent->get_radius() >= right) {
    // Right Wall
    event->collided(true);
    event->point_of_contact(Position(0, ent->get_pos().y));
    event->angle_of_contact(ent->get_heading_angle());
  } else if (ent->get_pos().x - ent->get_radius() <= left) {
    // Left Wall
    event->collided(true);
    event->point_of_contact(Position(0, ent->get_pos().y));
    event->angle_of_contact(ent->get_heading_angle());
  } else if (ent->get_pos().y + ent->get_radius() >= bottom) {
    // Bottom Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x, 0));
    event->angle_of_contact(ent->get_heading_angle());
  } else if (ent->get_pos().y - ent->get_radius() <= top) {
    // Top Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x, 0));
    event->angle_of_contact(ent->get_heading_angle());
  } else {
    event->collided(false);
  }
} /* entity_out_of_bounds() */

void Arena::CheckForEntityCollision(const ArenaEntity* const ent1,
  const ArenaEntity* const ent2, EventCollision * const event,
  double collision_delta) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;
  double ent1_r = ent1->get_radius();
  double ent2_r = ent2->get_radius();
  double dist = std::sqrt(std::pow(ent2_x - ent1_x, 2) +
                          std::pow(ent2_y - ent1_y, 2));
  if (dist > ent1_r + ent2_r + collision_delta) {
    event->collided(false);
  } else {
    // Populate the collision event.
    // Collided is true
    // Point of contact is point along perimeter of ent1
    // Angle of contact is angle to that point of contact
    event->collided(true);
    // double point_x
    //   = (ent1_r / (ent1_r + ent2_r) ) * (ent2_x - ent1_x) + ent1_x;
    // double point_y
    //   = (ent1_r / (ent1_r + ent2_r) ) * (ent2_y - ent1_y) + ent1_y;
    double deltaX = ent1_x - ent2_x;
    double deltaY = ent1_y - ent2_y;
    // passing the difference between collision objects's coordinates
    event->point_of_contact(Position(deltaX, deltaY));
    // type casting
    ArenaMobileEntity * ent = const_cast<ArenaMobileEntity *>
      (reinterpret_cast<const ArenaMobileEntity *>(ent1));
    double ent1_angle = ent->get_heading_angle();
    event->angle_of_contact(ent1_angle);
  }
} /* entities_have_collided() */

double Arena::ProximityInRange(const ArenaEntity* const ent1,
                      const ArenaEntity* const ent2,
                      double distance) {
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;
  // double ent1_r = ent1->get_radius();
  double ent2_r = ent2->get_radius();

  double deltaX = ent1_x - ent2_x;
  double deltaY = ent1_y - ent2_y;
  double dist = std::sqrt(std::pow(deltaX, 2.0) + std::pow(deltaY, 2.0));
  if (dist > (distance + ent2_r)) {
    return -1;
  } else {
    return dist;
  }
}

void Arena::UpdateProximityEvent(ArenaMobileEntity * ent1,
                                 ArenaEntity * ent2,
                                 EventProximity * const event,
                                 double dist) {
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;
  // double ent1_r = ent1->get_radius();
  double ent2_r = ent2->get_radius();
  double heading_angle = ent1->get_heading_angle();
  double fov = DEFAULT_FOV_ANGLE;

  double deltaX = ent1_x - ent2_x;
  double deltaY = ent1_y - ent2_y;

  double triangle_theta = PositiveAngle(std::atan(ent2_r/dist)*180/M_PI);
  double distance_theta = PositiveAngle(std::atan2(deltaY, deltaX)*180/M_PI);

  double sensor_lower = PositiveAngle(heading_angle - floor(fov / 2) + 180);
  double sensor_upper = PositiveAngle(heading_angle + floor(fov / 2) + 180);
  double sensed_lower = PositiveAngle(distance_theta - triangle_theta);
  double sensed_upper = PositiveAngle(distance_theta + triangle_theta);

  double distToCrossing;
  if (sensor_lower > sensor_upper) {
    distToCrossing = 360 - sensor_lower;
    sensor_lower = fmod((sensor_lower + distToCrossing), 360);
    sensor_upper = sensor_upper + distToCrossing;
    sensed_lower = fmod((sensed_lower + distToCrossing), 360);
    sensed_upper = fmod((sensed_upper + distToCrossing), 360);
  }
  if (sensed_lower > sensed_upper) {
    distToCrossing = 360 - sensed_lower;
    sensor_lower = fmod((sensor_lower + distToCrossing), 360);
    sensor_upper = sensor_upper + distToCrossing;
    sensed_lower = fmod((sensed_lower + distToCrossing), 360);
    sensed_upper = fmod((sensed_upper + distToCrossing), 360);
  }

  // in lower proximity sensor
  if ((sensed_lower >= sensor_lower) && (sensed_lower <= sensor_upper)) {
    event->set_status(true);
    event->set_sensor_lower(true);
    event->set_range(dist - ent2_r);
  }
  // in upper proximity sensor
  if ((sensed_upper >= sensor_lower) && (sensed_upper <= sensor_upper)) {
    event->set_status(true);
    event->set_sensor_upper(true);
    event->set_range(dist - ent2_r);
  }
}

double Arena::PositiveAngle(double angle) {
  if (angle < 0) {
    return (360 + angle);
  }
  if (angle > 360) {
    return fmod(angle, 360);
  }
  return angle;
}

void Arena::Update(const __unused EventKeypress * const e) {
  player_->Update(e->cmd());
}

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
