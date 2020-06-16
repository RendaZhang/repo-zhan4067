/**
 * @file event_keypress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_keypress.h"
#include "src/graphics_arena_viewer.h"
#include "src/player.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
enum event_commands EventKeypress::keypress_to_cmd(int key) {
  switch (key) {
    case 263:
      return COM_TURN_LEFT;
      break;
    case 262:
      return COM_TURN_RIGHT;
      break;
    case 265:
      return COM_SPEED_UP;
      break;
    case 264:
      return COM_SLOW_DOWN;
      break;
    default:
      printf("Unknown keypress: %d\n", key);
  } /* switch() */
} /* keypress_to_cmd() */

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
