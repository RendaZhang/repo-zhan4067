/**
 * @file common.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

/*!
 * csci3081 begin
 */
#define NAMESPACE_BEGIN(name) namespace name {
/*!
 * csci3081 end
 */
#define NAMESPACE_END(name) }

 /**
 * @brief This should be placed in front of any variable defined but not used to
 * satisfy the compiler - otherwise a warning is given.
 */
#define __unused __attribute__((unused))

/**
* @brief the maximum range in which the sensor can sensed
*/
#define DEFAULT_RANGE 40

/**
* @brief the maximum field of view in degrees
*/
#define DEFAULT_FOV_ANGLE 120

/**
* @brief the default speed of robot
*/
#define DEFAULT_ROBOT_SPEED 5

#endif /* SRC_COMMON_H_ */
