/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_POSITION_H_
#define SRC_POSITION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple representation of a position of an entity within the arena.
 */
struct Position {
  /**
  * @brief Constructor without argument
  */
  Position(void) : x(0), y(0) {}

  /**
  * @brief Constructor with argument position x and y
  */
  Position(double in_x, double in_y) : x(in_x), y(in_y) { }

  /**
  * @brief overload operator= for Position class
  */
  Position& operator=(const Position& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
  }

  /**
  * @brief x positon
  */
  double x;

  /**
  * @brief y positon
  */
  double y;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_POSITION_H_
