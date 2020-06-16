/**
 * @file motion_handler_player.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_player.h"
#include "src/player.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MotionHandlerPlayer::MotionHandlerPlayer() {
  set_heading_angle(0);
  set_speed(0);
  set_max_speed(10);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionHandlerPlayer::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
  case COM_TURN_LEFT:
    set_heading_angle(get_heading_angle() - 15);
    break;
  case COM_TURN_RIGHT:
    set_heading_angle(get_heading_angle() + 15);
    break;
  case COM_SPEED_UP:
    if (get_speed() < get_max_speed()) {
      set_speed(get_speed() + 1);
    }
    break;
  case COM_SLOW_DOWN:
    if (get_speed() > 0) {
      set_speed(get_speed() - 1);
    }
    break;
  default:
    std::cerr << "FATAL: bad actuator command" << std::endl;
  } /* switch() */
} /* accept_command() */

void MotionHandlerPlayer::Update(ArenaMobileEntity * const ent) {
  Player * player = reinterpret_cast<Player*>(ent);
  SensorTouch * st = player->get_sensor_touch();
  if (st->activated() == 1) {
    // speed decrease as collision happen
    if (get_speed() > 0) {
      set_speed(get_speed() - 1);
    }

    double point_x = st->point_of_contact().x;
    double point_y = st->point_of_contact().y;
    double angle = st->angle_of_contact();
    if (point_x == 0) {
      // Right or Left wall
      set_heading_angle(180 - angle);
    } else if (point_y == 0) {
      // Top or Bottom wall
      set_heading_angle(- angle);
    } else {
      double deltaD = angle - (std::atan2(point_y, point_x) * 180 / M_PI);
      set_heading_angle(angle + 180 - (2 * deltaD));
    }
  }
}

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
