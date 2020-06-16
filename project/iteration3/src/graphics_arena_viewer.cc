/**
 * @file graphics_arena_viewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/graphics_arena_viewer.h"
#include <iostream>
#include <string>
#include <vector>

#include "src/player.h"
#include "src/home_base.h"
#include "src/obstacle.h"
#include "src/robot.h"
#include "src/status_sign.h"
#include "src/arena_params.h"
#include "src/event_keypress.h"

/*!
 * csci3081 begin
 */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
GraphicsArenaViewer::GraphicsArenaViewer(
  const struct arena_params* const params)
    : csci3081::GraphicsApp(params->x_dim, params->y_dim, "Robot Simulation"),
      arena_(new Arena(params)),
      paused_(false),
      pause_btn_(nullptr),
      last_dt(-1) {
  nanogui::FormHelper *gui = new nanogui::FormHelper(this);
  nanogui::ref<nanogui::Window> window = gui->addWindow(Eigen::Vector2i(10, 10),
                                                       "Simulation Controls");
  gui->addButton("Restart",
    std::bind(&GraphicsArenaViewer::OnRestartBtnPressed, this));
  pause_btn_ = gui->addButton("Pause",
    std::bind(&GraphicsArenaViewer::OnPauseBtnPressed, this));

  last_dt = 0;
  performLayout();
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

// This is the primary driver for state change in the arena.
// It will be called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::UpdateSimulation(double dt) {
  if (!paused_) {
    if ((last_dt + dt) > .05) {
      arena_->AdvanceTime(dt+last_dt);
      last_dt = 0;
    } else {
      last_dt += dt;
    }
  }
}

/*******************************************************************************
 * Handlers for User Keyboard and Mouse Events
 ******************************************************************************/
void GraphicsArenaViewer::OnRestartBtnPressed() {
  arena_->Reset();
  (arena_->status_signs())[0]->set_name("FUN Game");
}

void GraphicsArenaViewer::OnPauseBtnPressed() {
  paused_ = !paused_;
  if (paused_) {
    pause_btn_->setCaption("Play");
  } else {
    pause_btn_->setCaption("Pause");
  }
}

void GraphicsArenaViewer::OnSpecialKeyDown(int key, int scancode,
  int modifiers) {
  EventKeypress e(key);
  arena_->Update(&e);
  if (false) {
    std::cout << "Special Key DOWN key=" << key << " scancode=" << scancode
              << " modifiers=" << modifiers << std::endl;
  }
}

/*******************************************************************************
 * Drawing of Entities in Arena
 ******************************************************************************/
void GraphicsArenaViewer::DrawPlayer(NVGcontext *ctx,
                                     const Player* const player) {
  // translate and rotate all graphics calls that follow so that they are
  // centered, at the position and heading for this player
  nvgSave(ctx);
  nvgTranslate(ctx, player->get_pos().x, player->get_pos().y);
  // disable rotate in player
  // nvgRotate(ctx, player->get_heading_angle());

  // player's circle
  nvgBeginPath(ctx);
  nvgCircle(ctx, 0.0, 0.0, player->get_radius());
  nvgFillColor(ctx, nvgRGBA(static_cast<int>(player->get_color().r() * 255),
                            static_cast<int>(player->get_color().g() * 255),
                            static_cast<int>(player->get_color().b() * 255),
                            255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  // player id text label
  nvgSave(ctx);
  // nvgRotate(ctx, M_PI / 2.0);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, 0.0, 0.0, player->get_name().c_str(), NULL);

  nvgRestore(ctx);
  nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawObstacle(NVGcontext *ctx,
                                       const Obstacle* const obstacle) {
  nvgBeginPath(ctx);
  nvgCircle(ctx, obstacle->get_pos().x, obstacle->get_pos().y,
            obstacle->get_radius());
  nvgFillColor(ctx, nvgRGBA(static_cast<int>(obstacle->get_color().r() * 255),
                            static_cast<int>(obstacle->get_color().g() * 255),
                            static_cast<int>(obstacle->get_color().b() * 255),
                            255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, obstacle->get_pos().x, obstacle->get_pos().y,
          obstacle->get_name().c_str(), NULL);
}

void GraphicsArenaViewer::DrawRobot(NVGcontext *ctx,
                                    const Robot* const robot) {
  // translate and rotate all graphics calls that follow so that they are
  // centered, at the position and heading for this Robot
  nvgSave(ctx);
  nvgTranslate(ctx, robot->get_pos().x, robot->get_pos().y);
  // enable rotate in robot
  nvgRotate(ctx, robot->get_heading_angle()*M_PI/180.0);

  // robot's circle
  nvgBeginPath(ctx);
  nvgCircle(ctx, 0.0, 0.0, robot->get_radius());
  nvgFillColor(ctx, nvgRGBA(static_cast<int>(robot->get_color().r() * 255),
                           static_cast<int>(robot->get_color().g() * 255),
                           static_cast<int>(robot->get_color().b() * 255),
                           255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  // robot id text label
  nvgSave(ctx);
  nvgRotate(ctx, M_PI / 2.0);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, 0.0, 0.0, robot->get_name().c_str(), NULL);

  nvgRestore(ctx);
  nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawRobotSensor(NVGcontext *ctx,
                                           const Robot* const robot,
                                           double sensor_angle,
                                           double sensor_dist) {
  // translate and rotate all graphics calls that follow so that they are
  // centered at the position and heading for this robot
  nvgSave(ctx);
  nvgTranslate(ctx, robot->get_pos().x, robot->get_pos().y);
  nvgRotate(ctx, robot->get_heading_angle()*M_PI/180.0);

  // sensor cone outline
  nvgSave(ctx);
  nvgRotate(ctx, 0.5 * sensor_angle);
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, sensor_dist, 0.0);
  nvgArc(ctx, 0.0, 0.0, sensor_dist, 0.0, -sensor_angle, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 100));
  nvgStroke(ctx);
  nvgRestore(ctx);

  // blue for right sensor cone
  nvgSave(ctx);
  nvgRotate(ctx, 0.5 * sensor_angle);
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, sensor_dist, 0.0);
  nvgArc(ctx, 0.0, 0.0, sensor_dist, 0.0, -0.5 * sensor_angle, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgFillColor(ctx, nvgRGBA(100, 100, 255, 150));
  nvgFill(ctx);
  nvgRestore(ctx);

  // yellow for left sensor cone
  nvgSave(ctx);
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, sensor_dist, 0.0);
  nvgArc(ctx, 0.0, 0.0, sensor_dist, 0.0, -0.5 * sensor_angle, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgFillColor(ctx, nvgRGBA(255, 255, 100, 150));
  nvgFill(ctx);
  nvgRestore(ctx);

  nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawStatusSign(NVGcontext *ctx,
                                       const StatusSign* const status_sign) {
  nvgBeginPath(ctx);
  nvgCircle(ctx, status_sign->get_pos().x, status_sign->get_pos().y,
            status_sign->get_radius());
  nvgFillColor(ctx, nvgRGBA(
    static_cast<int>(status_sign->get_color().r() * 255),
    static_cast<int>(status_sign->get_color().g() * 255),
    static_cast<int>(status_sign->get_color().b() * 255), 255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, status_sign->get_pos().x, status_sign->get_pos().y,
          status_sign->get_name().c_str(), NULL);
}

void GraphicsArenaViewer::DrawHomeBase(NVGcontext *ctx,
                               const HomeBase* const home) {
  nvgBeginPath(ctx);
  nvgCircle(ctx, home->get_pos().x, home->get_pos().y, home->get_radius());
  nvgFillColor(ctx, nvgRGBA(static_cast<int>(home->get_color().r() * 255),
                            static_cast<int>(home->get_color().g() * 255),
                            static_cast<int>(home->get_color().b() * 255),
                            255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, home->get_pos().x, home->get_pos().y,
          home->get_name().c_str(), NULL);
}

void GraphicsArenaViewer::DrawUsingNanoVG(NVGcontext *ctx) {
  // initialize text rendering settings
  nvgFontSize(ctx, 18.0f);
  nvgFontFace(ctx, "sans-bold");
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

  std::vector<Obstacle*> obstacles = arena_->obstacles();
  for (size_t i = 0; i < obstacles.size(); i++) {
    DrawObstacle(ctx, obstacles[i]);
  } /* for(i..) */

  std::vector<StatusSign*> status_signs = arena_->status_signs();
  for (size_t i = 0; i < status_signs.size(); i++) {
    DrawStatusSign(ctx, status_signs[i]);
  } /* for(i..) */

  std::vector<Robot*> robots = arena_->robots();
  for (size_t i = 0; i < robots.size(); i++) {
    DrawRobot(ctx, robots[i]);
    DrawRobotSensor(ctx, robots[i], DEFAULT_FOV_ANGLE*M_PI/180.0,
      DEFAULT_RANGE);
  } /* for(i..) */

  DrawPlayer(ctx, arena_->player());
  DrawHomeBase(ctx, arena_->home_base());
}

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);
