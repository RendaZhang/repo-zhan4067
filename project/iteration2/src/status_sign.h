/**
 * @file status_sign.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_STATUS_SIGN_H_
#define SRC_STATUS_SIGN_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/obstacle.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief A class representing a Status Sign within the arena that is used
  * to represent the game status.
  */
class StatusSign: public Obstacle {
 public:
  /**
  * @brief Constructor
  */
  StatusSign(double radius, const Position& pos,
                  const nanogui::Color& color) :
      Obstacle(radius, pos, color) { name_ = "FUN Game";}

  /**
   * @brief Get the name of the status sign entity
   */
  std::string get_name(void) const override {
    return "" + name_;
  }

  /**
   * @brief Set the name of the status sign entity
   */
  void set_name(std::string name) {
    name_ = name;
  }

  /**
   * @brief Update status sign after the specified
   * duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override {}

 private:
  std::string name_;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_STATUS_SIGN_H_ */
