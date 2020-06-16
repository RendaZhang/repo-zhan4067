/**
 * Renda Zhang
 * ID: 5109455
 * zhan4067@umn.edu
 */

#include "src/robot.h"

bool Robot::get_robot_pos(double *x_pos, double *y_pos, double sim_time_) {
    *x_pos = circle_x(sim_time_);
    *y_pos = circle_y(sim_time_);
    return true;
}

bool Robot::get_robot_vel(double *x_vel, double *y_vel, double sim_time_) {
	double xnow, ynow, xprev, yprev;
	double delta = 0.1;
	xnow = circle_x(sim_time_);
	ynow = circle_y(sim_time_);
	xprev = circle_x(sim_time_ - delta);
	yprev = circle_y(sim_time_ - delta);
	*x_vel = xnow - xprev;
	*y_vel = ynow - yprev;
	return true;
}


double Robot::get_robot_radius() { 
	return 50; 
}


double Robot::get_robot_sensor_angle() { 
	return 2.0; 
}


double Robot::get_robot_sensor_distance() {
	return 3.0 * get_robot_radius();
}

// My function for changing the robot color
int Robot::get_robot_color() {
	return color;
}

void Robot::set_robot_color(int newcolor) {
	color = newcolor;
}
