/**
 * Renda Zhang
 * ID: 5109455
 * zhan4067@umn.edu
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <cmath>
#include <iostream>

class Robot {	
private:
	double circle_x(double t) { return 512 + 200.0 * cos(t); }
	double circle_y(double t) { return 350 + 200.0 * sin(t); }
	//adding for changing color
	int color;
	
public:
	Robot(void) {
		//default value to the first argument in avgRGBA
		color = 200;
	}

	bool get_robot_pos(double *x_pos, double *y_pos, double sim_time_);
	
	bool get_robot_vel(double *x_vel, double *y_vel, double sim_time_);
	
	double get_robot_radius();
	
	double get_robot_sensor_angle();
	
	double get_robot_sensor_distance();
	
	//function header for changing color
	int get_robot_color();
	void set_robot_color(int newcolor);
};

#endif	// SRC_ROBOT_H_
