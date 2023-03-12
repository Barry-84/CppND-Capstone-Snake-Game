
#ifndef GRIDMODEL_H
#define GRIDMODEL_H

#include <vector>
#include <limits>
#include <cmath>
#include <array>

class GridModel {

  public:

  class Node {
    public:
      GridModel::Node* parent = nullptr;
      int h_value = std::numeric_limits<int>::max();
      int g_value = 0;
      bool visited = false;
      std::vector<GridModel::Node*> neighbours;
      int x;
      int y;

      void FindNeighbours();
      //float distance(Node other) const {
      //  return std::sqrt(std::pow((x - other.x), 2) + std::pow((y - other.y), 2));
      //}
      float distance(GridModel::Node other) const;

      Node(){}
      Node(GridModel* search_model) : parent_model(search_model) {}

    private:
      //std::array<std::array<int, 4>, 2> neighboursDeltas = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
      int neighboursDeltas[4][2]{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
      GridModel* parent_model = nullptr;

      //int index;
      //Node* FindNeighbour(std::vector<int< node_indices);
      //RouteModel* parent_model = nullptr;
  };

    GridModel(const std::size_t grid_width, const std::size_t grid_height);
    GridModel::Node* GetNodeAtPosition(int x, int y);
    std::vector<Node*> path;

  private:
    std::vector<std::vector<GridModel::Node*>> grid;
    //std::vector<GridModel::Node*> grid;
};

#endif
