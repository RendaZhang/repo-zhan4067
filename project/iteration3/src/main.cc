/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/graphics_arena_viewer.h"
#include "src/arena_params.h"
#include "src/color.h"

/**
* @brief main function
*/
int main(int, char **) {
  // Essential call to initiate the graphics window
  csci3081::InitGraphics();

  // Initialize default start values for various arena entities
  csci3081::player_params pparams;
  pparams.battery_max_charge = 100.0;
  pparams.angle_delta = 10;
  pparams.collision_delta = 0;
  pparams.radius = 40.0;
  pparams.pos = csci3081::Position(500, 500);
  pparams.color = csci3081::Color(253, 254, 200, 255); /* light yellow */

  csci3081::home_base_params hparams;
  hparams.angle_delta = 10;
  hparams.collision_delta = 0;
  hparams.radius = 10.0;
  hparams.pos = {400, 400};
  hparams.color = csci3081::Color(255, 0, 0, 255); /* red */

  csci3081::arena_params aparams;

  aparams.player = pparams;
  aparams.home_base = hparams;

  aparams.recharge_station.radius = 20.0;
  aparams.recharge_station.pos = {500, 300};
  aparams.recharge_station.color = nanogui::Color(0, 128, 128, 255); /* green */

  aparams.obstacles[0].radius = 30.0;
  aparams.obstacles[0].pos = {200, 200};
  aparams.obstacles[0].color = nanogui::Color(167, 163, 163, 255); /* grey */

  aparams.obstacles[1].radius = 30.0;
  aparams.obstacles[1].pos = {800, 100};
  aparams.obstacles[1].color = nanogui::Color(167, 163, 163, 255); /* grey */

  aparams.obstacles[2].radius = 30.0;
  aparams.obstacles[2].pos = {100, 200};
  aparams.obstacles[2].color = nanogui::Color(167, 163, 163, 255); /* grey */

  aparams.obstacles[3].radius = 30.0;
  aparams.obstacles[3].pos = {250, 500};
  aparams.obstacles[3].color = nanogui::Color(167, 163, 163, 255); /* grey */

  aparams.obstacles[4].radius = 30.0;
  aparams.obstacles[4].pos = {500, 200};
  aparams.obstacles[4].color = nanogui::Color(167, 163, 163, 255); /* grey */

  aparams.robots[0].angle_delta = 10;
  aparams.robots[0].collision_delta = 0;
  aparams.robots[0].radius = 10.0;
  aparams.robots[0].pos = {250, 300};
  aparams.robots[0].color = nanogui::Color(255, 255, 255, 255); /* white */

  aparams.robots[1].angle_delta = 10;
  aparams.robots[1].collision_delta = 0;
  aparams.robots[1].radius = 10.0;
  aparams.robots[1].pos = {650, 350};
  aparams.robots[1].color = nanogui::Color(255, 255, 255, 255); /* white */

  aparams.robots[2].angle_delta = 10;
  aparams.robots[2].collision_delta = 0;
  aparams.robots[2].radius = 10.0;
  aparams.robots[2].pos = {350, 290};
  aparams.robots[2].color = nanogui::Color(255, 255, 255, 255); /* white */

  aparams.robots[3].angle_delta = 10;
  aparams.robots[3].collision_delta = 0;
  aparams.robots[3].radius = 10.0;
  aparams.robots[3].pos = {280, 450};
  aparams.robots[3].color = nanogui::Color(255, 255, 255, 255); /* white */

  aparams.robots[4].angle_delta = 10;
  aparams.robots[4].collision_delta = 0;
  aparams.robots[4].radius = 10.0;
  aparams.robots[4].pos = {700, 290};
  aparams.robots[4].color = nanogui::Color(255, 255, 255, 255); /* white */

  aparams.status_signs[0].radius = 30.0;
  aparams.status_signs[0].pos = {500, 40};
  aparams.status_signs[0].color = nanogui::Color(167, 163, 163, 255); /* grey */

  aparams.n_obstacles = 5;
  aparams.n_robots = 5;
  aparams.n_status_signs = 1;
  aparams.x_dim = 1024;
  aparams.y_dim = 768;

  // Start up the graphics (which creates the arena).
  // Run will enter the nanogui::mainloop()
  csci3081::GraphicsArenaViewer *app =
      new csci3081::GraphicsArenaViewer(&aparams);
  app->Run();
  csci3081::ShutdownGraphics();
  return 0;
}
