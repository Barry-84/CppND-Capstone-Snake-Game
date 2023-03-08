#ifndef PATHPLANNER_H
#define PATHPLANNER_H

#include "gridmodel.h"
//#include "node.h"
//#include "SDL.h"

class PathPlanner {
  public:
    //PathPlanner(const std::size_t grid_width, const std::size_t grid_height);
    PathPlanner(GridModel &model, int start_x, int start_y, int end_x, int end_y);
    int GetDistance() const { return distance; }
    //void AStarSearch(int start_x, int start_y, int end_x, int end_y);
    void AStarSearch();
    //std::vector<Node*> AStarSearch(int start_x, int start_y, int end_x, int end_y);

    void AddNeighbours(GridModel::Node* current_node);
    float CalculateHValue(GridModel::Node * const node);
    // std::vector<Node> ConstructFinalPath(Node*);
    void ConstructFinalPath(GridModel::Node*);
    GridModel::Node* NextNode();

  private:
    std::vector<GridModel::Node*> open_list;
    std::vector<GridModel::Node*> path;
    //std::vector<std::vector<Node*>> grid;

    GridModel::Node* start_node;
    GridModel::Node* end_node;

    float distance = 0.0f;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    GridModel &m_model;
    
};

#endif