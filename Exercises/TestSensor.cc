#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Robot;
class EventDistress;

/*!
 * @brief The [x,y] position with respect to the graphics arena
 *
 * \todo Implement operator overloading for '-' and '<<'
 */
struct Position {
  Position( double in_x=0, double in_y=0) : x(in_x), y(in_y) {}
  double x;
  double y;
  // Operator Overload '-'
  // Operator Overload '<<'
};

/**
 * @brief Activates when a distress call is within its range.
 *
 * SensorDistress is a part of a robot. Implented with the Observer Pattern
 * the Arena (i.e. the subject) will call \ref Accept to alert the sensor
 * of all distress calls in the arena. The SensorDistress has to determine
 * whether or not this call will activate its sensor (which is part of a Robot).
 *
 * Either the Robot or parts of the Robot (e.g. RobotMotionHandler) will use
 * the sensor output to effect behavior.
 *
 */
class SensorDistress {
public:
  SensorDistress(const Robot * robot, double range):
    robot_(robot), range_(range) {}
  void Accept(const EventDistress & ed);
  int Output();
private:
  double range_;
  const Robot * robot_;
  std::vector<int> entity_ids_;
};

// As an observer, the sensor gets alerted of the "subject" arena
void SensorDistress::Accept(const EventDistress & ed ) {
  // Is this distress call from the robot that I am part of?
  // Is this a distress call I can hear?
}

int Output() {
  return 1;
  // Is this activated or not?
}

/*!
 * @brief A simple robot class that has an id and position
 *
 */
class Robot {
public:
  Robot(Position p, int id) : pos_(p), id_(id),
    sensor_distress_(new SensorDistress(this,50)) {}
  Position get_pos() { return pos_; }
  void set_pos(Position p) { pos_ = p; }
  int get_id() { return id_; }
  void set_id(int i) { id_ = i; }
private:
  SensorDistress * sensor_distress_;
  Position pos_;
  int id_;
};

// Communication of the event that a distress call was emitted in the arena
class EventDistress {
public:
  EventDistress(Position p, int id) : pos_(p), entity_id_(id) {}
  Position get_pos() { return pos_; }
  int get_entity_id() { return entity_id_; }
private:
  Position pos_;
  int entity_id_;
};

int main() {
  Robot robbie(Position(100,100),1);
}
