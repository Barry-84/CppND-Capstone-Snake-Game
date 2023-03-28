#include <algorithm>
#include <iostream>
#include "pathplanner.h"

PathPlanner::PathPlanner(GridModel &model, Snake &snake, int start_x, int start_y, int end_x, int end_y) 
           : m_model(model), m_snake(snake), start_x(start_x), start_y(start_y), end_x(end_x), end_y(end_y) {

}

float PathPlanner::CalculateHValue(GridModel::Node* const node) {
    return node->distance(*end_node);
}

void PathPlanner::AddNeighbours(GridModel::Node *current_node) {
  current_node->FindNeighbours();

  for (GridModel::Node* node : current_node->neighbours) {
    if (!node->visited && !m_snake.SnakeCell(node->x, node->y)) {
      node->parent = current_node;
      node->h_value = CalculateHValue(node);
      node->g_value = current_node->g_value + current_node->distance(*node);
      node->visited = true;
      open_list.push_back(node);
    }
  }

}

bool sortBySumDescending(GridModel::Node const *node1, GridModel::Node const *node2) {
  return (node1->h_value + node1->g_value) > (node2->h_value + node2->g_value);
}

GridModel::Node* PathPlanner::NextNode() {
  // could also use lambda expression instead of auxiliary (predicate?) function sortBySumDescending.
  std::sort(open_list.begin(), open_list.end(), sortBySumDescending);
  GridModel::Node* lowestSumNode = open_list.back();
  open_list.pop_back();
  return lowestSumNode;
}

void PathPlanner::ConstructFinalPath(GridModel::Node *current_node) {
  // Create path_found vector
  distance = 0.0f;
  
  while (current_node != start_node) {
    distance += current_node->distance(*current_node->parent);
    path.push_back(current_node);
    current_node = current_node->parent;
  }
  // Don't push the start node to the path. The snake's head is already there.
  reverse(path.begin(), path.end());
}

std::vector<GridModel::Node*> PathPlanner::AStarSearch() {
  GridModel::Node *current_node = nullptr;

  start_node = m_model.GetNodeAtPosition(start_x, start_y);
  start_node->x = start_x;
  start_node->y = start_y;

  end_node = m_model.GetNodeAtPosition(end_x, end_y);
  end_node->x = end_x;
  end_node->y = end_y;

  start_node->visited = true;
  open_list.push_back(start_node);
  AddNeighbours(start_node);

  while (!open_list.empty()) {
    // sort the open list and return the next node (node with lowest f-value)
    current_node = NextNode();
    // check whether we've reached the end_node.
    // Alternatively: current_node->x == end_node->x && current_node->y == end_node->y
    if (current_node->distance(*end_node) == 0) {
      ConstructFinalPath(current_node);
      break;
    }
    AddNeighbours(current_node);
  }
   
  return path;
}