/**
 * @file color.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <simple_graphics/graphics_app.h>
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
struct Color : public nanogui::Color {
 public:
  /**
  * @brief Constructor without argument
  */
  Color(void) : nanogui::Color(), r(0), g(0), b(0), a(255) { }

  /**
  * @brief Constructor with argument r g b a
  */
  Color(int in_r, int in_g, int in_b, int in_a)
    : nanogui::Color(in_r, in_g, in_b, in_a),
    r(in_r), g(in_g), b(in_b), a(in_a) { }

  /**
  * @brief red
  */
  int r;

  /**
  * @brief green
  */
  int g;

  /**
  * @brief blue
  */
  int b;

  /**
  * @brief a
  */
  int a;
};

/*!
 * csci3081 end
 */
NAMESPACE_END(csci3081);

#endif /* SRC_COLOR_H_ */
