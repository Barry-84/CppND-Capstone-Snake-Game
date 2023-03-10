// #ifndef NODE_H
// #define NODE_H

// #include <vector>
// #include <limits>
// #include <cmath>
// #include <array>
  
//   class Node {
//     public:
//       Node* parent = nullptr;
//       int h_value = std::numeric_limits<int>::max();
//       int g_value = 0;
//       bool visited = false;
//       std::vector<Node*> neighbours;
//       int x;
//       int y;

//       void FindNeighbours();
//       //float distance(Node other) const {
//       //  return std::sqrt(std::pow((x - other.x), 2) + std::pow((y - other.y), 2));
//       //}
//       float distance(Node other) const;

//       Node(){}
//       //Node(int idx, RouteModel* search_model, Model::Node node) : (Model::Node(node), parent_model(search_model), index(idx) {}

//     private:
//       //std::array<std::array<int, 4>, 2> neighboursDeltas = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//       int neighboursDeltas[4][2]{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//       //int index;
//       //Node* FindNeighbour(std::vector<int< node_indices);
//       //RouteModel* parent_model = nullptr;
//   };

// #endif