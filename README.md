# GET_NEXT_LINE

This project aims code a function that returns a line, reading from a file descriptor.

* [**Mandatory Part**](#Mandatory-Part) - brief description on how the function should work.
* [**Bonus Part**](#Bonus-Part) - brief description on bonus functionality proposed by the project.
* [**Files**](#Files) - list of files related to the project.
* [**Use Cases**](#Use-cases) - code snippets with example on how to use it.

## Mandatory Part
Through each call, the function will return a line.
Using it in a loop, the function will return each line read in the file descriptor.
It should return NULL if there is no line to read or an error occur.

## Bonus Part
Using only ONE static variable, the function is able to ouputs a line from differente file descriptors, without losing the reading thread on each of the file descriptors.

## Files

#### Mandatory
* [**get_next_line.h**](https://github.com/silvatom/get_next_line/blob/master/get_next_line.h) - header file
* [**get_next_line.c**](https://github.com/silvatom/get_next_line/blob/master/get_next_line.c) - the main functions
* [**get_next_line_utils.c**](https://github.com/silvatom/get_next_line/blob/master/get_next_line_utils.c) - additional functions

#### Bonus
* [**get_next_line_bonus.h**](https://github.com/silvatom/get_next_line/blob/master/get_next_line_bonus.h) - bonus header file
* [**get_next_line.bonus.c**](https://github.com/silvatom/get_next_line/blob/master/get_next_line_bonus.c) - the main bonus functions
* [**get_next_line_utils.bonus.c**](https://github.com/silvatom/get_next_line/blob/master/get_next_line_utils_bonus.c) - additional functions

## Use cases
### Getting input from *stdin* (like *scanf()*)
```c
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char	*input;

	input = get_next_line(0);
	printf("%s", input);
	free(input);
}
```

### Getting input from a *file* (named "file.txt")
```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*input;
	int		file_fd;

	file_fd = open("file.txt", O_RDONLY);
	input = get_next_line(file_fd);
	printf("%s", input);
	free(input);
}
```

### Bonus example: getting input from a *file* (named "file.txt") and from *stdin*
```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*input;
	int		file_fd;

	file_fd = open("file.txt", O_RDONLY);
	input = get_next_line(file_fd);
	printf("%s", input);
	free(input);

	input = get_next_line(0);
	printf("%s", input);
	free(input);
}
```

### Compilation for the examples
Copy and paste the snippets in a ***<main.c>*** file and compile with one of the lines below:
* Mandatory:
```
gcc main.c get_next_line.c get_next_line_utils.c
```
* Bonus:
```
gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```