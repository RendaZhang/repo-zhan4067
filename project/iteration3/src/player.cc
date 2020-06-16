/**
 * @file player.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Player::Player(const struct player_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
                    params->pos, params->color),
  freeze_timer_(-1),
  heading_angle_(0),
  angle_delta_(params->angle_delta),
  speed_delta_(params->speed_delta),
  battery_(params->battery_max_charge),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_() {
  motion_handler_.set_heading_angle(270);
  motion_handler_.set_speed(5);
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Player::TimestepUpdate(uint dt) {
  Position old_pos = get_pos();

  if (freeze_timer_ <= 0) {
    // Update heading and speed as indicated by touch sensor
    motion_handler_.Update(this);

    // Use velocity and position to update position
    motion_behavior_.UpdatePosition(this, dt);
  } else {
    freeze_timer_ = freeze_timer_ - 1;
  }

  // Deplete battery as appropriate given distance and speed of movement
  battery_.Deplete(old_pos, get_pos(), dt);
} /* TimestepUpdate() */

void Player::Update(EventRecharge * e) {
  battery_.EventRecharge();

  if (false) {
    e->EmitMessage();
  }
}

void Player::Update(enum event_commands cmd) {
  if (freeze_timer_ <= 0) {
    motion_handler_.AcceptCommand(cmd);
  }
} /* event_cmd() */

void Player::Reset(void) {
  battery_.Reset();
  motion_handler_.Reset();
  sensor_touch_->Reset();
  set_pos(get_init_pos());
  freeze_timer_ = -1;
} /* Reset() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
