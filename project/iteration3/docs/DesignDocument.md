Design Document
---------------
In Arena, For every timestep loop, UpdatePlayer(), UpdateHomeBase(), and
UpdateRobots() methods are called. Inside these methods, the sensors of these
mobile entities are updated. Different types of events are checked and the
event will be set and pass to the sensor by calling the Update(event) method
of sensor. 
<br>
list of sensor_touchs_, sensor_proximities_, sensor_entity_types, and
sensor_distresses are created in Arena. Every Robot has the four sensors.
Player and HomeBase have only sensor_touchs_ to detect collision event.
Observer Pattern is used to pass different events from arena to sensors
directly and the motion of robot will change accordingly in motion handler.
Sensors are used in the motion handler, arena, and mobile entities. Mobile
entities act as the Observer and sensors act as the Subject in Observer
Pattern. As event happend, the related sensor in mobile entity will be change
based on the event.
<br>
The Robot become SuperBot if it collide with HomeBase. This is implemented
using strategy pattern. A pointer a abstract type MotionHandler class as the
motion_handler_ variable, the choice of being Robot or SuperBot is done by
calling the function set_motion_handler(), this allow Robot behave
differently. Also the change of color by calling set_color() is also used to
make Robot become SuperBot.
<br>
The EntityType and EventCollsion and EventProiximity and EventDistressCall 
are used inside Motion Handler.
The change between robot and superbot is detected and done in Arena. The 
collision between robot and player is also detected in Arena.
<br>
The game is win if all the remaining Robots which are not SuperBot is freezed,
The game is lost if all Robot become SuperBot.
<br>
