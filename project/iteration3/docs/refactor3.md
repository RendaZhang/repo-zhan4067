A list of the files and the method(s) you are changing.
------------------------------------------------------------------------

<strong>arena.h</strong>, <strong>arena.cc</strong>: 
``UpdateRobots(void)`` <br>

<br>


The location of the changes. 
Be sure you explain briefly what you are doing at each location.
------------------------------------------------------------------------

file <strong>arena.h</strong> at line <strong>#184-185</strong>: 
Add the extracted method ``UpdateRobotCollisionEvent(Robot, EventCollision)``;
<br>

file <strong>arena.cc</strong> at line <strong>#293-327</strong>: 
Replace these lines with one line using the new method 
``UpdateRobotCollisionEvent(robot, &ec);``;
<br>

file <strong>arena.cc</strong> at line <strong>#356</strong>: 
Add the definition of the new method here.
<br>

<br>

A brief explanation of how this improves your code
------------------------------------------------------------------------

Because the method ``UpdateRobots(void)`` in Arena Class is super long.
And it is difficult to distinguish and find where is the part to update
the collision event for Robots. After we extract method 
``UpdateRobotCollisionEvent(Robot, EventCollision);`` from it, we can easily
located the collision part inside UpdateRobots method. Also in the future
we can make use of such function again by calling it directly.

<br>

