# CPPND: Capstone Snake Game with A* search
This is an implementation of the classic snake game, in which the user is given the option to control the snake manually or to allow the snake to be controlled automatically. Automatic snake control uses the A* search algorithm to calculate the snake's path to the food. Eating food causes the snakes size to grow by one and its speed to increase. In manual mode, the snake's size and speed can be reduced by eating magic food, making it easier to progress further in the game.
## Project structure
### `main.cpp`
Writes to the console and gets user input regarding choice of manual or automatic control. Creates a renderer, controller and game object and calls the function Run() on the game object.

### `game.cpp` and `game.h`
### `controller.cpp` and `controller.h`
### `food.cpp` and `food.h`
### `gridmodel.cpp` and `gridmodel.h`
### `pathplanner.cpp` and `pathplanner.h`
### `renderer.cpp` and `renderer.h`
### `snake.cpp` and `snake.h`

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
