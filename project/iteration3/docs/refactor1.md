A list of the files and methods added and/or changed.
------------------------------------------------------------------------

home_base.h : add method ``int RandNum(void)`` <br>

<br>


The code, filename, and line number with the temporary variable.
------------------------------------------------------------------------

file <strong>home_base.cc</strong> at line <strong>#41</strong> : <br>


```
int rand_n = rand_r(&seed_) % 10 + 1;
```

<br>


The name of the new method you created and where it is located. <br>
Identify where any changes were made to call the new function.
------------------------------------------------------------------------

method ``int RandNum(void)`` located in file <strong>home_base.cc</strong>
at line <strong>#114-#116</strong>; <br>

in file <strong>home_base.cc</strong>, line <strong>#41</strong> was remove
and all ``rand_n`` was replaced with ``RandNum()``; <br>

<br>


A brief explanation of what behavior this is replacing.
------------------------------------------------------------------------

A random number between 1 and 10 is generated based on the private variable
``seed_`` in HomeBase class.  
