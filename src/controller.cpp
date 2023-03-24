#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

Controller::Controller(const std::size_t grid_width, const std::size_t grid_height) :
    grid_width(grid_width), grid_height(grid_height) {

}

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.GetDirection() != opposite || snake.GetSize() == 1) snake.SetDirection(input);
  return;
}
//void Controller::PlanPath(int start_x, int start_y, int end_x, int end_y) {
std::vector<GridModel::Node*> Controller::PlanPath(int start_x, int start_y, int end_x, int end_y) {
  //pathplanner = std::make_unique<PathPlanner>(grid_width, grid_height); 
  //pathplanner.reset(new PathPlanner(grid_width, grid_height));
  GridModel model(grid_width, grid_height);
  //pathplanner.reset(new PathPlanner());
  PathPlanner pathplanner(model, start_x, start_y, end_x, end_y);
  //std::vector<Node*> path = pathplanner->AStarSearch(start_x, start_y, end_x, end_y);
  //pathplanner->AStarSearch(start_x, start_y, end_x, end_y);
  //pathplanner.AStarSearch();
  path = pathplanner.AStarSearch();
}

void Controller::AutoGuideSnake(Snake &snake) {
  auto nextPosition = path.front();
  int diffX = nextPosition->x - static_cast<int>(snake.GetHeadX());
  int diffY = nextPosition->y - static_cast<int>(snake.GetHeadY());
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