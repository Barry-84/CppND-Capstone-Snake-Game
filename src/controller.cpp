#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

Controller::Controller(const std::size_t grid_width, const std::size_t grid_height)
          : grid_width(grid_width), grid_height(grid_height) {

}

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.GetDirection() != opposite || snake.GetSize() == 1) snake.SetDirection(input);
  return;
}

std::vector<GridModel::Node*> Controller::PlanPath(Snake &snake, int start_x, int start_y, int end_x, int end_y) {
  GridModel model(grid_width, grid_height);
  PathPlanner pathplanner(model, snake, start_x, start_y, end_x, end_y);
  return path = pathplanner.AStarSearch();
}

void Controller::AutoGuideSnake(Snake &snake) {
  
  // path is empty right before snake dies.
  if (path.empty()) {
    return;
  }

  auto nextPosition = path.front();
  int diffX = nextPosition->x - static_cast<int>(snake.GetHeadX());
  int diffY = nextPosition->y - static_cast<int>(snake.GetHeadY());

  if (diffX == 0) {
    switch (diffY) {
      case -1:
        ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
        break;
      case +1:
        ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
        break;
    }
  } else { // diffY == 0
    switch (diffX) {
      case -1:
        ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
        break;
      case +1:
        ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
        break;
    }
  }
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}