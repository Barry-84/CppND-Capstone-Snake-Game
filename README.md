# CPPND: Capstone Snake Game with A* search
This is an implementation of the classic snake game, in which the user is given the option to control the snake manually or to allow the snake to be controlled automatically. Automatic snake control uses the A* search algorithm to calculate the snake's path to the food. Eating food causes the snakes size to grow by one and its speed to increase. In manual mode, the snake's size and speed can be reduced by eating magic food, making it easier to progress further in the game.
## Project structure
### `main.cpp`
Writes to the console and gets user input regarding choice of manual or automatic control. Creates a renderer, controller and game object and calls the function Run() on the game object.

### `game.cpp` and `game.h`
Depending on which mode was chosen by the user, this class calls functions in the controller class. If automatic control is desired, the PlanPath() function is called and a path to the food is generated. Then the AutoControlSnake function is called to guide the snake along this path. Otherwise, if manual control has been selected, the HandleInput() method is called and the user's keyboard inputs are used to control the snake.
Next the Update() function is called to move the snake and place food and magic food. Finally the Render() function is called on the renderer object. This function is overloaded.

### `controller.cpp` and `controller.h`
In the PlanPath() function of the controller class a grid of nodes and a pathplanner object is created. The AStarSearch() method is called on the pathplanner object. A path from the snake's head to the food is calculated. The AutoGuideSnake() function uses the ChangeDirection() method to change the snakes direction in the same it is done in the case of manual control.

### `food.cpp` and `food.h`
The food class contains getter and setter functions for food coordinates. It also contains a function which for a given coordinate returns true if it contains food, false otherwise.

### `gridmodel.cpp` and `gridmodel.h`
The constructor fills a vector of vectors of specified dimensions, with Nodes. The FindNeighbours() function finds the North, South, East and West neighbours of the given node. Since the snake is only permitted to move left, right, up and down, the manhattan distance is used in the function distance().

### `pathplanner.cpp` and `pathplanner.h`
### `renderer.cpp` and `renderer.h`
### `snake.cpp` and `snake.h`

## Rubric Points
The following rubric points are handled in this project.
### Loops, Functions, I/O
- The project demonstrates an understanding of C++ functions and control structures.
- The project accepts input from a user as part of the necessary operation of the program.

### Object Oriented Programming
- The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
- All class data members are explicitly specified as public, protected, or private.
- All class members that are set to argument values are initialized through member initialization lists.
- One function is overloaded with different signatures for the same function name.

### Memory Management
- At least two variables are defined as references, or two functions use pass-by-reference in the project code.
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
