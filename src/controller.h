#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include "snake.h"
#include "pathplanner.h"

class Controller {
 public:
  Controller(const std::size_t grid_width, const std::size_t grid_height);
  void HandleInput(bool &running, Snake &snake) const;
  //void PlanPath(int start_x, int start_y, int end_x, int end_y);
  std::vector<GridModel::Node*> PlanPath(Snake &snake, int start_x, int start_y, int end_x, int end_y);
  void AutoGuideSnake(Snake &snake);
 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
  std::unique_ptr<PathPlanner> pathplanner;
  std::vector<GridModel::Node*> path;
  int grid_width;
  int grid_height;
};

#endif