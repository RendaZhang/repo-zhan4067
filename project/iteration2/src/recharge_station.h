/**
 * @file recharge_station.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_RECHARGE_STATION_H_
#define SRC_RECHARGE_STATION_H_

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
  * @brief A class representing a recharge station within the arena that is used
  * to recharge robot batteries.
  */
class RechargeStation: public Obstacle {
 public:
  /**
  * @brief Constructor
  */
  RechargeStation(double radius, const Position& pos,
                  const nanogui::Color& color) :
      Obstacle(radius, pos, color) {}

  /**
  * @brief get the name of the racharge station
  */
  std::string get_name(void) const override {
    return "Recharge Station";
  }
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_RECHARGE_STATION_H_ */
