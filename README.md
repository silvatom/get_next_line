# GET_NEXT_LINE

This project aims code a function that returns a line, read from a file descriptor.

### Mandatory Part
Through each call, the function will return a line.
Using it in a loop, the function will return each line read in the file descriptor.
It should return NULL if there is no line to read or an error occur.

### Bonus Part
Using only ONE static variable, the function is able to ouputs a line from differente file descriptors, without losing the reading thread on each of the file descriptors.

## FILES

#### Mandatory
* get_next_line.h - header file
* get_next_line.c - the main functions
* get_next_line_utils.c - additional functions

#### Bonus
* get_next_line_bonus.h - bonus header file
* get_next_line.bonus.c - the main bonus functions
* get_next_line_utils.bonus.c - additional functions
