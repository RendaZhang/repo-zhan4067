A list of the files and methods where you are making your changes.
------------------------------------------------------------------------

file <strong>arena.h</strong> at line <strong>#177-#179</strong>: 
``double InRange(...)`` <br>

file <strong>arena.h</strong> at line <strong>#198</strong>: 
``double Positive(...)`` <br>

file <strong>arena.cc</strong> at line <strong>#280, 459</strong>:
``InRange(...)`` <br>

file <strong>arena.cc</strong> at line <strong>#495, 496, 498, 499, 500, 
501, 533</strong>:
``Positive(...)`` <br>

<br>


The original variable and/or method names that you are changing 
and what their new names are called after the refactor.
------------------------------------------------------------------------

Old method name: ``double InRange(...)``, 
new method name: ``double ProximityInRange(...)``; <br>

Old method name: ``double Positive(...)``, 
new method name: ``double PositiveAngle(...)``; <br>

<br>


A brief explanation of how new names are better than old ones.
------------------------------------------------------------------------

``double ProximityInRange(...)`` is better than ``double InRange(...)``, 
because InRange is very confusing to people and not knowing what is to be
checked in range. But ProximityInRange provide the meaning about it is 
checking for the proximity sensor. <br>

``double PositiveAngle(...)`` is better than ``double Positive(...)``, 
because Positive is very confusing to people and not knowing what is to be
positive. But PositiveAngle provide the meaning about it is making the 
angle to be positive angle.

<br>
