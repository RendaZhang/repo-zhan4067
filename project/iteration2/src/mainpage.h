/*
 * @file mainpage.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * \section intro_sec Introduction
 *
 * Player is controlled by keyboard input moving indside Arena, and win the game
 * by freezing all robots, and lose the game when all Robot become SuperBot.
 * Robot become SuperBot if it collided with HomeBase. Player have RobotBattery
 * inside, and battery is decreased by time, if batttery is out, lose. Battery
 * is recharge if player collided with RechargeStation.
 * <br><br>
 * Arena have control over all entities and handle all the Events pass to
 * Sensors. Entities are broken down into ArenaMobileEntity and
 * ArenaImmobileEntity. All ArenaMobileEntity have sensors in them to
 * recieve update from arena. All ArenaMobileEntity have MotionHandler
 * to handler speed and heading angle based on sensors.
 * <br><br>
 * The different types of EventBaseClass are: EventCollision, EventCommand,
 * EventDistressCall, EventKeypress, EventProximity, EventRecharge,
 * EventTypeEmit.
 * <br><br>
 * The different types of SensorBaseClass are: SensorDistress,
 * SensorEntityType, SensorProximity, SensorTouch.
 * <br><br>
 * The different MotionHandler are: MotionHandlerHomeBase, MotionHandlerPlayer,
 * MotionHandlerRobot, MotionHandlerSuperBot.
 * <br><br>
 * \section install_sec Installation
 *
 * \subsection libsimplegraphics Installing and Using libsimplegraphics
 *
 * etc...
 *
 *
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

#endif  // SRC_MAINPAGE_H_
