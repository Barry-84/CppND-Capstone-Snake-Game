#include <algorithm>
#include <iostream>
#include "gridmodel.h"

GridModel::GridModel(const std::size_t grid_width, const std::size_t grid_height)
         : grid_width(grid_width), grid_height(grid_height){

  for (size_t i = 0; i < grid_height; i++) {
    int j = 0;
    grid.emplace_back();
    while (j < grid_width) {
      grid.back().push_back(new GridModel::Node(this));
      j++;   
    }
  }

}

// Finds the 4 neighbours north, south, east and west of the current node.
// Note the snake cannot moved diagonally as it also cannot do so when
// controlled manually. 
void GridModel::Node::FindNeighbours() {

  for (auto& delta : neighboursDeltas) {
    int head_x = (this->x + delta[0] + parent_model->grid_width) % parent_model->grid_width;
    int head_y = (this->y + delta[1] + parent_model->grid_height) % parent_model->grid_height;

    GridModel::Node* neighbour = parent_model->grid[head_x][head_y];
    neighbour->x = head_x;
    neighbour->y = head_y;
    neighbours.push_back(neighbour);

    // if (this->x + delta[0] >= 0 && this->x + delta[0] < 32 && this->y + delta[1] >= 0 && this->y + delta[1] < 32) {
    //   GridModel::Node* neighbour = parent_model->grid[this->x + delta[0]][this->y + delta[1]];
    //   neighbour->x = this->x + delta[0];
    //   neighbour->y = this->y + delta[1];
    //   neighbours.push_back(neighbour);
    // }
  }

}

GridModel::Node* GridModel::GetNodeAtPosition(int x, int y) {
  return grid[x][y];
}

float GridModel::Node::distance(Node other) const {
  // Manhattan distance
  return std::abs(x - other.x) + std::abs(y - other.y);
}