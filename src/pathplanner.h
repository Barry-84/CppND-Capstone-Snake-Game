#ifndef PATHPLANNER_H
#define PATHPLANNER_H

#include "gridmodel.h"
#include "snake.h"

class PathPlanner {
  public:
    PathPlanner(GridModel &model, Snake &snake, int start_x, int start_y, int end_x, int end_y);
    int GetDistance() const { return distance; }
    std::vector<GridModel::Node*> AStarSearch();

    void AddNeighbours(GridModel::Node* current_node);
    float CalculateHValue(GridModel::Node * const node);
    void ConstructFinalPath(GridModel::Node*);
    GridModel::Node* NextNode();

  private:
    std::vector<GridModel::Node*> open_list;
    std::vector<GridModel::Node*> path;

    GridModel::Node* start_node;
    GridModel::Node* end_node;

    float distance = 0.0f;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    GridModel &m_model;
    Snake &m_snake;
};

#endif