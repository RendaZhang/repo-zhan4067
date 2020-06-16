/**
 * @file operator.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_OPERATOR_H_
#define SRC_OPERATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/position.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

struct Position;
/**
* @brief overload == operator for testing equality of position
*/
bool operator==(const Position p1, const Position p2) {
  if (p1.x == p2.x && p1.y == p2.y) {
    return true;
  } else {
    return false;
  }
}

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_OPERATOR_H_
