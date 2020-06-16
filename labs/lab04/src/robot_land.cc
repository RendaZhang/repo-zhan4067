/**
 * @file robot_land.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_land.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

//Two robots
int RobotLand::get_num_robots(void) { return 2; }

//My function for changing the robot color
int RobotLand::get_robot_color(int id) {
	if (id == 0) {
		return R.get_robot_color();
	} else if (id == 1) {
		return R2.get_robot_color();
	} else {
		return 0;
	}	
}
//Second one
void RobotLand::set_robot_color(int id, int newcolor) {
	if (id == 0) {
		return R.set_robot_color(newcolor);
	} else if (id == 1) {
		return R2.set_robot_color(newcolor);
	} else {
		return;
	}	
}


bool RobotLand::get_robot_pos(int id, double *x_pos, double *y_pos) {
	if (id == 0) {
		return R.get_robot_pos(x_pos, y_pos, sim_time_);
	} else if (id == 1) {
		//make this robot slower
		double t = 0.75 * sim_time_;
		return R2.get_robot_pos(x_pos, y_pos, t);
	} else {
		return 0.0;
	} 
}

bool RobotLand::get_robot_vel(int id, double *x_vel, double *y_vel) {
	if (id == 0) {
		return R.get_robot_vel(x_vel, y_vel, sim_time_);
	} else if (id == 1) {
		//make this robot slower
		double t = 0.75 * sim_time_;
		return R2.get_robot_vel(x_vel, y_vel, t);
	} else {
		return 0.0;
	} 
}

double RobotLand::get_robot_radius(int id) {
	if (id == 0) {
		return R.get_robot_radius();
	} else if (id == 1) {
		return R2.get_robot_radius();
	} else {
		return 0.0;
	}  
}

double RobotLand::get_robot_sensor_angle(int id) { 
	if (id == 0) {
		return R.get_robot_sensor_angle();
	} else if (id == 1) {
		return R2.get_robot_sensor_angle();
	} else {
		return 0.0;
	} 
}

double RobotLand::get_robot_sensor_distance(int id) {
	if (id == 0) {
		return R.get_robot_sensor_distance();
	} else if (id == 1) {
		return R2.get_robot_sensor_distance();
	} else {
		return 0.0;
	} 
}

int RobotLand::get_num_obstacles() {
	return 1; 
}

bool RobotLand::get_obstacle_pos(int id, double *x_pos, double *y_pos) {
	if (id == 0) {
		*x_pos = 200;
		*y_pos = 300;
		return true;
	}
	return false;
}

double RobotLand::get_obstacle_radius(int id) {
	return 75; 
}
