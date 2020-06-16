/**
 * @file graphics_arena_viewer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_GRAPHICS_ARENA_VIEWER_H_
#define SRC_GRAPHICS_ARENA_VIEWER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <simple_graphics/graphics_app.h>
#include "src/arena.h"
#include "src/common.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 *  @brief An application that uses the cs3081 SimpleGraphics library to open up
 *  a window that includes a few buttons for controlling the simulation and can
 *  be used to draw circles and other computer graphics.
 *
 *  After constructing a new RobotViewer, call Run() to start and run the
 *  application.  Run() will not return until the application window is closed.
 *  Make sure that you call cs3081::InitGraphics() before creating the
 *  RobotViewer app.  Example:
 *
 *  ```
 *  int main(int argc, char **argv) {
 *      cs3081::InitGraphics();
 *      RobotViewer *app = new RobotViewer();
 *      app->Run();
 *      cs3081::ShutdownGraphics();
 *      return 0;
 *  }
 *  ```
 *
 *  While the window is open \ref UpdateSimulation() will be called repeatedly,
 *  once per frame.  Fill this in to update your simulation or perform any other
 *  processing that should happen over time as the simulation progresses.
 *
 *  Fill in the On*() methods as desired to respond to user input events.
 *
 *  Fill in the Draw*() methods to draw graphics to the screen using
 *  either the nanovg library or raw OpenGL.
 */
class GraphicsArenaViewer : public GraphicsApp {
 public:
   /**
   * @brief constructor
   */
  explicit GraphicsArenaViewer(const struct arena_params* const params);

  /**
  * @brief virtual constructor
  */
  virtual ~GraphicsArenaViewer(void) { delete arena_; }

  /**
   * @brief Informs the arena of the new time, so that it can update.
   */
  void UpdateSimulation(double dt) override;

  /**
   * @brief Handle the user pressing the restart button on the GUI.
   */
  void OnRestartBtnPressed();

  /**
   * @brief Handle the user pressing the pause button on the GUI.
   */
  void OnPauseBtnPressed();

  /**
   * @brief Called each time the mouse moves on the screen within the GUI
   * window.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x X position of the cursor.
   * @param[in] y Y position of the cursor.
   */
  void OnMouseMove(int x, int y) override;

  /**
   * @brief Called each time the left mouse button is clicked.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the click.
   * @param[in] y The Y position of the click.
   */
  void OnLeftMouseDown(int x, int y) override;

  /**
   * @brief Called each time the left mouse button is released.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the release.
   * @param[in] y The Y position of the release.
   */
  void OnLeftMouseUp(int x, int y) override;

  /**
   * @brief Called each time the right mouse button is clicked.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the click.
   * @param[in] y The Y position of the click.
   */

  void OnRightMouseDown(int x, int y) override;

  /**
   * @brief Called each time the right mouse button is released.
   *
   * Origin is at the lower left of the window.
   *
   * @param[in] x The X position of the release.
   * @param[in] y The Y position of the release.
   */
  void OnRightMouseUp(int x, int y) override;

  /**
   * @brief Called each time a character key is pressed.
   *
   * @param[in] c Character representing a key that was pressed.
   * @param[in] modifiers Any modifier keys that were also pressed.
   */
  void OnKeyDown(const char *c, int modifiers) override;

  /**
   * @brief Called each time a character key is released.
   *
   * @param[in] c Character representing a key that was released.
   * @param[in] modifiers Any modifier keys that were held with the key.
   */
  void OnKeyUp(const char *c, int modifiers) override;

  /**
   * @brief Called each time a special (non-alphabetic) key is pressed.
   *
   * @param[in] key The key that was pressed.
   * @param[in] scancode The scancode corresponding to the key.
   * @param[in] modifiers Any modifiers that were also pressed.
   */
  void OnSpecialKeyDown(int key, int scancode, int modifiers) override;

  /**
   * @brief Called each time a special (non-alphabetic) key is released.
   *
   * @param[in] key The key that was released.
   * @param[in] scancode The scancode corresponding to the key.
   * @param[in] modifiers Any modifiers that were also pressed.
   */
  void OnSpecialKeyUp(int key, int scancode, int modifiers) override;

  /**
   * @brief Draw the arena with all robots, obstacles using nanogui.
   *
   * This is the primary driver for drawing all entities in the arena.  It is
   *  called at each iteration of nanogui::mainloop().
   *
   * @param[in] ctx Context for nanogui.
   */
  void DrawUsingNanoVG(NVGcontext *ctx) override;

  /**
   * @brief Draw using OpenGL. This callback had to be defined, but we are doing
   * all drawing with nanovg in this application, so it is empty.
   */
  void DrawUsingOpenGL(void) override {}

  /**
  * @brief get the arena class
  */
  Arena* arena(void) const { return arena_; }

 private:
  /**
   * @brief Draw a player using nanogui.
   *
   * This function requires an active nanovg drawing context (ctx), so it should
   * probably only be called from with \ref DrawUsingNanoVG().
   *
   * @param[in] ctx The nanogui context.
   * @param[in] player The player handle.
   */
  void DrawPlayer(NVGcontext *ctx, const class Player* const player);

  /**
   * @brief Draw an obstacle in the arena using nanogui.
   *
   * This function requires an active nanovg drawing context (ctx), so it should
   * probably only be called from with \ref DrawUsingNanoVG().
   *
   * @param[in] ctx The nanogui context.
   * @param[in] obstacle The obstacle handle.
   */
  void DrawObstacle(NVGcontext *ctx, const class Obstacle* const obstacle);

  /**
   * @brief Draw a robot in the arena using nanogui.
   *
   * This function requires an active nanovg drawing context (ctx), so it should
   * probably only be called from with \ref DrawUsingNanoVG().
   *
   * @param[in] ctx The nanogui context.
   * @param[in] robot The robot handle.
   */
  void DrawRobot(NVGcontext *ctx, const class Robot* const robot);

  /**
   * @brief Draw a status sign in the arena using nanogui.
   *
   * This function requires an active nanovg drawing context (ctx), so it should
   * probably only be called from with \ref DrawUsingNanoVG().
   *
   * @param[in] ctx The nanogui context.
   * @param[in] status sign The status sign handle.
   */
  void DrawStatusSign(NVGcontext *ctx,
    const class StatusSign* const status_sign);

  /**
   * @brief Draw the home base using nanogui.
   *
   * @param[in] ctx The nanogui context.
   * @param[in] home The home base handle.
   */
  void DrawHomeBase(NVGcontext *ctx, const class HomeBase* const home);


  /**
   * @brief Draw the sensors from a robot using nanogui.
   *
   * @param[in] ctx The nanogui context.
   * @param[in] robot The robot handle.
   * @param[in] sensor_angle The field of view of the robot's sensor.
   * @param[in] sensor_dist The range of the sensor.
   */
  void DrawRobotSensor(NVGcontext *ctx, const class Robot* const robot,
                        double sensor_angle, double sensor_dist);

  /**
  * @brief pointer to arena class
  */
  Arena *arena_;

  /**
  * @brief boolean for setting pause button
  */
  bool paused_;

  /**
  * @brief pause button in nanogui
  */
  nanogui::Button *pause_btn_;

  /**
  * @brief use in TimestepUpdate()
  */
  double last_dt;

  /**
  * @brief Satisfies compilers warning that the copy constructor should exist.
  */
  GraphicsArenaViewer& operator=(const GraphicsArenaViewer& other) = delete;

  /**
  * @brief Satisfies compilers warning that the copy constructor should exist
  */
  GraphicsArenaViewer(const GraphicsArenaViewer& other) = delete;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif  // SRC_GRAPHICS_ARENA_VIEWER_H_
