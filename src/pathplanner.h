#ifndef PATHPLANNER_H
#define PATHPLANNER_H

#include "node.h"
//#include "SDL.h"

class PathPlanner {
  public:
    PathPlanner(const std::size_t grid_width, const std::size_t grid_height);
    int GetDistance() const { return distance; }
    //void AStarSearch(int start_x, int start_y, int end_x, int end_y);
    std::vector<Node*> AStarSearch(int start_x, int start_y, int end_x, int end_y);

    void AddNeighbours(Node* current_node);
    float CalculateHValue(Node const *node);
    // std::vector<Node> ConstructFinalPath(Node*);
    void ConstructFinalPath(Node*);
    Node* NextNode();

  private:
    std::vector<Node*> open_list;
    std::vector<Node*> path;
    std::vector<std::vector<Node*>> grid;

    Node* start_node;
    Node* end_node;

    float distance = 0.0f;
    
};

#endif